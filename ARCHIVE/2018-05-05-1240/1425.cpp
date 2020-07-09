#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2+10;

typedef pair<int, pair<int, int>> piii;

int n, m;
int mini, val, jmp;
int arr[MAXN]; // arr[i] is minimum N for i
queue<piii> q;

int main ()
{
	for (int i = 0; i < MAXN; i++) arr[i] = 1e9;
	arr[1] = 1;
	q.push ({1, {1, 3}}); // {MIN. N, {VALUE, jmp}}
	int ii = 0;
	while (!q.empty()) {
		if (ii++ > 3e7) break;
		mini = q.front().first;
		val = q.front().second.first;
		jmp = q.front().second.second;
		q.pop();
		if ((val+jmp) < MAXN) {
			arr[val+jmp] = min(max (mini, val+jmp), arr[val+jmp]);
			q.push ({arr[val+jmp], {val+jmp, jmp+2}});
		}
		if ((val-jmp) >= 1) {
			arr[val-jmp] = min(max (mini, val-jmp), arr[val-jmp]);
			q.push ({arr[val-jmp], {val-jmp, jmp+2}});
		}
	}

	/*for (int i = 1; i <= MAXN; i++)
		printf ("%2d ", arr[i]);
	putchar ('\n');*/

	while (scanf ("%d %d", &n, &m), n || m) {
		if (m < 30 && (arr[m] < 1e9 && arr[m] > n))
			printf ("Don't make fun of me!\n");
		else
			printf ("Let me try!\n");
	}

	return 0;
}
