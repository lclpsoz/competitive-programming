#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int arr[20];
int aux[20];
int i;

int zero () {
	int k = i;
	for (int j = i-1; j >= 0; j--)
		if (aux[j] == 0) {
			k = j;
			break;
		}
	if (k == i)
		return INF;
	int ans = k-(i-1);
	for (int j = k; j < i-1; j++)
		swap (aux[j], aux[j+1]);

	k = i;
	for (int j = i-2; j >= 0; j--)
		if (aux[j] == 5 || aux[j] == 0) {
			k = j;
			break;
		}

	if (k == i)
		return INF;
	return ans += k-(i-2);
}

int two () {
	int k = i;
	for (int j = i-1; j >= 0; j--)
		if (aux[j] == 5) {
			k = j;
			break;
		}
	if (k == i)
		return INF;
	int ans = k-(i-1);
	for (int j = k; j < i-1; j++)
		swap (aux[j], aux[j+1]);

	k = i;
	for (int j = i-2; j >= 0; j--)
		if (aux[j] == 2 || aux[j] == 7) {
			k = j;
			break;
		}
	if (k == i) return INF;
	return ans + k-(i-2);
}

int main ()
{
	char c;
	int n;
	scanf ("%d", &n);
	for (int nn = 10000; nn < 100000; nn++) {
		n = nn;
		int aj[100];
		i = 0;
		for (i = 0; n; i++) {
			aj[i] = n%10;
			n/=10;
		}
		i--;
		int jj = 0;
		for (jj = 0; i >= 0; jj++)
			arr[i--] = aj[jj];
		i = jj;

		int ans = INF;

		for (int ii = 0; ii < 20; ii++)
			aux[ii] = arr[ii];
		ans = min (ans, abs(zero ()));
		for (int ii = 0; ii < 20; ii++)
			aux[ii] = arr[ii];
		ans = min (ans, abs(two ()));

		if (ans != INF) {
			printf ("%d:\n", nn);
			printf ("%d\n", ans == INF ? -1 : abs(ans));
		}
	}

	return 0;
}
