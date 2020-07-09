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
	int zero, one;
	scanf ("%d %d", &zero, &one);
	if (zero > one+1 || (zero+1)*2 < one)
		printf ("-1");
	else {
		if (zero >= one) {
			if (zero > one) putchar ('0');
			while (one--)
				printf ("10");
		} else {
			while (one > 1 && one > zero) {
				one-=2;
				printf ("11");
				if (zero) {
					zero--;
					putchar ('0');
				}
			}
			while (zero--) {
				one--;
				printf ("10");
			}
			if (one)
				putchar ('1');
		}
	}
	putchar ('\n');

	return 0;
}
