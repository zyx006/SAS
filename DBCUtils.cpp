/*
* 数据库连接工具函数接口实现
*/
#include"DBCUtils.h"

bool getConnection(std::string& pwd, _ConnectionPtr& connection) {
    bool isPwdTrue = false;
    _bstr_t strConnect;
    if (!pwd.empty()) {//密码非空，使用SQL Server身份验证
        try {
            std::string con = "Provider=SQLOLEDB.1;Password=" + pwd + "; Persist Security Info = True; User ID = sa; Initial Catalog = stuAdminSystem; Data Source = LAPTOP-4DMOD6O5";
            strConnect = con.c_str();
            connection->Open(strConnect, "", "", NULL);
            isPwdTrue = true;//密码正确，连接成功
            wprintf(L"登录成功！\n");
            return true;
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
        if (!isPwdTrue) {//密码错误，连接失败（打开连接失败，跳出try块执行）
            wprintf(L"密码错误！\n");
            return false;
        }
    }
    else {//密码为空，使用Windows 身份验证
        try {
            strConnect = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=stuAdminSystem;Data Source=LAPTOP-4DMOD6O5";
            connection->Open(strConnect, "", "", NULL);
            isPwdTrue = true;//验证成功，连接成功
            wprintf(L"登录成功！\n");
            return true;
        }
        catch (_com_error& err) {
            wprintf(L"The application throws the error: %s\n", (wchar_t*)err.ErrorMessage());
            wprintf(L"Description = %s\n", (wchar_t*)err.Description());
        }
        if (!isPwdTrue) {//验证失败，连接失败（打开连接失败，跳出try块执行）
            wprintf(L"验证失败！\n");
            return false;
        }
    }
    return false;
}

void getSqlType(std::string& sql, std::string& comType) {
    size_t len = sql.length();
    for (size_t i = 0; i < len; i++) {//获取SQL语句的类别
        if (sql[i] != ' ')
            comType += isupper(sql[i]) ? (sql[i] - 32) : sql[i];
        else return;
    }
}