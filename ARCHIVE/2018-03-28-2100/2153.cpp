#include <bits/stdc++.h>
using namespace std;

char arr[40];
bool test;

int main ()
{
	while (scanf (" %[^\n]", arr) != EOF) {
		for (int i = strlen(arr)&1, j = (strlen(arr)+1)/2; i >= 0; i+=2, j++) {
			// printf ("%d %d\n", i, j);
			test = true;
			for (int k = i, l = j; test && l < strlen(arr); k++, l++)
				if (arr[k] != arr[l])
					test = false;
			if (test) {
				arr[j] = '\0';
				break;
			}
		}
		printf ("%s\n", arr);
	}

	return 0;
}
