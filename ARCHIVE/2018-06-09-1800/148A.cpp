#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int arr[6];
int d;

int main ()
{
	for (int i = 0; i < 4; i++)
		scanf ("%d", &arr[i]);
	scanf ("%d", &d);

	int ans = 0;
	for (int i = 1; i <= d; i++)
		for (int j = 0; j < 4; j++)
			if (i % arr[j] == 0) {
				ans++;
				break;
			}

	cout << ans << '\n';

	return 0;
}
