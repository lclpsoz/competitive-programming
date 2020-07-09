#include <bits/stdc++.h>
using namespace std;

#define prim first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int a, b;
int a1[3];
int a2[3];

int main ()
{
	scanf ("%d %d", &a, &b);
	if (a > b) swap (a, b);
	scanf ("%d %d", &a1[0], &a1[1]);
	scanf ("%d %d", &a2[0], &a2[1]);

	bool ans = false;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			int x = a1[i]+a2[j];
			int y = max (a1[!i], a2[!j]);
			if ((a >= x && b >= y) || (a >= y && b >= x))
				ans = true;
			if (ans)
				break;
		}



	printf ("%s\n", ans ? "S" : "N");

	return 0;
}
