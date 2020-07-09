#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2010;

int n, k;
int arr[MAXN];
map<int, int> mp;
int spaces[MAXN];

int main ()
{
	while (scanf ("%d %d", &n, &k) != EOF) {
		for (int i = 0; i < MAXN; i++) arr[i] = -1;
		arr[0] = 0;
		for (int i = 2, j = 0; j < n-1; j++) {
			scanf ("%d", &arr[i]);
			if (arr[i] != arr[i-2]) {
				arr[i-1] = -(arr[i]-arr[i-2]);
				spaces[j] = arr[i-1];
				i+=2;
			}
		}
		sort (spaces, spaces+n);
		for (int i = 0; i < (k-1); i++) {
			if (mp[spaces[i]] == 0);
			mp[spaces[i]]++;
		}
		int st;
		int ans = 0;
		st = arr[0];
		if (mp[arr[1]] > 0) {
			ans += arr[0]-st;
			st = arr[2];
			mp[arr[1]]--;
		}
		/*for (int i = 0; i <= 2*n; i++)
			printf ("%d ", arr[i]);
		putchar ('\n');*/
		for (int i = 2; arr[i] != -1; i+=2) {
			if (mp[arr[i+1]] > 0 || arr[i+2] == -1) {
				ans += arr[i]-st;
				// printf("%d %d\n", arr[i], st);
				st = arr[i+2];
				if (mp[arr[i+1]] > 0)
					mp[arr[i+1]]--;
			}
		}

		printf ("%d\n", ans);

		mp.clear ();
		for (int i = 0; i < MAXN; i++) spaces[i] = 0;
	}

	return 0;
}
