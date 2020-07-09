#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
set<int> s;

int main ()
{
	scanf ("%d", &n);
	scanf ("%d", &b);
	for (int i = 1; i < n; i++) {
		a = b;
		scanf ("%d", &b);
		s.insert (abs(a-b));
	}

	if (s.size() > 2) {
		printf ("NO\n");
	}
	else if (n == 1) {
		printf ("YES\n");
		printf ("%d %d\n", (int)1e9, b);
	}
	else if (s.size() == 1){
		printf ("YES\n");
		printf ("%d %d\n", (int)1e9, *s.begin());
	}
	else {
		auto it1 = s.begin();
		a = *it1;
		it1++;
		b = *it1;
		if (a == 0 || b == 0)
			printf ("NO\n");
		else if (a == 1 || b == 1) {
			printf ("YES\n");
			printf ("%d %d\n", (int)1e9, a == 1 ? b : a);
		}
		else
			printf ("N0\n");
	}


	return 0;
}
