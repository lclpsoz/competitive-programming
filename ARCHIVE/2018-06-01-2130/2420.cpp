#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
int arr[100010];

int main ()
{
	int x = 0;
	scanf ("%d", &n);
	int aux = n;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &arr[i]);
		x += arr[i];
	}
	int ss = 0;
	int i;
	for (i = 1; i <= n; i++) {
		ss += arr[i];
		if (ss == x/2)
			break;
	}

	printf ("%d\n", i);

	return 0;
}
