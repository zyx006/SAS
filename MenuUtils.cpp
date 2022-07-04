#include"MenuUtils.h"

void checkOptInput(int& opt, int low, int high) {
	printf(">>>请输入选项(%d-%d)：", low, high);
	while (!(cin >> opt) || (opt < low) || (opt > high)) {
		cout << "输入选项错误！请重新输入：";
		cin.clear();
		while (cin.get() != '\n');
	}
}