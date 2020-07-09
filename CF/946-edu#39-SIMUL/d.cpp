#include <bits/stdc++.h>
using namespace std;

typedef pair<int, deque<int>> pid;

int n, m, k;
int dif;
char c;
deque<int> dq;
priority_queue<pid> pq;
int total;

int main ()
{
	scanf ("%d %d %d", &n, &m, &k);
	total = 0;
	int m1 = m;
	while (n--) {
		dif = -1;
		dq.clear ();
		m = m1;
		while (m--) {
			scanf (" %c", &c);
			if (c == '1') {
				if (dif > -1) {
					total += dif;
					dq.push_back (dif);
				}
				dif = 1;
			}
			else if (dif > -1)
				dif++;
		}
		if (dif > -1)
			total += 1;
		// printf ("%d\n", dif);
		if (dq.empty () && dif > -1)
			pq.push ({1, dq});
		else if (!dq.empty())
			pq.push ({max (dq.front(), dq.back()), dq});
	}

	while (k-- && !pq.empty ()) {
		pid aux = pq.top();
		total -= aux.first;
		pq.pop ();
		if (!aux.second.empty ()) {
			if (aux.second.front() > aux.second.back())
				aux.second.pop_front();
			else
				aux.second.pop_back();
			dq = aux.second;
			if (dq.empty ())
				pq.push ({1, dq});
			else
				pq.push ({max (dq.front(), dq.back()), dq});
		}
	}

	printf ("%d\n", total);

	return 0;
}
