#include <bits/stdc++.h>
using namespace std;

char arr[100];
int x;

int main ()
{
	while (scanf ("%s", arr), arr[0] != '-' || arr[1] != '1' || arr[2] != '\0') {
		if (arr[0] == '0' && arr[1] == 'x') {
			sscanf (arr, "%x", &x);
			printf ("%d\n", x);
		}
		else {
			sscanf (arr, "%d", &x);
			printf ("0x%X\n", x);
		}
	}

	return 0;
}
