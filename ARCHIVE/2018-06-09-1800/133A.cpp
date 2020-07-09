#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	char c;
	while (c = getchar (), c != EOF) {
		if (c == 'H' || c == 'Q' || c == '9') {
			printf ("YES\n"); return 0;
		}
	}

	printf ("NO\n");

	return 0;
}
