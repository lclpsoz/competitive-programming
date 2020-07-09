#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e6+10;

int tsts;
int n, k, s;
vector<long long> arr(MAXN, 0);
vector<long long> comp;
int qnt[MAXN];

int idx (long long x)
{
	return lower_bound (comp.begin(), comp.end(), x);
}

int main ()
{
	scanf ("%d", &tsts);
	while (tsts--) {
		scanf ("%d %d %d", &n, &k, &s);
		arr[0] = s;
		for (int i = 1; i < n; ++i)
			arr[i] = (1LL*arr[i-1]*1103515245 + 12345) % (2147483648LL);
		comp = arr;
		sort (comp.begin(), comp.end());
		comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
		/*for (int i = 0; i < n; i++)
			if (arr[i] != comp[i]) printf ("%lld %lld\n", arr[i], comp[i]);*/

		// Two pointers
		int i = 0, j = k; // [i, j)
		long long ans = 0;
		long long maxi = -1e18;
		for (int l = 0; l <= j; l++) {
			maxi = max (arr[l], maxi);
			qnt[idx(arr[l])]++;
		}
		i++; j++;
		while (j <= n) {
			if (arr[i-1] == maxi)


			i++; j++;
		}

		memset (qnt, 0, sizeof(int)*(n+10));
	}

	return 0;
}
