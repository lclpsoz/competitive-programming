#include <bits/stdc++.h>
using namespace std;

int n, m;
int k, v;
unordered_map<int, vector<int>> arr;

int main ()
{
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &v);
			arr[v].push_back (i);
		}
		while (m--) {
			scanf ("%d %d", &k, &v);
			if (k > arr[v].size())
				putchar ('0');
			else
				printf ("%d", arr[v][k-1]);
			putchar ('\n');
		}
		arr.clear();
	}

	return 0;
}
