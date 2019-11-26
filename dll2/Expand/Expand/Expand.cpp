#include <iostream>
//#include "MathLibrary.h"
#include <Windows.h>
using namespace std;
typedef void(*PINIT)(const unsigned long long a, const unsigned long long b);
typedef unsigned long long(*p1)();
typedef bool(*p2)();
typedef unsigned(*p3)();

int main()
{
	HMODULE hDLL = LoadLibrary(L"../../MathLibrary/Debug/MathLibrary.dll");
	if (hDLL == NULL) {
		cout << "获取动态链接库失败！";
		return 0;
	}
	PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
	p1 fibonacci_current = (p1)GetProcAddress(hDLL, "fibonacci_current");
	p2 fibonacci_next = (p2)GetProcAddress(hDLL, "fibonacci_next");
	p3 fibonacci_index = (p3)GetProcAddress(hDLL, "fibonacci_index");

	if (fibonacci_init != NULL) {
		fibonacci_init(20, 10);
	}
	// Write out the sequence values until overflow.
	do {
		cout << fibonacci_index() << ": "
			<< fibonacci_current() << endl;
	} while (fibonacci_next());
	cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << endl;
	FreeLibrary(hDLL);
}