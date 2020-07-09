#include "stdio.h"
#include "string.h"
using namespace std;

const int N = 10;

int arr[N];

int main () {
	memset (arr, 0x3f3f3f, sizeof arr);
	printf ("arr: %d: %d\n", 0x3f3f3f, arr[0]);
	memset (arr, 16843009, sizeof arr);
	printf ("16843009: %d\n", arr[0]);
    for (int val = -500; val <= 500; val++) {
        memset (arr, val, sizeof arr);
        printf ("%d: %d\n", val, arr[0]);
    }

	return 0;
}
