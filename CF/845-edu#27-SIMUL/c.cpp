#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int n;
int tv1, tv2;
vector<pii> vec;

int main ()
{
	scanf ("%d", &n);
	int a, b;
	while (n--) {
		scanf ("%d %d", &a, &b);
		vec.pb ({a, b});
	}
	sort (vec.begin(), vec.end());


	bool test = true;
	for (pii p : vec) {
		if (p.x >= tv1)
			tv1 = p.y+1;
		else if (p.x >= tv2)
			tv2 = p.y+1;
		else {
			test = false;
			break;
		}
	}

	printf ("%s\n", test ? "YES" : "NO");

	return 0;
}
