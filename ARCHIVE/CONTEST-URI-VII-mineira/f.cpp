#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

const int MOD = 1e9+7;

int qnt;
char c;
int aux;

int modpow(int x, int n, int m) {
	if (n == 0)
		return 1%m;
	long long u = modpow (x, n/2, m);
	u = (u*u)%m;
	if (n%2 == 1)
		u = (u*x)%m;
	return u;
}

int main ()
{

	while (c = getchar ()) {
		if (c == 'M')
			aux++;
		else if (c == 'F')
			aux--;
		else
			break;
		if (aux == 0)
			qnt++;
	}

	printf ("%d\n", modpow (2, qnt-1, MOD));

	return 0;
}
