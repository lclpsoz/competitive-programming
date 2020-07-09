#include "vector"
#include "stdio.h"
#include "string.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

////////////////////////// Solution starts below. //////////////////////////////

const int M = 1e3+10, W = 2100;

int wkit, m, n;
int wei[M];
char names[M][15];
int bag[W];

void solve (int w) {
	w = (w+1)/2;
	w -= wkit;
	
	for (int i = w; i < W; i++)
		if (bag[i] != -1) {
			vector<int> ans;
			while (i) {
				ans.push_back (bag[i]);
				i -= wei[bag[i]];
			}
			printf ("%d", len (ans));
			for (int v : ans)
				printf (" %s", names[v]);
			putchar ('\n');
			return;
		}
		
	printf ("-1\n");
}

int main () {
	memset (bag, -1, sizeof bag);
	scanf ("%d %d", &wkit, &m);
	for (int i = 1; i <= m; i++)
		scanf ("%s %d", names[i], &wei[i]);
	
	bag[0] = 0;
	for (int i = 1; i <= m; i++)
		for (int j = W-1; j >= wei[i]; j--)
			if (bag[j-wei[i]] != -1 and bag[j] == -1)
				bag[j] = i;
	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int w;
		scanf ("%d", &w);
		solve (w);
	}
	
	return 0;
}
