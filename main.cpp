#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include <stdio.h>  // wprintf
#include <iostream>
#include <locale.h> // setlocale
#include <string>
#include<vector>
#include "DBCUtils.h"
#include "StudentDAO.h"
using namespace std;

//高级功能 直接输入sql语句
int main() {
    setlocale(LC_ALL, "chs");
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    string pwd;

    wprintf(L"Enter password:");
    getline(cin, pwd);

    _ConnectionPtr pconnect(_uuidof(Connection));

    if (getConnection(pwd, pconnect)) {
        try {
            
        }catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
    }
    CoUninitialize();
    return 0;
}