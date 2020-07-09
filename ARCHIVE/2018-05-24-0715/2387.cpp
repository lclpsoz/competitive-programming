#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
priority_queue<pii> pq;

int main ()
{
	scanf ("%d", &n);
	pii p;
	for (int i = 0; i < n; i++) {
		// Primeiro o final
		scanf ("%d %d", &p.y, &p.x);
		p.y = -p.y;
		p.x = -p.x;
		pq.push (p);
	}

	int ans = 0;
	int livre = -1;
	while (!pq.empty()) {
		p = pq.top();
		pq.pop();
		p.y = -p.y;
		p.x = -p.x;
		if (p.y >= livre) {
			ans++;
			livre = p.x;
		}
	}

	printf ("%d\n", ans);

	return 0;
}
