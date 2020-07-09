#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n;
int arr[10];

bool func () {
	memset (arr, 0, sizeof (arr));
	int x = n;
	while (x) {
		if (arr[x%10]) return false;
		arr[x%10] = true;
		x/=10;
	}
	return 1;
}

int main ()
{
	scanf ("%d", &n);
	n++;
	while (!func ()) n++;

	printf ("%d\n", n);

	return 0;
}
