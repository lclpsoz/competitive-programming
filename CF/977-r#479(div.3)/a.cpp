#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int a, b;

int main ()
{
	scanf ("%d %d", &a, &b);
	while (b--) {
		if (a%10 != 0)
			a--;
		else
			a/=10;
	}
	printf ("%d\n", a);

	return 0;
}
