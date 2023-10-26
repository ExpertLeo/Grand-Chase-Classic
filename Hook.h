#include "stdafx.h"

#pragma region Hook

typedef HRESULT(WINAPI* tReset)(LPDIRECT3DDEVICE9 pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
tReset oReset;

typedef HRESULT(WINAPI *tPresent)(LPDIRECT3DDEVICE9 pDevice, const RECT *a, const RECT *b, HWND c, const RGNDATA *d);
tPresent oPresent;

typedef HRESULT(WINAPI *tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene;

typedef HRESULT(WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE, int, UINT, UINT, UINT, UINT);
tDrawIndexedPrimitive oDrawIndexedPrimitive;

VOID CreateDevice(DWORD *dwVTable)
{
	LPDIRECT3D9 pD3d9;
	LPDIRECT3DDEVICE9 pD3DDevice;
	pD3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (pD3d9 == NULL)
		return;
	D3DPRESENT_PARAMETERS pPresentParms;
	ZeroMemory(&pPresentParms, sizeof(pPresentParms));
	pPresentParms.Windowed = TRUE;
	pPresentParms.BackBufferFormat = D3DFMT_UNKNOWN;
	pPresentParms.SwapEffect = D3DSWAPEFFECT_DISCARD;
	if (FAILED(pD3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GetDesktopWindow(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pPresentParms, &pD3DDevice)))
		return;
	DWORD *dwTable = (DWORD *)pD3DDevice;
	dwTable = (DWORD *)dwTable[0];
	dwVTable[0] = dwTable[16]; //Reset
	dwVTable[1] = dwTable[17]; //Present
	dwVTable[2] = dwTable[42]; //EndScene
	dwVTable[3] = dwTable[82]; //DrawIndexedPrimitive
}

VOID *DetourCreate(BYTE *src, const BYTE *dst, const int len)
{
	int Pointer[] = { 0xE9, 0x90 };

	BYTE *jmp = (BYTE *)malloc(len + 5);
	DWORD dwback;
	VirtualProtect(src, len, PAGE_READWRITE, &dwback);
	memcpy(jmp, src, len);
	jmp += len;
	jmp[0] = Pointer[0];
	*(DWORD *)(jmp + 1) = (DWORD)(src + len - jmp) - 5;
	src[0] = Pointer[0];
	*(DWORD *)(src + 1) = (DWORD)(dst - src) - 5;
	for (INT i = 5; i < len; i++) src[i] = Pointer[1];
	VirtualProtect(src, len, dwback, &dwback);

	return(jmp - len);
}

#pragma endregion