#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;

int p, n, c;
int ans;
int qnt[MAXN];
bool b;

int main ()
{
	while (scanf ("%d %d %d", &p, &n, &c), n && p && c) {
		ans = 0;
		getchar (); // '\n'
		for (int i = 0; i < n; i++)
			for (int j = 0; j < p; j++) {
				b = getchar ()-'0';
				getchar ();
				if (b)
					qnt[j]++;
				else {
					if (qnt[j] >= c)
						ans++;
					qnt[j] = 0;
				}
			}
		for (int i = 0; i < p; i++) {
			if (qnt[i] >= c)
				ans++;
			qnt[i] = 0;
		}

		printf ("%d\n", ans);

	}
	return 0;
}
