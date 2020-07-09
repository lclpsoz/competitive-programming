#include <bits/stdc++.h>
using namespace std;

int n;
int o, x;
queue<int> q;
stack<int> st;
priority_queue<int> pq;
bool arr[3]; // {q, st, pq}


int main ()
{
	while (scanf ("%d", &n) != EOF) {
		arr[0] = arr[1] = arr[2] = true;
		int qnt = 3;
		while (n--) {
			scanf ("%d %d", &o , &x);
			if (o == 1) {
				if (arr[0])
					q.push (x);
				if (arr[1])
					st.push (x);
				if (arr[2])
					pq.push (x);
			} else {
				if (x == q.front())
					q.pop();
				else if (arr[0]) {
					arr[0] = false;
					qnt--;
				}
				if (x == st.top())
					st.pop();
				else if (arr[1]) {
					arr[1] = false;
					qnt--;
				}
				if (x == pq.top())
					pq.pop();
				else if (arr[2]) {
					arr[2] = false;
					qnt--;
				}
			}
		}

		if (qnt == 0)
			printf ("impossible\n");
		else if (qnt > 1)
			printf ("not sure\n");
		else {
			if (arr[0])
				printf ("queue\n");
			else if (arr[1])
				printf ("stack\n");
			else
				printf ("priority queue\n");
		}
		while (!q.empty()) q.pop();
		while (!st.empty()) st.pop();
		while (!pq.empty()) pq.pop();
	}

	return 0;
}
