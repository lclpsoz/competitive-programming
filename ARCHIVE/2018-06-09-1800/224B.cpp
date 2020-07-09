#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e5+10;

int n, k, x;
int arr[MAXN];
int vals[MAXN];

int main ()
{
	scanf ("%d %d", &n, &k);
	int i, j;
	j = 1;
	for (i = 1; k && i <= n; i++) {
		scanf ("%d", &x);
		vals[i] = x;
		if (arr[x] == 0)
			k--;
		arr[x]++;
	}
	i--;

	if (k) {
		printf ("-1 -1\n");
		return 0;
	}

	while (true) {
		if (arr[vals[j]] == 1)
			break;
		arr[vals[j]]--;
		j++;
	}

	printf ("%d %d\n", j, i);


	return 0;
}
