#pragma once
#include "xor.h"
#define VC_EXTRALEAN
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <random>
#include <string>
#include <thread>
#include<stdio.h>
#include <string.h>
#include <iostream>
#include <tchar.h>
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383
static float value_foundreach;
static int delaycps;
float max_cps = 0.0f;
float min_cps = 0.0f;
float max_ms;
static bool mouse_down;
static bool bool_ac = false;
static bool pressed_ac = false;
HHOOK mouse_hook;

DWORD pid;
HANDLE pHandle;
LRESULT __stdcall call_back(int c, WPARAM wprm, LPARAM lprm)
{

	MSLLHOOKSTRUCT* h = (MSLLHOOKSTRUCT*)lprm;
	if ((h->flags != LLMHF_INJECTED) || (h->flags != LLMHF_LOWER_IL_INJECTED))
	{
		if ((h->flags & LLMHF_INJECTED) != LLMHF_INJECTED)

		{
			if (wprm != WM_MOUSEMOVE)
			{
				if ((h->flags == LLMHF_LOWER_IL_INJECTED) || (h->flags == LLMHF_INJECTED))
					return false;
				switch (wprm)
				{
				case WM_LBUTTONDOWN:
					mouse_down = true;
					break;
				case WM_LBUTTONUP:
					mouse_down = false;
					break;
				}
			}
			return CallNextHookEx(mouse_hook, c, wprm, lprm);
		}
		return false;
	}
	return false;
}


DWORD __cdecl mouse_h()
{
	mouse_hook = SetWindowsHookEx(WH_MOUSE_LL, &call_back, nullptr, 0);

	MSG message;

	while (GetMessage(&message, nullptr, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	UnhookWindowsHookEx(mouse_hook);

	return 0;

}

void DeleteKey()
{
	HKEY hKey = NULL;
	long resposta = RegOpenKeyEx(HKEY_CURRENT_USER,
		_T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\*")),
		0L,
		KEY_ALL_ACCESS,
		&hKey);
	if (resposta == ERROR_SUCCESS)
	{
		RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		RegCloseKey(hKey);
	}
	resposta = RegOpenKeyEx(HKEY_CURRENT_USER, _T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\LastVisitedPidlMRU")), 0L, KEY_ALL_ACCESS, &hKey);
	if (resposta == ERROR_SUCCESS)
	{
		RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		RegCloseKey(hKey);
	}
	resposta = RegOpenKeyEx(HKEY_CURRENT_USER, _T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\dll")), 0L, KEY_ALL_ACCESS, &hKey);
	if (resposta == ERROR_SUCCESS)
	{
		RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		RegCloseKey(hKey);
	}
}
BOOL e_d_p()
{
	HWND hWnd11 = FindWindow(_T(xor ("LWJGL")), nullptr);
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkp;

	if (OpenProcessToken(hWnd11, TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
	{
		LookupPrivilegeValue(nullptr, SE_DEBUG_NAME, &luid);
		tkp.PrivilegeCount = 1;
		tkp.Privileges[0].Luid = luid;
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
		AdjustTokenPrivileges(hToken, false, &tkp, sizeof(tkp), nullptr, nullptr);
		CloseHandle(hToken);
	}
	return TRUE;
}

