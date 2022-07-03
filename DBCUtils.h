#ifndef DBCUTILS_H
#define DBCUTILS_H

#import "c:\\Program Files\\Common Files\\System\\ado\\msado15.dll" no_namespace rename("EOF", "EndOfFile")

#include <stdio.h>  // wprintf
#include <iostream>
#include <locale.h> // setlocale
#include <string>

bool getConnection(std::string& pwd, _ConnectionPtr& connection);
void getSqlType(std::string& sql, std::string& comType);
void showRecordInfo(_RecordsetPtr& recordSet);

#endif // !DBCUTILS_H