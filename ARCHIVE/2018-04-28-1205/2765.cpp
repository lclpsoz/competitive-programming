#include <bits/stdc++.h>
using namespace std;

char arr[150];

int main ()
{
	scanf ("%[^\n]", arr);
	int i = 0;
	for (; arr[i] != ',' && arr[i] != '\0'; i++)
		putchar (arr[i]);
	putchar ('\n');
	i++;
	for (; arr[i] != '\0'; i++)
		putchar (arr[i]);
	putchar ('\n');

	return 0;
}
