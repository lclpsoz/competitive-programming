#include <bits/stdc++.h>
using namespace std;

char arr[60];

int main ()
{
	int n;
	int ans = 0, aux = 0;
	while (scanf (" %s ", arr) != EOF) {
		ans = aux = 0;
		scanf ("%d", &n);
		for (int i = 0; arr[i] != '\0'; i++) {
			if (arr[i] == 'W') {
				ans++;
				if (aux)
					ans++;
				aux = 0;
			}
			else {
				aux++;
				// printf ("\taux: %d\n", aux);
				if (aux > n) {
					ans++;
					aux = 1;
				}
				// printf ("\tans: %d\n\n", ans);
			}
		}
		if (aux)
			ans++;
		printf ("%d\n", ans);
	}

	return 0;
}
