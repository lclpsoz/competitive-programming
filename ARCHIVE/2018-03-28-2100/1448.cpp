#include <bits/stdc++.h>
using namespace std;

int t;
char arr1[105], arr2[105], arr3[105];

int main ()
{
	scanf ("%d", &t);
	getchar (); // '\n'
	for (int i = 0; i < t; i++) {
		scanf ("%[^\n]", arr1);
		getchar (); // '\n'
		scanf ("%[^\n]", arr2);
		getchar (); // '\n'
		scanf ("%[^\n]", arr3);
		getchar (); // '\n'
		pair <int, int> prim = {-1, -1};
		pair <int, int> qnt = {0, 0};
		for (int j = 0; arr1[j] != '\0'; j++) {
			if (arr1[j] != arr2[j]) {
				qnt.first++;
			}
			else if (prim.first == -1)
				prim.first = j;

			if (arr1[j] != arr3[j]) {
				qnt.second++;
			}
			else if (prim.second == -1)
				prim.second = j;
			if (prim.first >= 0 && prim.first == prim.second)
				prim.first = prim.second = -1;
		}
		printf ("Instancia %d\n", i+1);
		// printf ("%d %d\n", prim.first, prim.second);
		if (qnt.first > qnt.second)
			printf ("time 2\n");
		else if (qnt.second > qnt.first)
			printf ("time 1\n");
		else if (prim.first < prim.second)
			printf ("time 1\n");
		else if (prim.first > prim.second)
			printf ("time 2\n");
		else
			printf ("empate\n");
		putchar ('\n');
	}

	return 0;
}
