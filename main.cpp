#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include <stdio.h>  // wprintf
#include <iostream>
#include <locale.h> // setlocale
#include <string>
#include <vector>
#include "DBCUtils.h"
#include "StudentDAO.h"
#include "Menu.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "chs");
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    string pwd;
    while (true) {
        try {
            wprintf(L"Enter password:");
            getline(cin, pwd);

            _ConnectionPtr pconnect(_uuidof(Connection));
            if (getConnection(pwd, pconnect)) {
                mainMenu(pconnect);
            }
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
    }
    CoUninitialize();
    return 0;
}