#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int INF = 1e9;

int n;
int t, x;
int now;
stack<int> q;

int main ()
{
	scanf ("%d", &n);
	scanf ("%d %d", &t, &now);

	int ans = 0;
	int over = 0;
	for (int i = 1; i < n; i++) {
		scanf ("%d", &t);
		switch (t) {
			case 1:
				scanf ("%d", &now);
				while (!q.empty() && now > q.top()) {
					ans++;
					q.pop();
				}
				break;
			case 2:
				ans += over;
				over = 0;
				break;
			case 3:
				scanf ("%d", &x);
				if (now > x)
					ans++;
				else
					q.push (x);
				break;
			case 4:
				over = 0;
				break;
			case 5:
				while (!q.empty())
					q.pop();
				break;
			case 6:
				over++;
				break;
		}
	}

	printf ("%d\n", ans);

	return 0;
}
