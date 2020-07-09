#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int mat[52][52];

int main ()
{
	int n, k;
	scanf ("%d %d", &n, &k);

	int x, p, t;
	while (n--) {
		scanf ("%d %d", &p, &t);
		mat[p][t]++;
		mat[p][0]++;
	}

	int pos = 0;
	int i;
	for (i = 50; i >= 1; i--)
		if (pos+mat[i][0] >= k)
			break;
		else
			pos+=mat[i][0];

	int j;
	for (j = 1; j <= 50; j++) {
		if (pos+mat[i][j] >= k)
			break;
		else
			pos+=mat[i][j];
	}

	printf ("%d\n", mat[i][j]);

	return 0;
}
