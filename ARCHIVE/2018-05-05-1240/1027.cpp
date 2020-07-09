#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int MAXN = 70000;
const int C = 35000;
typedef pair<int, int> point;

int n, x, y;
int mini, maxi;
vector<point> vec;
vector<int> arr[MAXN]; // sum 35000 to each x so it will be in [2232, 67768]
int ans;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		if (n) {
			ans = 1;
			vec.clear();
			while (n--) {
				scanf ("%d %d", &x, &y);
				vec.push_back ({x, y});
			}
			sort (vec.begin(), vec.end());

			maxi = -1e6;
			mini = 1e6;
			for (point p : vec) {
				// printf ("%d %d\n", p.x, p.y);
				arr[p.y+C].push_back (p.x);
				maxi = max (maxi, p.y+C);
				mini = min (mini, p.y+C);
			}
			int aux, j, k;
			for (int i = mini; i <= maxi; i++) {
				if (arr[i].size() && arr[i+2].size()) {
					aux = 1;
					j = 0; // arr[i]
					k = 0; // arr[i+2]
					while (1) {
						// printf ("%d, %d, %ld\n", arr[i][j], j, arr[i].size());
						// IN arr[i][j];
						while (k < arr[i+2].size () && arr[i][j] >= arr[i+2][k]) k++;
						if (k == arr[i+2].size()) break;
						aux++;
						// printf ("(%d, %d) %d, %ld\n", i+2-C, k, arr[i+2][k], arr[i+2].size());
						// IN arr[i+2][j];
						while (j < arr[i].size () && arr[i+2][k] >= arr[i][j]) j++;
						if (j == arr[i].size()) break;
						aux++;
					}
					ans = max (aux, ans);
					// printf (">>> %d %d :: %d\n", i-C, i+2-C, aux);
					aux = 1;
					j = k = 0;
					while (1) {
						// printf ("(%d, %d) %d, %ld\n", i+2-C, k, arr[i+2][k], arr[i+2].size());
						// IN arr[i+2][j];
						while (j < arr[i].size () && arr[i+2][k] >= arr[i][j]) j++;
						if (j == arr[i].size()) break;
						// printf ("%d, %d, %ld\n", arr[i][j], j, arr[i].size());
						aux++;
						// IN arr[i][j];
						while (k < arr[i+2].size () && arr[i][j] >= arr[i+2][k]) k++;
						if (k == arr[i+2].size()) break;
						aux++;
					}
					ans = max (aux, ans);
					// printf (">>> %d %d :: %d\n", i-C, i+2-C, aux);
				}
				arr[i].clear();
			}

			printf ("%d\n", ans);
			// printf ("ANS : %d\n", ans);
			// printf ("--------------\n");
		} else {
			printf ("0\n");
		}
	}

	return 0;
}
