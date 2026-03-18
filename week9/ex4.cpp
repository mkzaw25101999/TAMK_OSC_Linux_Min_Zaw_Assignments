/*
 * 'new' is an operator that allocates memory and calls constructors for objects.
 * it return type pointer, complier calculates size automatically.
 * after the array, it handls cleanup with "delete[]".
 *
 *
 * "malloc" is C funtion that allocates a raw byte.
 * unlike "new", "malloc" needs a manual calculation using "sizeOf" and explicit type casting.
 * It is end with "free" for cleaning memory.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int n = 10;  // 10 -element table

	//new c++ allocation
	int* table1 = new int[n];
	//int* table1 is pointer and new int[n] tells OS, find a space big enough for 10 int.
	
	//Fill and Print
	cout << "Table 1 (new): ";
	for(int i =0; i < n; i++) {
		table1[i] = i;
		cout<< table1[i] << " ";
	}
	// put the number 0 in slot 0 and 1 in slot 1.
	cout << endl;
	//clean
	delete[] table1;
	
	//since I used "new" with [], I must use "delete" with[]. 
	//it means I am done with this space, OS can give it to someone.
	
	//c style allocation
	
	int* table2 = (int*)malloc(n * sizeof(int));
	// I must calculate the size: 10 * size of one integer
	// I also (int*) cast it because program know I am storing the integer.

	if(table2 == nullptr) {
		return 1;
	}
	cout << "Table 2 (malloc): ";

	//safety check needs becuase unlike "new", if "malloc" fails, it will return null.
	for(int i = 0; i < n; i++) {
		table2[i] = i;
		cout << table2[i] << " ";
	}
	cout << endl;
	//clean
	free(table2);
	// this will release the memory.
	return 0;
}
