#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int check[150];
int arr[150];

int main ()
{
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &arr[i]);

	vector<int> vec;
	for (int i = 0; i < n; i++) {
		if (check[arr[i]] == 0) {
			check[arr[i]] = true;
			vec.pb (i+1);
		}
	}

	if (vec.size() >= k) {
		printf ("YES\n");
		for (int i = 0; i < k; i++)
			printf ("%d ", vec[i]);
		putchar ('\n');
	} else
		printf ("NO\n");

	return 0;
}
