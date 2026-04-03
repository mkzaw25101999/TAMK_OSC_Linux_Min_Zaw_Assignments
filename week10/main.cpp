#include <iostream>
extern void func1();
extern void func2();

int main() {
	std::cout << "Main: Calling Libraries..." << std::endl;
	func1();
	func2();
	return 0;
}

