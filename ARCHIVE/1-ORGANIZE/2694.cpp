#include <bits/stdc++.h>
using namespace std;

char arr[20];
int n;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%s", arr);
		for (int j = 0; arr[j] != '\0'; j++)
			if (!(arr[j] >= '0' && arr[j] <= '9'))
				arr[j] = ' ';
		int a, b, c;
		sscanf (arr, "%d%d%d", &a, &b, &c);
		printf ("%d\n", a+b+c);
	}
	return 0;
}
