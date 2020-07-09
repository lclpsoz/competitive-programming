#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> neg;
vector<int> pos;
int zero;

int main ()
{
	scanf ("%d", &n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		if (x == 0)
			zero++;
		else if (x > 0)
			pos.push_back (x);
		else
			neg.push_back (x);
	}
	printf ("1 %d\n", neg.back());
	neg.pop_back();
	if (!pos.empty()) {
		printf ("1 %d\n", pos.back());
		pos.pop_back();
	}
	else {
		printf ("2 %d", neg.back());
		neg.pop_back();
		printf (" %d\n", neg.back());
		neg.pop_back();
	}
	printf ("%ld", pos.size()+neg.size()+zero);
	while (zero--) {
		putchar (' ');
		putchar ('0');
	}
	for (int z : pos)
		printf (" %d", z);
	for (int z : neg)
		printf (" %d", z);
	putchar ('\n');

	return 0;
}
