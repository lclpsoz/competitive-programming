#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int N = 1e5+10;

int n, k;
int arr[N];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
	int i = 0;
	int j = n-1;
	int aux = arr[i]+arr[j];
	scanf ("%d", &k);
	while (aux != k) {
		if (aux > k)
			j--;
		else
			i++;
		aux = arr[i]+arr[j];
		// printf ("%d %d %d\n", i, j, aux);
	}

	printf ("%d %d\n", arr[i], arr[j]);

	return 0;
}
