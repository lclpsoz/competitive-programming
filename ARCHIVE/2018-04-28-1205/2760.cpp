#include <bits/stdc++.h>
using namespace std;

char arr1[100];
char arr2[100];
char arr3[100];

int main ()
{
	scanf ("%[^\n]", arr1);
	getchar ();
	scanf ("%[^\n]", arr2);
	getchar ();
	scanf ("%[^\n]", arr3);
	getchar ();

	printf ("%s%s%s\n", arr1, arr2, arr3);
	printf ("%s%s%s\n", arr2, arr3, arr1);
	printf ("%s%s%s\n", arr3, arr1, arr2);
	printf ("%.10s %.10s %.10s\n", arr1, arr2, arr3);

	return 0;
}
