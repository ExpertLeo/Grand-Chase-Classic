#include "include.h"

#pragma region Functions
BOOL bCompare(const BYTE* pData, const BYTE* bMask, const char* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return false;
	return (*szMask) == NULL;
}

DWORD FindPattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
		if (bCompare((BYTE*)(dwAddress + i), bMask, szMask))
			return (DWORD)(dwAddress + i);
	return 0;
}

DWORD DoBypass(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
		if (bCompare((BYTE*)(dwAddress + i), bMask, szMask))
		{
			DWORD Bol = 0;

			printf("Bypass: %x\n", (dwAddress + i));
			VirtualProtect((LPVOID)(DWORD)(dwAddress + i), 0x60, PAGE_EXECUTE_READWRITE, &Bol);
			*(byte*)(dwAddress + i) = 0xEB;
			VirtualProtect((LPVOID)(DWORD)(dwAddress + i), 0x60, Bol, &Bol);
		}

	return 0;
}

DWORD DoHook(PBYTE Function, DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask)
{
	for (DWORD i = 0; i < dwLen; i++)
		if (bCompare((BYTE*)(dwAddress + i), bMask, szMask))
			DetourFunction((PBYTE)dwAddress + i, Function);

	return 0;
}

bool Compare(const BYTE* pData, const BYTE* bMask, const CHAR* szMask)
{
	for (; *szMask; ++szMask, ++pData, ++bMask)
		if (*szMask == 'x' && *pData != *bMask)
			return 0;

	return (*szMask) == NULL;
}

DWORD FindSignature(BYTE *bMask, CHAR * szMask)
{
	DWORD dwAddress = (DWORD)GetModuleHandleA(NULL);
	DWORD dwLen = 0x2120800;

	for (DWORD i = 0; i<dwLen; i++)
		if (Compare((BYTE*)(dwAddress + i), bMask, szMask))  return (DWORD)(dwAddress + i);

	return 0;
}

DWORD FindSignatureCall(BYTE Length, BYTE *bMask, CHAR * szMask)
{
	DWORD dwAddress = (DWORD)GetModuleHandleA(NULL);
	DWORD dwLen = 0x1120800;

	for (DWORD i = 0; i< dwLen; i++)
		if (Compare((BYTE*)(dwAddress + i), bMask, szMask))
			return *(DWORD*)((dwAddress + i) + Length) + (dwAddress + i + 5);

	return 0;
}

DWORD FindSignaturePointer(BYTE Length, BYTE *bMask, CHAR * szMask)
{
	DWORD dwAddress = (DWORD)GetModuleHandleA(NULL);
	DWORD dwLen = 0x1120800;

	for (DWORD i = 0; i<dwLen; i++)
		if (Compare((BYTE*)(dwAddress + i), bMask, szMask)) 
			return *(DWORD*)((dwAddress + i) + Length);

	return 0;
}
#pragma endregion