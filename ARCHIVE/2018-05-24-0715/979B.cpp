#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e5+10;

int n, l;
char a[MAXN];
char b[MAXN];
char c[MAXN];
int a1[300];
int b1[300];
int c1[300];
pair<int, string> ans[4];

int aux (int xx) {
	xx += n;
	if (n == 1 && xx == (l+1))
		xx = l-1;
	else if (xx >= l+1)
		xx = l;

	return xx;
}

int func (int *arr) {
	int maxi = 0;
	for (int i = 'a'; i <= 'z'; i++) {
		maxi = max (maxi, aux (arr[i]));
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		maxi = max (maxi, aux (arr[i]));
	}

	return maxi;
}

int main ()
{
	scanf ("%d", &n);
	scanf ("%s %s %s", a, b, c);
	l = strlen (a);
	for (int i = 0; i < strlen (a); i++) {
		a1[a[i]]++;
		b1[b[i]]++;
		c1[c[i]]++;
	}

	int a2, b2, c2;

	a2 = func (a1);
	b2 = func (b1);
	c2 = func (c1);

	ans[0] = {a2, "Kuro"};
	ans[1] = {b2, "Shiro"};
	ans[2] = {c2, "Katie"};

	sort (ans, ans+3);
	/*printf ("%d %d %d\n", ans[0].x.x, ans[1].x.x, ans[2].x.x);
	cout << ans[0].y << " " << ans[1].y << " " << ans[2].y << "\n";*/
	if (ans[1].x == ans[2].x)
		cout << "Draw\n";
	else
		cout << ans[2].y << '\n';

	return 0;
}
