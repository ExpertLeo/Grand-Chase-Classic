#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

using namespace std;

#include <Windows.h>
#include <stdio.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <TlHelp32.h>
#include <Psapi.h>
#include <intrin.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <tchar.h>
#include <vector>
#include <conio.h>
#include <algorithm>
#include <iomanip>
#include <WinInet.h>
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_internal.h"
#include <map>
#include <set>
#include <wincrypt.h>
#include <winternl.h>
#include <MMSystem.h>
#include <hash_map>
#pragma comment (lib,"winmm.lib")

#pragma region Utility

DWORD FindSignature(BYTE *bMask, CHAR * szMask);
DWORD FindSignatureCall(BYTE Length, BYTE *bMask, CHAR * szMask);
DWORD FindSignaturePointer(BYTE Length, BYTE *bMask, CHAR * szMask);
DWORD FindPattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask);
DWORD DoHook(PBYTE Function, DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask);
DWORD DoBypass(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char * szMask);
#define WAIT(Key, Interval) while(!GetAsyncKeyState(Key) & 1){Sleep(Interval);}
#pragma endregion

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib,"Ws2_32.lib")
#pragma comment (lib, "Wininet.lib") 
#pragma comment(lib,"Psapi.lib")
#pragma warning (disable : 4244 4838 4305 4805)

typedef     DWORD          GCITEMID;
typedef     INT64          GCITEMUID;

extern "C" {
	PBYTE WINAPI DetourFunction(PBYTE pbTargetFunction, PBYTE pbDetourFunction);
	BOOL  WINAPI DetourRemove(PBYTE pbTrampoline, PBYTE pbDetour);
}

extern DWORD EncryptTable00;

#include "EH\Xor.h"
#include "EH\XorStr.h"
#include "EH\XorInc.h"
#include "Virtualizer\VirtualizerSDK.h"
#include "cTimer.h"


#include "Resource.h"
#include "Game.h"
#include "Menu.h"


#include "Main.h"


