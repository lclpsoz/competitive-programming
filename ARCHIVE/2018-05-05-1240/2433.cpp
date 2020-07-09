#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

list<int> lst;
int n, k;

int main ()
{
	scanf ("%d %d", &n, &k);
	int x, maxi, mini;
	maxi = 0;
	mini = 1e9;
	while (n--) {
		scanf ("%d", &x);
		lst.push_back (x);
	}
	lst.sort();

	lst.sort();

	return 0;
}
