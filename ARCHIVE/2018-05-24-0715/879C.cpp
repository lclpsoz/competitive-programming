#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int main ()
{
	int n;
	char c;
	int zero, all;
	zero = 0;
	all = (1<<10)-1;
	int ou = 0, ou_ex = 0;
	scanf ("%d", &n);
	int x;
	while (n--) {
		scanf (" %c %d", &c, &x);
		switch (c) {
			case '|':
				all |= x;
				zero |= x;
				break;
			case '&':
				all &= x;
				zero &= x;
				break;
			case '^':
				all ^= x;
				zero ^= x;
				break;
		}
	}

	for (int i = 0; i < 10; i++) {
		x = 1<<i;
		if ((all & x) && (zero & x))
			ou ^= x;
		else if ((all & x) == 0 && (zero & x))
			ou_ex ^= x;
		else if ((all & x) == 0 && (zero & x) == 0) {
			ou ^= x;
			ou_ex ^= x;
		}
	}

	printf ("2\n");
	printf ("| %d\n", ou);
	printf ("^ %d\n", ou_ex);


	return 0;
}
