#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;
const int INF = 1e9;

int n, m;
int x;
vector<int> vec1, vec2;

int main ()
{
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		vec1.pb (x);
	}
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		vec2.pb (x);
	}

	int a, b;
	for (int &v : vec1) {
		vec2.lower_bound (v);
	}

	return 0;
}
