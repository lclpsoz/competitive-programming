#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

long long a;

int main ()
{
	scanf ("%lld", &a);
	bool t = true;
	if (a < 4)
		printf ("N\n");
	else {
		for (int i = 2; i*i <= a; i++)
			if (a%i == 0) {
				printf ("S\n");
				t = false;
				break;
			}
		if (t)
			printf ("N\n");
	}

	return 0;
}
