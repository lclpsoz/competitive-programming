#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n;
int tree[MAXN];

int sum (int k)
{
	int s = 0;
	while (k >= 1) {
		s += tree[k];
		k -= k&-k;
	}
	return s;
}

void add(int k, int x)
{
	for (; k <= n; k += k&-k)
		tree[k] += x;
}

int main ()
{
	scanf ("%d", &n);
	int x;
	int arr[MAXN];
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &arr[i]);
		add (i, arr[i]);
	}

	char c;
	while (scanf (" %c %d", &c, &x) != EOF) {
		if (c == 'a')
			add (x, -arr[x]);
		else
			printf ("%d\n", sum (x-1));
	}

	return 0;
}
