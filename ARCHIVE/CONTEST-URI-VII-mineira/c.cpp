#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5+10;

int n, x;
int arr[MAXN];
int mat[7][MAXN];
int ans[10];

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= 6; i++)
		ans[i] = n;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		ans[7-x]++;
		ans[x]--;
	}

	int resp = 1e9;
	for (int i = 1; i < 7; i++)
		resp = min (resp, ans[i]);

	printf ("%d\n", resp);

	return 0;
}
