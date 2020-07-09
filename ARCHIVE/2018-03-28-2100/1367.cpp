#include <bits/stdc++.h>
using namespace std;

int n, tim;
int que[30];
char c, arr[30];

int main ()
{
	while (scanf ("%d ", &n), n) {
		pair<int, int> ans = {0, 0};
		for (int i = 0; i < 30; i++)
			que[i] = 0;
		for (int i = 0; i < n; i++) {
			c = getchar ()-'A';
			scanf (" %d %s ", &tim, arr);
			if (arr[0] == 'c') {
				ans.first++;
				ans.second += que[c]+tim;
			}
			else
				que[c]+=20;
		}
		printf ("%d %d\n", ans.first, ans.second);
	}

	return 0;
}
