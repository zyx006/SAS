/*
* ���ݿ����ӹ��ߺ����ӿ�ʵ��
*/
#include"DBCUtils.h"

bool getConnection(std::string& pwd, _ConnectionPtr& connection) {
    bool isPwdTrue = false;
    _bstr_t strConnect;
    if (!pwd.empty()) {//����ǿգ�ʹ��SQL Server�����֤
        try {
            std::string con = "Provider=SQLOLEDB.1;Password=" + pwd + "; Persist Security Info = True; User ID = sa; Initial Catalog = stuAdminSystem; Data Source = LAPTOP-4DMOD6O5";
            strConnect = con.c_str();
            connection->Open(strConnect, "", "", NULL);
            isPwdTrue = true;//������ȷ�����ӳɹ�
            wprintf(L"��¼�ɹ���\n");
            return true;
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
        if (!isPwdTrue) {//�����������ʧ�ܣ�������ʧ�ܣ�����try��ִ�У�
            wprintf(L"�������\n");
            return false;
        }
    }
    else {//����Ϊ�գ�ʹ��Windows �����֤
        try {
            strConnect = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=stuAdminSystem;Data Source=LAPTOP-4DMOD6O5";
            connection->Open(strConnect, "", "", NULL);
            isPwdTrue = true;//��֤�ɹ������ӳɹ�
            wprintf(L"��¼�ɹ���\n");
            return true;
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
        if (!isPwdTrue) {//��֤ʧ�ܣ�����ʧ�ܣ�������ʧ�ܣ�����try��ִ�У�
            wprintf(L"��֤ʧ�ܣ�\n");
            return false;
        }
    }
    return false;
}

void getSqlType(std::string& sql, std::string& comType) {
    size_t len = sql.length();
    for (size_t i = 0; i < len; i++) {//��ȡSQL�������
        if (sql[i] != ' ')
            comType += isupper(sql[i]) ? (sql[i] - 32) : sql[i];
        else return;
    }
}