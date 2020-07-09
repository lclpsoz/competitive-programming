#include <bits/stdc++.h>
using namespace std;

int n;

int main ()
{
	int a, b, c;
	queue<int> pi[3];
	while (scanf ("%d", &n), n) {
		int ans = 1;
		while (n--) {
			scanf ("%d %d %d", &a, &b, &c);
			if (a%3)
				pi[0].push (a%3);
			if (b%3)
				pi[1].push (b%3);
			if (c%3)
				pi[2].push (c%3);
		}
		bool test = true;
		while (test) {
			// printf ("%d %d %d\n", pi[0].size(), pi[1].size(), pi[2].size());
			test = false;
			for (int i = 0; i < 3; i++)
				for (int j = i+1; j < 3; j++)
					while (!pi[i].empty() && !pi[j].empty() && (pi[i].front()+pi[j].front())%3==0) {
						test = true;
						pi[i].pop();
						pi[j].pop();
					}
			while (!pi[0].empty() && !pi[1].empty() && !pi[2].empty() && (pi[0].front()+pi[1].front()+pi[2].front())%3==0) {
				test = true;
				pi[0].pop();
				pi[1].pop();
				pi[2].pop();
			}
		}
		for (int i = 0; i < 3; i++) {
			if (!pi[i].empty()) ans = 0;
			while (!pi[i].empty()) pi[i].pop();
		}

		printf ("%d\n", ans);

	}

	return 0;
}
