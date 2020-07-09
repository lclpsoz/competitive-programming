#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt, n, x, bigger, bef, last;
priority_queue<int> poke;

int main () {
	scanf ("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		scanf ("%d %d", &last, &n);
		for (j = 0; j < n; j++) {
			scanf ("%d", &x);
			if (x <= last)
				poke.push (x);
		}
		bigger = 0;
		bef = last;
		while (!poke.empty()) {
			if (bef - poke.top() > bigger)
				bigger = bef - poke.top();
			bef = poke.top();
			poke.pop();
		}
		bigger = max (bigger, bef);
		printf ("%d\n", bigger);
	}
	return 0;
}
