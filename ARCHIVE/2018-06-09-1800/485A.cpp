#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

const int MAXN = 1e5+10;

int a, m;
bool arr[MAXN];

int main ()
{
	scanf ("%d %d", &a, &m);

	while (a && !arr[a]) {
		arr[a] = true;
		a = (a+a)%m;
	}

	printf ("%s\n", !a ? "Yes" : "No");

	return 0;
}
