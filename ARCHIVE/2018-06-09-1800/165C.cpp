#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int N = 1e6+10;

int k;
char str[N];
ll ans;

int c_zeros (int p) {
	int r = 0;
	++p;
	while (str[p] == 0 && str[p] != 2) {
		++r;
		++p;
	}
	return r;
}

int c_zeros_l (int p) {
	int r = 0;
	--p;
	while (!str[p] && p >= 0) {
		++r;
		--p;
	}
	return r;
}

int main ()
{
	scanf ("%d ", &k);
	scanf ("%s", str);
	str[strlen(str)] = 2;
	for (int i = 0; str[i] != 2; i++)
		str[i]-='0';
	int l = 0;
	int r = 0;
	int qnt = 0;

	if (k > 0) {
		while (qnt < k && str[r] != 2) {
			qnt += str[r];
			++r;
		}
		if (qnt < k) {
			printf ("%lld\n", ans);
			return 0;
		}
		--r;
		while (str[r] != 2) {
			while (!str[l]) ++l;
			int l1 = c_zeros_l(l)+1;
			int r1 = c_zeros(r)+1;
			ans += 1LL*l1*r1;

			r+=r1;
			++l;
			--qnt;
		}
	} else {
		while (str[r] != 2) {
			l = r;
			while (!str[r]) ++r;
			--r;
			// printf ("%d %d\n", l, r);
			ans += (1LL*(r-l+1)*(r-l+2))/2;
			++r;
			while (str[r] == 1) ++r;
		}
	}

	printf ("%lld\n", ans);

	return 0;
}
