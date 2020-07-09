#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;
typedef long long ll;

int n;
stack<int> a, b;
bool arr[1050];

int main ()
{
	scanf ("%d", &n);
	int x;
	while (n--) {
		scanf ("%d", &x);
		a.push (x);
	}
	while (!a.empty()) {
		if (!arr[a.top()]) {
			arr[a.top()] = true;
			b.push (a.top());
		}
		a.pop();
	}

	printf ("%ld\n", b.size());
	while (!b.empty()) {
		printf ("%d ", b.top());
		b.pop();
	}
	putchar ('\n');

	return 0;
}
