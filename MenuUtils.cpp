#include"MenuUtils.h"

void checkOptInput(int& opt, int low, int high) {
	printf(">>>请输入选项(%d-%d)：", low, high);
	while (!(cin >> opt) || (opt < low) || (opt > high)) {
		cout << "输入选项错误！请重新输入：";
		cin.clear();
		while (cin.get() != '\n');
	}
}

string doubleToString(double num) {
	char* buf;
	int dec, sign;

	buf = _fcvt(num, 2, &dec, &sign);

	string str;
	if (sign) str += "-";
	int i;
	for (i = 0; i < dec; i++) {
		str += buf[i];
	}
	str += ".";
	for (; i < strlen(buf); i++) {
		str += buf[i];
	}
	return str;
}