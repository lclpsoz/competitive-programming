#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

llu waiting;
llu ans, livre, atual;
vector<llu> vec[1050];
priority_queue<llu, vector<llu>, greater<llu>> pq;

int main ()
{
	int n, a, b;
	while (scanf ("%d", &n) != EOF) {
		ans = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d %d", &a, &b);
			vec[a].push_back (b);
		}
		livre = 1;
		waiting = 0;
		atual = 0;
		for (int i = 1; i <= 1000 && n; i++) {
			waiting += vec[i].size();
			//printf ("i(%d), w(%d), livre(%d)\n", i, waiting, livre);
			for (llu aux : vec[i])
				pq.push(aux);
			vec[i].clear();
			if (livre <= i && pq.size()) {
				atual = pq.top();
				pq.pop();
				livre = i+atual;
				waiting--;
				n--;
			}
			ans += waiting;
			if (atual)
				atual--;
		}
		while (waiting) {
			ans += waiting*atual;
			atual = pq.top();
			pq.pop();
			waiting--;
		}
		printf ("%llu\n", ans);
	}

	return 0;
}
