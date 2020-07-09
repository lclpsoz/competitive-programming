#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n, a, b, c;
int arr[4050];

int main ()
{
	memset (arr, -1, sizeof(arr));
	scanf ("%d %d %d %d", &n, &a, &b, &c);
	arr[0] = 0;
	for (int i = a; i <= 4000; i++)
		if (arr[i-a] > -1)
			arr[i] = max (arr[i], arr[i-a]+1);
	for (int i = b; i <= 4000; i++)
		if (arr[i-b] > -1)
			arr[i] = max (arr[i], arr[i-b]+1);
	for (int i = c; i <= 4000; i++)
		if (arr[i-c] > -1)
			arr[i] = max (arr[i], arr[i-c]+1);

	printf ("%d\n", arr[n]);

	return 0;
}
