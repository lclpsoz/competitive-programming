#include <bits/stdc++.h>
using namespace std;

const int M = 1e5+10;

int j;
int n;
string vec[M];
char base[210], arr[210];
int main ()
{
	while (scanf ("%d", &n) != EOF) {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			scanf (" %s ", arr);
			vec[i] = arr;
		}
		sort (vec, vec+n);
		for (int i = 1; i < n; i++) {
			for (j = 0; vec[i][j] != '\0' && vec[i][j] == vec[i-1][j]; j++)
				ans++;
		}

		printf ("%d\n", ans);
	}

	return 0;
}
