#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n, k;
int ans[35];
bool mark[1000];

int main ()
{
	scanf ("%d %d", &n, &k);
	int x;
	for (int i = 1; i <= k; i++) {
		scanf ("%d", &x);
		mark[x] = true;
		ans[i] = x;
	}

	int j = 1;
	for (int i = 1; i <= k; i++) {
		printf ("%d", ans[i]);
		for (int i = 2; i <= n; i++) {
			while (mark[j])	j++;
			mark[j] = true;
			printf (" %d", j);
		}
		putchar ('\n');
	}

	return 0;
}
