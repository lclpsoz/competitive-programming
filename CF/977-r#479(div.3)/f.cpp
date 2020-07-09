#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 2e5+10;

int n;
int x;
int val;
int qnt;
map<int, int> mp;
map<int, vector<int>> pos;

int main ()
{
	scanf ("%d", &n);
	qnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		pos[x].pb (i);

		if ((mp[x] = mp[x-1]+1) > qnt) {
			qnt++;
			val = x;
		}
	}

	printf ("%d\n", qnt);
	int bef = -1;
	for (int i = val-qnt+1; i <= val; i++) {
		int j = 0;
		vector<int> aux = pos[i];
		while (aux[j] < bef) j++;
		printf ("%d ", aux[j]);
		bef = aux[j];
	}
	putchar ('\n');

	return 0;
}
