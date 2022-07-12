#pragma once

/// next:

/// void DelMe()
/// {
///	TCHAR szModuleName[MAX_PATH];
///	TCHAR szCmd[2 * MAX_PATH];
///	STARTUPINFO si = { 0 };
///	PROCESS_INFORMATION pi = { 0 };
///
///	GetModuleFileName(NULL, szModuleName, MAX_PATH);

	/// StringCbPrintf(szCmd, 2 * MAX_PATH, SELF_REMOVE_STRING, szModuleName);

///	CreateProcess(NULL, szCmd, NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, &si, &pi);

	/// CloseHandle(pi.hThread);
	/// CloseHandle(pi.hProcess);
///} 


/// void to delete exe with bat, ps: this is totally shit but you can try it
/// next:

	/// void kysniggers() {
	/// HKEY hKey = NULL;
	/// long resposta = RegOpenKeyEx(HKEY_CURRENT_USER,
	///	_T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\*")),
	///	0L,
	///	KEY_ALL_ACCESS,
	///	&hKey);
	///	if (resposta == ERROR_SUCCESS)
	/// {
	///	RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		///	RegCloseKey(hKey);
	/// }
	/// resposta = RegOpenKeyEx(HKEY_CURRENT_USER, _T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\LastVisitedPidlMRU")), 0L, KEY_ALL_ACCESS, &hKey);
	/// if (resposta == ERROR_SUCCESS)
	/// {
	///		RegDeleteValue(hKey, _T(xor ("MRUListEx")));
	///		RegCloseKey(hKey);
	/// }
	/// resposta = RegOpenKeyEx(HKEY_CURRENT_USER, _T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\exe")), 0L, KEY_ALL_ACCESS, &hKey);
	///	if (resposta == ERROR_SUCCESS)
		///{
		///	RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		///	RegCloseKey(hKey);
		///	}
	///	resposta = RegOpenKeyEx(HKEY_CURRENT_USER, _T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\dll")), 0L, KEY_ALL_ACCESS, &hKey);
	///	if (resposta == ERROR_SUCCESS)
		///	{
		///		RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		///		RegCloseKey(hKey);
		///}
	///	resposta = RegOpenKeyEx(HKEY_CURRENT_USER, _T(xor ("Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\ComDlg32\\OpenSavePidlMRU\\bat")), 0L, KEY_ALL_ACCESS, &hKey);
	///	if (resposta == ERROR_SUCCESS)
		/// {
		///		RegDeleteValue(hKey, _T(xor ("MRUListEx")));
		///	RegCloseKey(hKey);
		///	}
/// }

/// use brain, it is really bad/good feature
