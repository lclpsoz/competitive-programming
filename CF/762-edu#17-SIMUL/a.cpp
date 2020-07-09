#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

long long n, k;
vector<long long> vec;

int main ()
{
	scanf ("%lld %lld", &n, &k);
	for (long long i = 1; i*i <= n; i++)
		if (n%i == 0) {
			vec.pb (i);
			if (i != (n/i))
				vec.pb (n/i);
		}
	sort (vec.begin(), vec.end());

	if (vec.size() < k)
		printf ("-1\n");
	else
		printf ("%lld\n", vec[k-1]);


	return 0;
}
