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
	int arr[10];
	int c = 0, f = 0;
	for (int i = 0; i < 6; i++) {
		scanf ("%d", &arr[i]);
		if (i/3 == 0) {
			if (i == 0)
				c += arr[i]*3;
			else if (i == 1)
				c += arr[i];
		} else {
			if (i == 3)
				f += arr[i]*3;
			else if (i == 4)
				f += arr[i];
		}
	}

	if (c == f) {
		if (arr[2] > arr[5])
			printf ("C\n");
		else if (arr[2] < arr[5])
			printf ("F\n");
		else
			printf ("=\n");
	} else if (c > f)
		printf ("C\n");
	else
		printf ("F\n");

	return 0;
}
