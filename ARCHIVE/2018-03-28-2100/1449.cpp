#include <bits/stdc++.h>
using namespace std;

int t, n, m;
char arr[100000], *aux;
string str1, str2;
map <string, string> dict;
int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		dict.clear();
		scanf ("%d %d", &m, &n);
		for (int j = 0; j < m; j++) {
			scanf (" %[^\n]", arr);
			str1 = arr;
			scanf (" %[^\n]", arr);
			str2 = arr;
			dict[str1] = str2;
		}
		for (int j = 0; j < n; j++) {
			scanf (" %[^\n]", arr);
			aux = strtok (arr, " ");
			while (aux != NULL) {
				str1 = aux;
				if (dict[str1] == "")
					cout << str1;
				else
					cout << dict[str1];
				aux = strtok (NULL, " ");
				if (aux != NULL)
					putchar (' ');
			}
			putchar ('\n');
		}
		putchar ('\n');
	}
	return 0;
}
