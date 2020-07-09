#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int llu;
const llu cte = 1e12;
const int cte1 = 1e6;
vector<int> t_primos;
bool n_prim[cte1+12];

bool bb (int in, int fin, llu x)
{
	if (in == fin) return x == t_primos[in];
	int mid = (in+fin)/2;
	if (x < (llu)t_primos[mid]*t_primos[mid])
		return bb (in, mid, x);
	else if (x == (llu)t_primos[mid]*t_primos[mid])
		return true;
	else return bb (mid+1, fin, x);
}

int main()
{
	int n;
	llu x;
	n_prim[0] = n_prim[1] = true;
	for (int i = 2; i*i < cte; ++i) {
		if (!n_prim[i]) {
			for (int j = i*i; j <= cte1; j += i)
				n_prim[j] = true;
			t_primos.push_back(i);
		}
	}
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		if (bb (0, t_primos.size()-1, x)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
