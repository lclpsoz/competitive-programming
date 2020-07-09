#include <bits/stdc++.h>
using namespace std;

char arr1[100], arr2[100];

int main ()
{
	scanf ("%[^.].%s", arr1, arr2);

	bool test = false;
	for (int i = 0; arr2[i] != '\0'; i++) {
		if (arr2[i] != '0')
			test = true;
		if (test)
			putchar (arr2[i]);
	}
	if (!test)
		putchar ('0');
	printf (".%s\n", arr1);

	return 0;
}
