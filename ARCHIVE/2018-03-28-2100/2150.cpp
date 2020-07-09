#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;

int ans;
char c;
long long vows;

int main ()
{
	while (c = getchar (), c != EOF && c != '\n' && c != ' ') {
		vows = 0;
		while (c != '\n') {
			if (c >= '0' && c <= '9')
				vows |= 1LL<<(('z'-'a')+(c-'0')+1);
			else
				vows |= 1LL << tolower (c)-'a';
			c = getchar ();
		}
		ans = 0;
		while (c = getchar (), c != '\n' && c != EOF) {
			if (c >= '0' && c <= '9')
				ans += (vows & 1LL<<(('z'-'a')+(c-'0')+1))>0;
			else if (c = tolower (c), c >= 'a' && c <= 'z')
				ans += (vows & 1LL << (tolower (c)-'a'))>0;
		}
		printf ("%d\n", ans);

	}

	return 0;
}
