#include"MenuUtils.h"

void checkOptInput(int& opt, int low, int high) {
	printf(">>>������ѡ��(%d-%d)��", low, high);
	while (!(cin >> opt) || (opt < low) || (opt > high)) {
		cout << "����ѡ��������������룺";
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