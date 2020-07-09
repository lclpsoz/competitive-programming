#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int t;
int a, b;
bool verif[MAXN];

int inv (int x)
{
	int y = 0;
	while (x) {
		y*=10;
		y += x%10;
		x/=10;
	}
	return y;
}

int bfs ()
{
	queue<pair<int,int>> q;
	q.push ({0, a});
	while (!q.empty () && q.front().second != b) {
		int w = q.front().first;
		a = q.front().second;
		q.pop();
		if (verif[a]) continue;
		verif[a] = true;
		if (a+1 < 1e4)
			q.push ({w+1, a+1});
		a = inv (a);
		q.push ({w+1, a});
	}
	return q.front().first;
}

int main ()
{
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &a, &b);
		for (int i = 0; i < MAXN; i++)
			verif[i] = false;
		printf ("%d\n", bfs ());
	}

	return 0;
}
