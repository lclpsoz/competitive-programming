#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int arr[110];

int main ()
{
	int n;
	scanf ("%d", &n);
	int ones = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		if (arr[i] == 1) ones++;
	}

	int ans = ones;
	int aux;
	if (ones < n) {
		for (int i = 0; i < n; i++) {
			aux = ones;
			for (int j = i; j < n; j++) {
				if (arr[j] == 0)
					aux++;
				else
					aux--;
				ans = max (ans, aux);
			}
		}
	}
	else
		ans--;
	printf ("%d\n", ans);


	return 0;
}
