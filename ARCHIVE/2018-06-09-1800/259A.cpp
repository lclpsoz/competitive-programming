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
	char str[10];
	bool now;
	for (int i = 0; i < 8; i++) {
		scanf ("%s", str);
		now = (str[0] == 'B');
		for (int j = 1; j < 8; j++) {
			if (now && str[j] == 'B') {
				printf ("NO\n");
				return 0;
			} else if (!now && str[j] == 'W') {
				printf ("NO\n");
				return 0;
			}
			now = !now;
		}
	}
	printf ("YES\n");
	return 0;
}
