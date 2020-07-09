#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int n, v, e, ans;
char x, y;
bool adj[30][30], vec[30];
priority_queue<int, vector<int>, greater<int> > seq;

void dfs (int z) {
	int i;
	vec[z] = true;
	seq.push(z);
	for (i = 0; i <= 'z'-'a' && i < v; i++)
		if (adj[z][i] && !vec[i])
			dfs(i);
}

int main ()
{
	int i, j, k;
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		ans = 0;
		scanf ("%d %d", &v, &e);
		for (j = 0; j < e; j++) {
			scanf (" %c %c", &x, &y);
			adj[x-'a'][y-'a'] = true;
			adj[y-'a'][x-'a'] = true;
		}
		printf ("Case #%d:\n", i+1);
		for (j = 0; j <= 'z'-'a' && j < v; j++) {
			if (!vec[j]) {
				ans++;
				dfs (j);
				while (!seq.empty()) {
					putchar (seq.top()+'a');
					putchar (',');
					seq.pop();
				}
				putchar ('\n');
			}
		}
		printf ("%d connected components\n\n", ans);
		for (j = 0; j < v; j++) {
			vec[j] = 0;
			for (k = 0; k < v; k++)
				adj[j][k] = 0;
		}
	}
	return 0;
}
