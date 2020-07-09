#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1002*152;

bool arr[MAXN];
int lst;

int main ()
{
	int n, x;
	int ans;
	while (scanf ("%d", &n) != EOF) {
		memset (arr, 0, sizeof (arr));
		lst = 0;
		ans = 1e9;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &x);
			for (int i = MAXN-1; i >= x; i--)
				if (arr[i-x])
					arr[i] = true;
		}
	}


	return 0;
}
