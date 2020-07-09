#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1020;
const int MAXV = 6020;

int n, v;
double dp[MAXN][MAXV];
double ans[MAXN][MAXV];
int st;

void imprime () {
	for (int i = 1; i < 20; i++)
		printf ("|[%3d]", i);
	putchar ('\n');
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++)
			printf ("|%2.3lf", abs(ans[i][j]));
		putchar ('\n');
	}

	printf ("%lf\n", dp[1000][1100]);
}

int main ()
{
	for (int i = 11; i <= 16; i++)
		dp[1][i] = 1/6.0;

	double aux;
	int st, en;
	for (int i = 2; i < MAXN; i++) {
		st = i+4;
		en = i+9;
		aux = dp[i-1][i+9];
		for (int k = 10+i; aux && k < MAXV; k++) {
			dp[i][k] += aux/6;
			en++;
			aux -= dp[i-1][st];
			aux += dp[i-1][en];
			st++;
		}
	}

	// imprime();

	for (int i = MAXN-2; i >= 1; i--)
		for (int j = MAXN-2; j >= 11; j--)
			ans[i][j-10] = ans[i][j+1-10] + dp[i][j];

	while (scanf ("%d %d", &n, &v) != EOF) {
		printf ("%.4lf\n", ans[n][v]);
	}

	return 0;
}
