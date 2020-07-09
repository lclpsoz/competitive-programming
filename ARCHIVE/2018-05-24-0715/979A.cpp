#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int main ()
{
	long long n;
	scanf ("%lld", &n);
	n++;
	if (n == 1)
		printf ("0\n");
	else if (n%2	== 0)
		printf ("%lld\n", n/2);
	else
		printf ("%lld\n", n);

	return 0;
}
