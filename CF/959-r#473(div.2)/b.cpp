#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, k, m, x;
string strs[MAXN];
map<string, int> ind;
int value[MAXN];
int link[MAXN];
int mini[MAXN];
string str;
char arr[25];
long long ans;


int main ()
{
	scanf ("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s", arr);
		str = arr;
		vec.push_back (str);
		strs[i] = str;
		ind[str] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		value[i] = x;
	}
	//for (pair<string, int> p : value)
		//cout << p.first << " " << p.second << '\n';
	for (int g = 1; g <= k; g++) {
		scanf ("%d", &n);
		mini[g] = 2e9;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &x);
			link[x] = g;
			mini[g] = min (mini[g], value[x]);
			// printf ("%d: %d\n", g, mini[g]);
		}
	}
	while (m--) {
		scanf ("%s", arr);
		str = arr;
		ans += mini[link[ind[str]]];
		// printf ("%d\n", ans);
	}
	printf ("%lld\n", ans);

	return 0;
}
