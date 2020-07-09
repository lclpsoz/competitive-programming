#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n, m;
int maxi[105];
bool check[105];

int main ()
{
	scanf ("%d %d", &n, &m);
	char mat[105][105];
	for (int i = 0; i < n; i++) {
		scanf ("%s", mat[i]);
		for (int j = 0; j < m; j++)
			maxi[j] = max (maxi[j], mat[i][j]-'0');
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (mat[i][j]-'0' == maxi[j]) {
				check[i] = true;
				break;
			}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) if (check[i]) ans++;

	cout << ans << '\n';

	return 0;
}
