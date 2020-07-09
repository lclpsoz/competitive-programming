#include <bits/stdc++.h>
using namespace std;

class ord
{
public:
	bool operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		if (a.first > b.first)
			return false;
		else if (a.first < b.first)
			return true;
		else if (a.second <= b.second)
			return false;
		else
			return true;
	}
};

int t, n, k, id, a, b, c;
priority_queue <pair<int, int>, vector <pair<int, int> >, ord> p;
priority_queue<int, vector<int>, greater<int> > ans;

int main ()
{
	scanf ("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf ("%d %d", &n, &k);
		for (int j = 0; j < n; j++) {
			scanf ("%d %d %d %d", &id, &a, &b, &c);
			p.push ({(a*b*c), id});
		}
		for (int j = 0; j < k; j++) {
			ans.push (p.top().second);
			p.pop();
		}
		for (int j = 0; j < k; j++) {
			printf ("%d", ans.top());
			ans.pop();
			if (j < k-1)
				putchar (' ');
		}
		putchar ('\n');
		while (!p.empty())
			p.pop();
	}

	return 0;
}
