#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int arr[3];

int main ()
{
	int x;
	int n;
	scanf ("%d", &n);
	while (n--) {
		scanf ("%d", &x);
		x/=25;
		if (x == 1) arr[0]++;
		else if (x == 2) {
			arr[0]--;
			arr[1]++;
		} else {
			arr[2]++;
			if (arr[1]) {
				arr[1]--;
				arr[0]--;
			} else {
				arr[0]-=3;
			}
		}
		if (arr[0] < 0 || arr[1] < 0) {
			printf ("NO\n");
			return 0;
		}
	}

	printf ("YES\n");

	return 0;
}
