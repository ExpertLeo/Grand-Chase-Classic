#include "include.h"

DWORD WINAPI Hook(LPVOID lpArgs);

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hModule);
	if (dwReason == DLL_PROCESS_ATTACH) 
	{
		CreateThread(NULL, NULL, &Hook, NULL, NULL, NULL);
	}
	return TRUE;
}