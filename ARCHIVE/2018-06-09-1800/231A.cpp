#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
int x, qnt;

int main ()
{
	int ans = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		qnt = 0;
		for (int j = 0; j < 3; j++) {
			scanf ("%d", &x);
			qnt += x;
		}
		if (qnt > 1)
			ans++;
	}
	printf ("%d\n", ans);

	return 0;
}
