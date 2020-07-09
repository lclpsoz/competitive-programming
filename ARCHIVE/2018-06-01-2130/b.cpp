#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

char arr[300];
int l;

int check (int i, int j) {
	// printf ("  %d %d\n", i, j);
	while (j <= l) {
		if (j == l)
			return i+1;
		if (i < 0 || arr[i] != arr[j])
			return -1;
		i--;
		j++;
	}

	return -1;
}

int main ()
{
	int ans = 0;
	while (scanf ("%s", arr) != EOF) {
		l = strlen (arr);
		for (int i = 0, j = l-1; ans == 0 &&  i < j; i++, j--) {
			if (arr[i] != arr[j]) ans = 1;
		}
		if (ans) {
			ans = l-1;
			for (int i = l-1; i > 0; i--) {
				int ax = check (i, i);
				// printf ("  %d\n", ax);
				if (ax > -1)
					ans = min (ans, ax);
				ax = check (i-1, i);
				// printf ("  %d\n", ax);
				if (ax > -1)
					ans = min (ans, ax);
			}
		}

		printf ("%d\n", ans);
	}

	return 0;
}
