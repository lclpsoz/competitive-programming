// Using index vecression
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int n;
long long x;
deque<long long> vec;

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		if (n) {
			vec.clear();
			while (n--) {
				scanf ("%lld", &x);
				vec.push_back (x);
			}
			sort (vec.begin(), vec.end());
			while (vec[0] == vec[1]) {
				vec.pop_front();
				vec.pop_front();
			}
			long long a = vec[0];
			vec.pop_front();
			while (vec.size() > 1 && vec[0] == vec[1]) {
				vec.pop_front();
				vec.pop_front();
			}
			long long b = vec[0];
			if (a > b) swap (a, b);
			printf ("%lld %lld\n", a, b);
		}
	}

	return 0;
}
