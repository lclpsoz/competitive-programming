#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 2e5+10;

int n, q;
int arr[MAXN];
int bit[MAXN];
priority_queue<int> pq;
priority_queue<int> pq2;

int sum (int p) {
	int r = 0;
	for (int i = p; i >= 1; i-=i&-i)
		r += bit[i];
	return r;
}

void add (int v, int p) {
	for (int i = p; i <= n; i+=i&-i)
		bit[i] += v;
}

int main ()
{
	scanf ("%d %d", &n, &q);

	int x;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		pq.push (x);
	}

	int l, r;
	for (int i = 0; i < q; i++) {
		scanf ("%d %d", &l, &r);
		add (1, l);
		add (-1, r+1);
	}

	for (int i = 1; i <= n; i++)
		pq2.push (sum (i));

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += 1LL*pq.top()*pq2.top();
		pq.pop(); pq2.pop();
	}

	cout << ans << '\n';

	return 0;
}
