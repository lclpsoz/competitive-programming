#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, k, m, x;
map<int, string> ind;
map<string, int> ind_back;
map<string, int> value;
map<int, int> link;
int mini[MAXN];
string str;
char arr[25];
vector<string> vec;


int main ()
{
	scanf ("%d %d %d", &n, &k, &m);
	for (int i = 1; i <= n; i++) {
		scanf ("%s", arr);
		str = arr;
		vec.push_back (str);
		ind[i] = str;
		ind_back[str] = i;
	}
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		value[vec[i-1]] = x;
	}
	//for (pair<string, int> p : value)
		//cout << p.first << " " << p.second << '\n';
	for (int g = 1; g <= k; g++) {
		scanf ("%d", &n);
		mini[g] = 2e9;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &x);
			link[x] = g;
			mini[g] = min (mini[g], value[ind[x]]);
			// printf ("%d: %d\n", g, mini[g]);
		}
	}
	long long ans = 0;
	while (m--) {
		scanf ("%s", arr);
		str = arr;
		ans += mini[link[ind_back[str]]];
		// printf ("%d\n", ans);
	}
	printf ("%lld\n", ans);

	return 0;
}
