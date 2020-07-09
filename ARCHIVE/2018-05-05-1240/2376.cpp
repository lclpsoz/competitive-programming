#include <bits/stdc++.h>
using namespace std;

char arr[100];

int main ()
{
	int a, b;
	for (int i = 1; i <= 8; i++) {
		scanf ("%d %d", &a, &b);
		if (a > b)
			arr[i] = 'A'+2*(i-1);
		else
			arr[i] = 'B'+2*(i-1);
	}
	for (int i = 9, j = 1; i <= 12; i++, j+=2) {
		scanf ("%d %d", &a, &b);
		if (a > b)
			arr[i] = arr[j];
		else
			arr[i] = arr[j+1];
	}
	for (int i = 13, j = 9; i <= 14; i++, j+=2) {
		scanf ("%d %d", &a, &b);
		if (a > b)
			arr[i] = arr[j];
		else
			arr[i] = arr[j+1];
	}
	scanf ("%d %d", &a, &b);
	if (a > b)
		printf ("%c\n", arr[13]);
	else
		printf ("%c\n", arr[14]);



	return 0;
}
