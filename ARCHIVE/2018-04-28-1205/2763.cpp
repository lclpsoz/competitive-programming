#include <bits/stdc++.h>
using namespace std;

char arr[15];

int main ()
{
	scanf ("%s", arr);
	for (int j = 0; j < 13; j+=4) {
		for (int i = 0; i < 3 && arr[i+j] != '\0'; i++)
			putchar (arr[j+i]);
		putchar ('\n');
	}

	return 0;
}
