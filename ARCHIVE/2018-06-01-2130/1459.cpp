#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 2e6+20;

int a, b;
bool check[MAXN];
pii arr[MAXN];

int main ()
{
	int n;
	while (scanf ("%d", &n) != EOF) {
		for (int i = 1; i < 2*n; i+=2) {
			scanf ("%d %d", &a, &b);
			arr[i] = {a, -i};
			arr[i+1] = {b, i};
			check[i] = false;
		}
		sort (arr+1, arr+2*n+1);
		vector<int> vec;
		int ans = 0;
		for (int i = 1; i <= 2*n; i++) {
			if (arr[i].y < 0)
				vec.pb (-arr[i].y);
			else if (vec.size() && !check[arr[i].y]) {
				// printf ("%d\n", i);
				ans++;
				while (vec.size()) {
					check[vec.back()] = true;
					vec.pop_back();
				}
			}
		}
		if (vec.size()) ans++;
		vec.clear();

		printf ("%d\n", ans);
	}

	return 0;
}
