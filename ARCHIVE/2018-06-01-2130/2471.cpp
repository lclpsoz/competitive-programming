#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
map<int, vector<int>> lines;
map<int, vector<int>> col;
int mat[51][51];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int li = 0;
		for (int j = 0; j < n; j++) {
			scanf ("%d", &mat[i][j]);
			li += mat[i][j];
		}
		lines[li].pb (i);
	}
	for (int i = 0; i < n; i++) {
		int ci = 0;
		for (int j = 0; j < n; j++)
			ci += mat[j][i];
		col[ci].pb (i);
	}
	int li, ci, dif;
	for (auto v : lines)
		if (v.y.size() == 1)
			li = v.y[0];
	int x, y;
	x = y = -1000;
	for (auto v : col) {
		if (v.y.size() == 1) {
			ci = v.y[0];
			x = v.x; // Wrong
		} else
			y = v.x; // Correct
	}

	printf ("%d %d\n", mat[li][ci]-(x-y), mat[li][ci]);


	return 0;
}
