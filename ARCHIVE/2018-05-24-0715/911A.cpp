#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
const int INF = 2e9;

int n;
int x;
int val = INF;
int st;

int main ()
{
	scanf ("%d", &n);
	int ans = INF;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (x < val) {
			val = x;
			st = i;
			ans = INF;
		} else if (x == val) {
			ans = min (ans, i-st);
			st = i;
		}
	}

	printf ("%d\n", ans);

	return 0;
}
