#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 105;

int n;
int link[MAXN];
int size[MAXN];
vector<pii> vec;
int endi[MAXN];

int find (int x) {
	int r = x;
	while (x != link[x]) x = link[x];
	return link[r] = x;
}

bool same (int x, int y) {
	return find (x) == find (y);
}

void unite (int x, int y) {
	x = find (x);
	y = find (y);
	if (size[x] > size[y]) swap (x, y);
	size[y] += size[x];
	link[x] = y;
}

int main ()
{
	for (int i = 0; i < MAXN; i++) {
		link[i] = i;
		size[i] = 1;
	}
	scanf ("%d", &n);
	int o, l, r;
	int id = 1;
	int lst = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d %d %d", &o, &l, &r);
		if (o == 1) {
			vec.pb ({l, id});
			vec.pb ({r, -id});
			endi[id] = r;
			id++;
		} else {
			sort (vec.begin(), vec.end());
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i].y > 0) {
					int aux = endi[vec[i].y];
					lst = vec[i].y;
					for (int j = i+1; vec[j].x < aux; j++)
						if (!same (abs (vec[j].y), vec[i].y))
							unite (abs (vec[j].y), vec[i].y);
				}
			}
			printf ("%s\n", same (l, r) ? "YES" : "NO");
		}
	}

	return 0;
}
