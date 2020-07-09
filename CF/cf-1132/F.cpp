#include "stdio.h"
#include "algorithm"
#include "cstring"
using namespace std;

const int N = 505;

int n;
int dp[N][N][30];
char aux[N];
char s[N];

int solve (int l, int r, int ch) {
	if (l == r) return s[l] != ch;
	int &ret = dp[l][r][ch];
	if (ret != -1) return ret;
	ret = N;
	if (s[l] == s[r])
		ret = solve (l+1, r-1, s[l]) + (s[l] != ch);
	for (int mid = l+1; mid <= r; mid++)
		ret = min (ret, solve (l, mid-1, ch) + solve (mid, r, ch));
	
	return ret;
}

int main () {
// 	int REMOVER;
// 	scanf ("%d", &REMOVER);
// 	while (REMOVER--) {
	
	memset (dp, -1, sizeof dp);
	
	scanf ("%d %s", &n, aux);
	int p = 0;
	s[p++] = aux[0];
	for (int i = 1; i < n; i++)
		if (aux[i] != aux[i-1])
			s[p++] = aux[i];
	printf ("%d\n", solve (0, p-1, 29));
	
// 	}
	
	return 0;
}