#include <bits/stdc++.h>
using namespace std;

int n, m, p;
map <string, double> vec;
double val, ans;
string str;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &m);
		for (int j = 0; j < m; j++) {
			cin >> str >> val;
			vec[str] = val;
		}
		scanf ("%d", &p);
		ans = 0;
		for (int j = 0; j < p; j++) {
			cin >> str >> val;
			ans += vec[str] * val;
		}
		printf ("R$ %.2lf\n", ans);
		vec.clear();
	}
	return 0;
}
