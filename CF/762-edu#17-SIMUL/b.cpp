#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

int a, b, c;
int m;
priority_queue<int,vector<int>, greater<int>> usb, ps;

int main ()
{
	scanf ("%d %d %d", &a, &b, &c);
	scanf ("%d", &m);
	char str[100];
	int x;
	for (int i = 0; i < m; i++) {
		scanf ("%d %s", &x, str);
		if (str[0] == 'U')
			usb.push (x);
		else
			ps.push (x);
	}

	long long ans = 0;
	int qnt = 0;
	while (a && usb.size()) {
		ans += usb.top();
		qnt++;
		usb.pop();
		a--;
	}
	while (b && ps.size()) {
		ans += ps.top();
		qnt++;
		ps.pop();
		b--;
	}
	while (c && (usb.size() || ps.size())) {
		c--;
		if (usb.empty()) {
			ans += ps.top();
			ps.pop();
			qnt++;
		}
		else if (ps.empty()) {
			ans += usb.top();
			usb.pop();
			qnt++;
		}
		else if (usb.top() <= ps.top()) {
			ans += usb.top();
			usb.pop();
			qnt++;
		}
		else {
			ans += ps.top();
			ps.pop();
			qnt++;
		}
	}
	printf ("%d %lld\n", qnt, ans);

	return 0;
}
