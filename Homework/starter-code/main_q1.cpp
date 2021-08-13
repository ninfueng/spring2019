#include <iostream>
#include <string>
#include <memory>
using namespace std;


int main(void) {
	int *a = (int *)malloc(100 * sizeof(int));

	for(int i = 0; i < 100; ++i) {
		a[i] = 0;
	}
	
	free(a);

	int *b = new int[100];
	for(int i = 0; i < 100; ++i) {
		b[i] = 0;
	}
	delete[] b;

	unique_ptr<int> c (new int[100]);


	return 0;
}
