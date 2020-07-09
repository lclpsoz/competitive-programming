#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int col[12];
int row[12];

int main ()
{
	int r, c;
	char mat[12][12];
	scanf ("%d %d", &r, &c);
	for (int i = 1; i <= r; i++)
	 	for (int j = 1; j <= c; j++) {
			scanf (" %c", &mat[i][j]);
			if (mat[i][j] == 'S') {
				row[i]++;
				col[j]++;
			}
		}

	int ans = 0;
	// Rows
	for (int i = 1; i <= r; i++)
		if (row[i] == 0) {
			for (int j = 1; j <= c; j++)
				mat[i][j] = '\0';
			ans += c;
		}

	// Cols
	for (int j = 1; j <= c; j++)
		if (col[j] == 0)
			for (int i = 1; i <= r; i++)
				if (mat[i][j] == '.') ans++;

	cout << ans << '\n';


	return 0;
}
