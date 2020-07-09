#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 5e5+10;

int n;
int arr[MAXN];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);

	sort (arr, arr+n);
	int fi = n-1;
	int mid = n/2;
	int ans = n/2;
	while (mid > -1 && fi > n/2) {
		
		mid--;
	}

	return 0;
}
