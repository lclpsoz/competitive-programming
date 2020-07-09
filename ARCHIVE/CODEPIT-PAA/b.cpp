#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;


int func (int n, int k) {
	if (n <= k) return 1;
	if (n%2 == 1)
		return func (n/2, k) + func ((n/2)+1, k);
	return func (n/2, k) + func (n/2, k);
}

int main ()
{
	int n, k;
	while (scanf ("%d %d", &n, &k), n || k) {
		printf ("%d\n", func (n, k));
	}

	return 0;
}
