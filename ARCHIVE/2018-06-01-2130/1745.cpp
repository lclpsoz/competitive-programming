#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int main ()
{
	int N = 1e6+10;
	char str[N];
	scanf ("%s", str);
	string s = str;

	ll qnt = 0;
	long long ans = 0;
	int numb = 0;
	int acu = 0;
	for (char c : s) {
		c-='0';
		if (c <= 9)
			c%=3;
		if (numb || (c && c <= 9)) {
			if (!c) acu++;
			numb = (numb+c)%3;
			if (numb == 0)
				qnt++;
		}
		else if (!c)
			qnt++;
		else {
			ans += (qnt)*(qnt+1)/2;
			qnt = 0;
		}
	}
	if (qnt)
		ans += (qnt)*(qnt+1)/2;

	printf ("%lld\n", ans);

	return 0;
}
