#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5+10;

int n, x, pos, qnt;
int arr[MAXN];

int main ()
{
	scanf ("%d", &n);
	pos = n;
	putchar ('1');
	putchar (' ');
	qnt = 0;
	while (n--) {
		scanf ("%d", &x);
		arr[x] = 1;
		qnt++;
		while (arr[pos]) {
			pos--;
			qnt--;
		}
		printf ("%d", qnt+1);
		if (n)
			putchar (' ');
	}
	putchar ('\n');

	return 0;
}
