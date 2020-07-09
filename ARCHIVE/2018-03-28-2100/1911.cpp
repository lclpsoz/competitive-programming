#include <bits/stdc++.h>
using namespace std;

int n, ans, aux;
map <string, string> nomes;
string str1, str2;

int main ()
{
	while (scanf ("%d", &n), n) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> str1 >> str2;
			nomes[str1] = str2;
		}
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> str1 >> str2;
			aux = 0;
			for (int i = 0; i < str2.size(); i++) {
				if (str2[i] != nomes[str1][i])
					aux++;
			}
			if (aux > 1)
				ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
