#include <bits/stdc++.h>
using namespace std;

char arr[20];

int main ()
{
	scanf ("%s", arr);
	printf ("%c%c/%c%c/%c%c\n", arr[3], arr[4], arr[0], arr[1], arr[6], arr[7]);
	printf ("%c%c/%c%c/%c%c\n", arr[6], arr[7], arr[3], arr[4], arr[0], arr[1]);
	printf ("%c%c-%c%c-%c%c\n", arr[0], arr[1], arr[3], arr[4], arr[6], arr[7]);

	return 0;
}
