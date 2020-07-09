#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
int arr[105];

int main ()
{
	scanf ("%d", &n);
	int x;
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &x);
		arr[x] = i;
	}

	for (int i = 1; i <= n; i++)
		printf ("%d ", arr[i]);
	putchar ('\n');



	return 0;
}
