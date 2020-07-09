#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7e4+10;

int n, q;
int l, r, x;
vector<int> arr[MAXN];
vector<int> comp;
int a[MAXN];

int main ()
{
	while (~scanf ("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &a[i]);
			comp.push_back (a[i]);
		}
		sort (comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end()) - comp.begin());

		// Comprimir a[]
		for (int i = 1; i <= n; i++)
			a[i] = lower_bound (comp.begin(), comp.end(), a[i])-comp.begin();

		for (int i = 1; i <= n; i++)
			arr[a[i]].push_back (i);

		scanf ("%d", &q);
		while (q--) {
			scanf ("%d %d %d", &l, &r, &x);
			int it = lower_bound (comp.begin(), comp.end(), x)-comp.begin();
			if (comp[it] != x)
				putchar ('0');
			else {
				auto j = lower_bound (arr[it].begin(), arr[it].end(), l);
				if (j == arr[it].end())
					putchar ('0');
				else if ((*j) <= r)
					putchar ('1');
				else
					putchar ('0');
			}
		}
		putchar ('\n');
	}

	return 0;
}
