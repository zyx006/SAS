#include"StringUtils.h"

string doubleToString(double num) {
	char* buf;//double数据转换为无符号整数字符串 如12.34 -> 1234
	int dec, sign;//dec->小数点前有几位数字 sign->0为正数，1为负数

	buf = _fcvt(num, 2, &dec, &sign);

	string str;
	if (sign) str += "-";
	int i;
	for (i = 0; i < dec; i++) {
		str += buf[i];
	}
	if (dec == 0)
		str += "0";
	if (strcmp(buf, "00") != 0) {
		str += ".";
		for (; i < strlen(buf); i++) {
			str += buf[i];
		}
	}
	return str;
}

std::string trim(const std::string& str) {
	const std::string& whitespace = " \t";
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content 

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

std::string reduce(const std::string& str) {
	const std::string& fill = " ";
	const std::string& whitespace = " \t";
	// trim first 
	auto result = trim(str);
	// replace sub ranges 
	auto beginSpace = result.find_first_of(whitespace);
	while (beginSpace != std::string::npos)
	{
		const auto endSpace = result.find_first_not_of(whitespace, beginSpace);
		const auto range = endSpace - beginSpace;

		result.replace(beginSpace, range, fill);

		const auto newStart = beginSpace + fill.length();
		beginSpace = result.find_first_of(whitespace, newStart);
	}
	return result;
}