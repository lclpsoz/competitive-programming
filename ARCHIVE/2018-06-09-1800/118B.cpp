#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;

void func (int x, int lvl) {
	if (!x) {
		putchar ('0');
		for (int i = 1; i <= n; i++)
			printf (" %d", i);
		for (int i = n-1; i >= 0; i --)
			printf (" %d", i);
		putchar ('\n');
	} else {
		for (int i = 1; i < 2*x; i++) putchar (' ');
		for (int i = 0; i <= lvl; i++)
			printf (" %d", i);
		for (int i = lvl-1; i >= 0; i --)
			printf (" %d", i);
		putchar ('\n');
		func (x-1, lvl+1);
		for (int i = 1; i < 2*x; i++) putchar (' ');
		for (int i = 0; i <= lvl; i++)
			printf (" %d", i);
		for (int i = lvl-1; i >= 0; i --)
			printf (" %d", i);
		putchar ('\n');
	}
}

int main ()
{
	scanf ("%d", &n);
	func (n, 0);

	return 0;
}
