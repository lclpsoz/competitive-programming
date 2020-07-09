#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
pair<int, string> arr[110];
char str[110];


int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%s", str);
		arr[i] = {strlen (str), str};
	}
	sort (arr, arr+n);

	bool ans = true;
	for (int i = n-1; i >= 0; i--) {
		for (int j = i-1; j >= 0; j--) {
			if (arr[i].y.find (arr[j].y) == string::npos) {
				ans = false;
				break;
			}
		}
	}

	if (ans) {
		printf ("YES\n");
		for (int i = 0; i < n; i++)
			cout << arr[i].y << '\n';
	} else
		printf ("NO\n");

	return 0;
}
