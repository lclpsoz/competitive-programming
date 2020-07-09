#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, i, a, b;
	char str[20];
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%s", str);
		a = b = 0;
		int j = 0;
		for (j = 0; j < 14; j++) {
			printf ("%s\n", &str[j]);
			sscanf (&str[j], " %d ", &a);
			printf ("%d %d\n", a, j);
			b += a;
		}
		printf ("%d\n", b);
	}
	return 0;
}
