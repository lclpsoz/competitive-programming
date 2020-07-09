#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int m, p, f;
int x;
int cap[MAXN];
queue<int> st;
stack<int> arr[MAXN];

int main ()
{
	while (scanf ("%d %d %d", &m, &p, &f) != EOF) {
		for (int i = 0; i < p; i++) {
			cap[i] = 0;
		}
		while (!st.empty()) st.pop();

		for (int i = 0; i < m; i++)
			for (int j = 0; j < p; j++) {
				scanf ("%d", &x);
				if (x == 0)
					cap[j]++;
			}
		for (int i = 0; i < f; i++) {
			scanf ("%d", &x);
			st.push (x);
		}

		for (int i = p-1; i >= 0 && !st.empty(); i--) {
			while (!st.empty () && cap[i]) {
				cap[i]--;
				arr[i].push (st.front());
				st.pop ();
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				if (cap[j]) {
					putchar ('0');
					cap[j]--;
				}
				else if (!arr[j].empty()) {
					printf ("%d", arr[j].top());
					arr[j].pop();
				}
				else
					putchar ('1');
				if (j < p-1)
					putchar (' ');
			}
			putchar ('\n');
		}

	}

	return 0;
}
