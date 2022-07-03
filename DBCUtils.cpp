#include"DBCUtils.h"

bool getConnection(std::string& pwd, _ConnectionPtr& connection) {
    bool isPwdTrue = false;
    _bstr_t strConnect;
    if (!pwd.empty()) {
        try {
            std::string con = "Provider=SQLOLEDB.1;Password=" + pwd + "; Persist Security Info = True; User ID = sa; Initial Catalog = stuAdminSystem; Data Source = LAPTOP-4DMOD6O5";
            strConnect = con.c_str();
            connection->Open(strConnect, "", "", NULL);
            isPwdTrue = true;
            wprintf(L"µÇÂ¼³É¹¦£¡\n");
            return true;
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
        if (!isPwdTrue) {
            wprintf(L"ÃÜÂë´íÎó£¡");
            return false;
        }
    }
    else {
        try {
            strConnect = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=stuAdminSystem;Data Source=LAPTOP-4DMOD6O5";
            connection->Open(strConnect, "", "", NULL);
            isPwdTrue = true;
            wprintf(L"µÇÂ¼³É¹¦£¡\n");
            return true;
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
        if (!isPwdTrue) {
            wprintf(L"ÑéÖ¤Ê§°Ü£¡");
            return false;
        }
    }
}

void getSqlType(std::string& sql, std::string& comType) {
    int len = sql.length();
    for (int i = 0; i < len; i++) {//ÅÐ¶ÏsqlÓï¾äÀàÐÍ
        if (sql[i] != ' ')
            comType += isupper(sql[i]) ? (sql[i] - 32) : sql[i];
        else return;
    }
}

void showRecordInfo(_RecordsetPtr& recordSet) {
    COORD pos = { 0,0 };
    for (long i = 0; i < recordSet->Fields->Count; i++) {
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        wprintf(L"%s", (wchar_t*)recordSet->Fields->GetItem(i)->Name);
        pos.X += (short)recordSet->Fields->GetItem(i)->DefinedSize % 16 + 4;
    }
    for (; !recordSet->EndOfFile; recordSet->MoveNext()) {
        pos.X = 0;
        pos.Y++;
        for (long i = 0; i < recordSet->Fields->Count; i++) {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            if (recordSet->Fields->GetItem(i)->Value.vt == VT_NULL) {
                wprintf(L"Null");
            }
            else {
                wprintf(L"%s", (wchar_t*)(_bstr_t)recordSet->Fields->GetItem(i)->Value);
            }
            pos.X += (short)recordSet->Fields->GetItem(i)->DefinedSize % 16 + 4;
        }
    }
}