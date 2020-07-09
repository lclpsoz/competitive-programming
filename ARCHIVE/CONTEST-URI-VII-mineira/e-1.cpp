#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;


int n, x;
deque<int> v;

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i < n; i++)
		v.pb (i);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		auto it = lower_bound (v.begin(), v.end(), x);
		printf ("%ld", (it - v.begin())+1);
		v.erase (it);
		if (i < n-1)
			putchar (' ');
	}
	putchar ('\n');

	return 0;
}
