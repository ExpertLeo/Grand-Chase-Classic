#include "include.h"
#include "Hook.h"

#pragma comment(lib, "detours.lib")
#pragma region External

extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#pragma endregion
#pragma region D3DStuff

DWORD *VTable;
UINT Offset = 0;
UINT Stride = 0;
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
LPDIRECT3DDEVICE9 pDevice1, g_pDevice, r_pDevice;
WNDPROC oriWndProc = NULL;

#pragma endregion
#pragma region BoolandETC

bool isImGUiOK = false, testbool;
float testslider;
bool bShowMenu = true;

#pragma endregion



LRESULT CALLBACK hWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

	if (ImGui_ImplDX9_WndProcHandler(hwnd, uMsg, wParam, lParam) && ImGui::IsAnyWindowHovered())
	{
		return 1l;
	}

	return CallWindowProc(oriWndProc, hwnd, uMsg, wParam, lParam);
}

bool bTest = false;

void MenuRender()
{
	if (!bShowMenu)
		return;

	ImGui_ImplDX9_NewFrame();

	Menu->Draw_Dashboard();

	ImGui::Render();
}

void suspend(DWORD processId)
{
	HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	THREADENTRY32 threadEntry;
	threadEntry.dwSize = sizeof(THREADENTRY32);

	Thread32First(hThreadSnapshot, &threadEntry);

	do
	{
		if (threadEntry.th32OwnerProcessID == processId)
		{
			HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE,
				threadEntry.th32ThreadID);

			SuspendThread(hThread);
			CloseHandle(hThread);
		}
	} while (Thread32Next(hThreadSnapshot, &threadEntry));

	CloseHandle(hThreadSnapshot);
}

D3DDEVICE_CREATION_PARAMETERS d3dcp{ 0 };

void CreateLog(CHAR * File, CONST CHAR *FMD, ...)
{
	ofstream ofile;
	ofile.open(File, ios::app);
	va_list va_alist;

	CHAR logbuf[256] = { 0 };
	va_start(va_alist, FMD);

	vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), FMD, va_alist);
	va_end(va_alist);

	ofile << logbuf << endl;
	ofile.close();
}


HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	VIRTUALIZER_FISH_WHITE_START

	if (!isImGUiOK)
	{
		Menu->Design();

		pDevice->GetCreationParameters(&d3dcp);
		ImGui_ImplDX9_Init(d3dcp.hFocusWindow, pDevice);
		oriWndProc = (WNDPROC)SetWindowLongPtr(d3dcp.hFocusWindow, GWL_WNDPROC, (LONG)(LONG_PTR)hWndProc);
		isImGUiOK = true;
	}

	if (GetAsyncKeyState(VK_INSERT) & 1)
		bShowMenu = !bShowMenu;

	if (GetAsyncKeyState(VK_F6) & 1)
	{
		printf_s("%x - %x - %1.1f - %1.1f \n", GrandChase->GetLocalPlayer() ,GrandChase->GetLocalPlayer()->m_vPosition, GrandChase->GetLocalPlayer()->m_vPosition.x, GrandChase->GetLocalPlayer()->m_vPosition.y);
	}

	if (GetAsyncKeyState(VK_F5) & 1)
	{
		
	}

	MenuRender();

	Menu->Function_Cheats();

	ImGui::GetIO().MouseDrawCursor = bShowMenu;
	
	VIRTUALIZER_FISH_WHITE_END

	return oEndScene(pDevice);
}

HRESULT WINAPI hkReset(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	ImGui_ImplDX9_InvalidateDeviceObjects();

	auto ret = oReset(pDevice, pPresentationParameters);

	if (ret == D3D_OK)
		ImGui_ImplDX9_CreateDeviceObjects();

	return ret;
}

typedef LRESULT(WINAPI* tSendMessage)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
tSendMessage oSendMessage;

LRESULT WINAPI hk_SendMessage(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
	//printf("hWnd: %d - Msg: %d - wParam: %d - lParam: %x \n", hWnd,Msg,wParam,lParam);

	//suspend(GetCurrentProcessId());

	return oSendMessage(hWnd, Msg, wParam, lParam);
}

void Func_Hook()
{
	//return 0;
}

DWORD WINAPI Hook(LPVOID lpAlgs)
{
	DWORD dwD3D9 = 0;

	FILE	*pStream = NULL;
	AllocConsole();
	freopen_s(&pStream, "CONIN$", "r", stdin);
	freopen_s(&pStream, "CONOUT$", "w", stderr);
	freopen_s(&pStream, "CONOUT$", "w", stdout);
	
	DWORD dwGrandChase = (DWORD)GetModuleHandleA(NULL);

	Sleep(15000);

	while (!dwD3D9) 
	{
		Sleep(100);
		dwD3D9 = (DWORD)GetModuleHandle(Xor("d3d9.dll"));
	}
	
	VIRTUALIZER_FISH_WHITE_START
	GrandChase = new cMain();
	Menu = new cMenu();
	Resource = new cResource();
	
	DWORD dwDevice = FindPattern(dwD3D9, 0x128000, (PBYTE)"\xC7\x06\x00\x00\x00\x00\x89\x86\x00\x00\x00\x00\x89\x86", "xx????xx????xx");
	memcpy(&VTable, (void *)(dwDevice + 2), 4);

	oReset = (tReset)DetourFunction((PBYTE)VTable[16], (PBYTE)&hkReset);
	oEndScene = (tEndScene)DetourFunction((PBYTE)VTable[42], (PBYTE)&hkEndScene);
	
	VIRTUALIZER_FISH_WHITE_END
	return FALSE;
}