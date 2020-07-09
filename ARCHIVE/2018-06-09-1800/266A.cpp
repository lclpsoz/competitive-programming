#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;

int main ()
{
	scanf ("%d ", &n);
	char c = '\0';
	char b = '\0';
	int ans = 0;
	while (c = getchar (), c != EOF)
		if (c == b) ans++;
		else b = c;

	printf ("%d\n", ans);

	return 0;
}
