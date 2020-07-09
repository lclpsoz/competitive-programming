#include <bits/stdc++.h>
using namespace std;

int i, j;
int n, m;
long long ans, val;
unordered_map <string, int> money;
char arr[1000];
string str;

int main ()
{
	scanf ("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf ("%s %lld", arr, &val);
		str = arr;
		money[str] = val;
	}
	for (j = 0; j < m; j++) {
		ans = 0;
		scanf ("%s", arr);
		while (strcmp (arr, ".")) {
			str = arr;
			ans += money[str];
			scanf ("%s", arr);
		}
		printf ("%lld\n", ans);
	}
	return 0;
}
