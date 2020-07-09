#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

set<int> a, b;
set<pair<int,int>> c;

int main ()
{
	int n, x, ans;
	while (scanf ("%d", &n), n) {
		a.clear(); b.clear(); c.clear();
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			a.insert (x);
		}
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			b.insert (x);
		}
		ans = 0;
		for (int i : a)
			for (int j : b)
				if (mdc (i, j) == 1) {
					c.insert ({i, j});
					c.insert ({j, i});
				}

		printf ("%ld\n", c.size());

	}
	return 0;
}
