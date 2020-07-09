#include <bits/stdc++.h>
using namespace std;

int t;
int money, n, m;
int a, b;
int prices[105], price;
int ans;

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &money, &n, &m);
		for (int i = 0; i < n; i++)
			scanf ("%d", &prices[i]);
		ans = 0;
		while (m--) {
			scanf ("%d", &n);
			price = 0;
			while (n--) {
				scanf ("%d %d", &a, &b);
				price += prices[a]*b;
			}
			ans = max (ans, money/price);
		}
		printf ("%d\n", ans);
	}

	return 0;
}
