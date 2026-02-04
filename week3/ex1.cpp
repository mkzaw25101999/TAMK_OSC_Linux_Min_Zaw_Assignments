#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {

	int wordCount = argc - 1;

	cout << "Number of argument lines: " << wordCount << endl;
	cout << "The line results: " << endl;

	for(int i=1; i < argc; i++) {
		cout << " " << argv[i] << endl;
	}
	
	return 0;

}
