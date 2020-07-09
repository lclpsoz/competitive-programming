#include <bits/stdc++.h>
using namespace std;

int n;
char arr[1000];
string str, ans_s;
int a, b, c;
int a1, b1, c1;

int main ()
{
	scanf ("%d", &n);
	scanf ("%s %d %d %d", arr, &a, &b, &c);
	ans_s = arr;
	a1 = a;
	b1 = b;
	c1 = c;
	for (int i = 1; i < n; i++) {
		scanf ("%s %d %d %d", arr, &a, &b, &c);
		str = arr;
		if (a > a1) {
			ans_s = arr;
			a1 = a;
			b1 = b;
			c1 = c;
		}
		else if (a == a1 && b > b1) {
			ans_s = arr;
			a1 = a;
			b1 = b;
			c1 = c;
		}
		else if (a == a1 && b == b1 && c < c1) {
			ans_s = arr;
			a1 = a;
			b1 = b;
			c1 = c;
		}
		else if (a == a1 && b == b1 && c == c1 && str < ans_s) {
			ans_s = arr;
			a1 = a;
			b1 = b;
			c1 = c;
		}
	}
	cout << ans_s << '\n';
	return 0;
}
