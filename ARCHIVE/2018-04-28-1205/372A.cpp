#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n, x;
vector<int> vec;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		vec.push_back (x);
	}
	sort (vec.begin(), vec.end());
	for (auto st = vec.rbegin(); st != vec.rend();) {
		x = (*st)*2;
		// printf ("%d\n", x);
		auto pos = lower_bound (vec.begin(), vec.end(), x);
		if (pos != vec.end()) {
			printf ("%d %d %d\n", *st, x, *pos);
			n--;
			vec.erase (pos);
			auto lst = st;
			st++;
			vec.erase (next(lst).base());
		}
		else
			st++;
	}
	for (int zz : vec)
		printf ("%d\n", zz);

	printf ("%d\n", n);


	return 0;
}
