#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int N = 505;

int n, p;
int x, y;
int game[N][N];

void fill_sum (int v, int mat[][N]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			mat[i][j] = mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
			if (game[i][j] == v)
				mat[i][j]++;
		}
}

pii func (int one[][N], int two[][N]) {
	pii aux;
	pii sum;
	pii r = {0, 0};
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			aux.x = one[i-1][j-1];
			aux.y = two[i-1][j-1];
			for (int k = 0; i+k <= n && j+k <= n; k++) {
				sum.x = one[i+k][j+k]-one[i-1][j+k]-one[i+k][j-1]+aux.x;
				sum.y = two[i+k][j+k]-two[i-1][j+k]-two[i+k][j-1]+aux.y;
				if (sum.x && !sum.y)
					r.x++;
				else if (!sum.x && sum.y)
					r.y++;
				else if (sum.x && sum.y)
					break;
			}
		}

	return r;
}

int main ()
{
	int one[N][N];
	int two[N][N];

	scanf ("%d %d", &n, &p);
	for (int i = 0; i < p; i++) {
		scanf ("%d %d", &x, &y);
		game[x][y] = 1;
	}
	for (int i = 0; i < p; i++) {
		scanf ("%d %d", &x, &y);
		game[x][y] = 2;
	}

	fill_sum (1, one);
	fill_sum (2, two);

	pii ans = func (one, two);
	printf ("%d %d\n", ans.x, ans.y);


	return 0;
}
