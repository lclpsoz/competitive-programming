#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
typedef pair<pair<int, double>, pair<int, int>> pa;

int n, m;
int x, y, z, w;
pa arr[MAXN];

int main ()
{
	int test = 0;
	while (scanf ("%d", &n), n) {
		if (test)
			putchar ('\n');
		for (int i = 0; i < n; i++)
			arr[i] = {{0, 0.0}, {0, i+1}};
		m = (n*(n-1))/2;
		while (m--) {
			scanf ("%d %d %d %d", &x, &y, &z, &w);
			x--; z--;
			arr[x].first.second += w;
			arr[x].second.first += -y;
			arr[z].first.second += y;
			arr[z].second.first += -w;
			if (y > w) {
				arr[x].first.first-=2;
				arr[z].first.first--;
			}
			else {
				arr[z].first.first-=2;;
				arr[x].first.first--;
			}
		}

		for (int i = 0; i < n; i++) {
			if (arr[i].first.second == 0)
				arr[i].first.second = arr[i].second.first;
			else
				arr[i].first.second = (double)arr[i].second.first/arr[i].first.second;
		}
		sort (arr, arr+n);
		test++;
		printf ("Instancia %d\n", test);
		for (int i = 0; i < n; i++) {
			printf ("%d", arr[i].second.second);
			if (i < n-1)
				putchar (' ');
		}
		putchar ('\n');
	}

	return 0;
}
