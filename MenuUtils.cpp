#include"MenuUtils.h"

void checkOptInput(int& opt, int low, int high) {
	printf(">>>������ѡ��(%d-%d)��", low, high);
	while (!(cin >> opt) || (opt < low) || (opt > high)) {
		cout << "����ѡ��������������룺";
		cin.clear();
		while (cin.get() != '\n');
	}
}