#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;

int n,m;
long long int r[MAXN];

int busca(long long int val)
{
	int st = 1;
	int en = n;
	int mid;
	if(val > r[n])
		return 0;

	while(st<en) {
		mid = (st+en)/2;

		if(r[mid] >= val)
			en = mid;
		else
			st = mid + 1;
	}

	return n+1-en;
}

int main()
{
    scanf("%d %d",&n, &m);
	for(int i = 1;i <= n; i++) {
		scanf ("%lld", &r[i]);
		r[i] = r[i] * r[i];
	}

	long long int ans = 0;
	for(int i=1;i<=m;i++)
	{
		long long int x,y;
		scanf ("%lld %lld", &x ,&y);
		x = x*x + y*y;
		ans += busca(x);
	}

	printf("%lld\n",ans);

	return 0;
}
