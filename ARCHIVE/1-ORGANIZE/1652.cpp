#include <bits/stdc++.h>
using namespace std;

int n, m, size;
map <string, string> mapa;
char arr1[30], arr2[30];
string str;

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%s %s", arr1, arr2);
		mapa[arr1] = arr2;
	}
	for (int i = 0; i < m; i++) {
		scanf ("%s", arr1);
		if (mapa[arr1] != "")
			cout << mapa[arr1] << '\n';
		else {
			size = strlen(arr1);
			if (size > 0) {
				char c = arr1[size-1];
				char d = arr1[size-2];
				if (d != 'a' && d != 'e' && d != 'i' && d != 'o' && d != 'u' && c == 'y') {
					arr1[size-1] = '\0';
					printf ("%sies\n", arr1);
				}
				else if (c == 'o' || c == 's' || (size > 1 && c == 'h' && (d == 'c' || d == 's')) || c == 'x')
					printf ("%ses\n", arr1);
				else
					printf ("%ss\n", arr1);
			}
		}
	}
	return 0;
}
