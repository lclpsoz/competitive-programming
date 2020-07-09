#include <bits/stdc++.h>
using namespace std;

int t, k;
char arr[1050];

int main ()
{
	int ans = 0;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%s %d", arr, &k);
		ans = 0;
		int st = 0;
		int en = st+k-1;
		int len = strlen(arr);
		for (int j = 0; j < len && en < len; j++) {
			if (arr[j] == '-') {
				ans++;
				for (int k = st; k <= en; k++) {
					if (arr[k] == '+')
						arr[k] = '-';
					else
						arr[k] = '+';
				}
			}
			st++;
			en++;
		}
		for (int j = 0; j < len; j++)
			if (arr[j] == '-')
				ans = -1;
		printf ("Case #%d: ", i);
		if (ans == -1)
			printf ("IMPOSSIBLE\n");
		else
			printf ("%d\n", ans);
	}

	return 0;
}
