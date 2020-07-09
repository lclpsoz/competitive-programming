#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
const int MAXQ = 320;

int arr[MAXN];
int sq[MAXQ][4]; // 0 → true value | 1→qnt - | 2→qnt of 0 | 3→qnt of +
int n, k;
char c;
int a, b, ax;

void upd (int i, int v)
{
	if (arr[i] < 0)
		sq[i/ax][1]--;
	else if (arr[i] == 0)
		sq[i/ax][2]--;
	else
		sq[i/ax][3]--;

	arr[i] = v;
	if (arr[i] < 0) {
		sq[i/ax][1]++;
		arr[i] = -1;
	}
	else if (arr[i] == 0)
		sq[i/ax][2]++;
	else {
		sq[i/ax][3]++;
		arr[i] = 1;
	}

	if (sq[i/ax][2])
		sq[i/ax][0] = 0;
	else if (sq[i/ax][1]%2 == 1)
		sq[i/ax][0] = -1;
	else
		sq[i/ax][0] = +1;
}

int main ()
{
	while (scanf ("%d %d", &n, &k) != EOF) {
		ax = sqrt (n);
		for (int i = 0; i < n; i++)
			for (int j = 1; j < 4; j++)
				sq[i/ax][j] = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%d", &arr[i]);
			if (arr[i] < 0) {
				sq[i/ax][1]++;
				arr[i] = -1;
			}
			else if (arr[i] == 0)
				sq[i/ax][2]++;
			else {
				sq[i/ax][3]++;
				arr[i] = 1;
			}
		}
		for (int i = 0; i < n; i+=ax) {
			if (sq[i/ax][2])
				sq[i/ax][0] = 0;
			else if (sq[i/ax][1]%2 == 1)
				sq[i/ax][0] = -1;
			else
				sq[i/ax][0] = +1;
		}

		while (k--) {
			scanf (" %c %d %d", &c, &a, &b);
			if (c == 'C')
				upd (a-1, b);
			else {
				int ans = 1;
				a--;
				while (a < b && a%ax)
					ans *= arr[a++];
				while (a < b && (a+ax) < b) {
					ans *= sq[a/ax][0];
					a += ax;
				}
				while (a < b)
					ans *= arr[a++];

				if (ans < 0)
					putchar ('-');
				else if (ans == 0)
					putchar ('0');
				else
					putchar ('+');
			}
		}
		putchar ('\n');
	}

	return 0;
}
