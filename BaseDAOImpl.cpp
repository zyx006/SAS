/*
* 数据库操作基础接口实现
*/
#include"BaseDAO.h"

_RecordsetPtr executeSql(_ConnectionPtr connection, const char* sql, vector<string>* v) {
	if (v == NULL) {
		return connection->Execute(sql, NULL, (long)0);
	}

	_CommandPtr command(__uuidof(Command));
	command->ActiveConnection = connection;
	command->CommandText = sql;
	command->CommandType = adCmdText;
	size_t size = v->size();
	for (size_t i = 0; i < size; i++)
	{
		_ParameterPtr p = command->CreateParameter("var" + i, adBSTR, adParamInput, sizeof((*v)[i].c_str()), (*v)[i].c_str());
		command->Parameters->Append(p);
	}
	return command->Execute(NULL, NULL, long(0));
}