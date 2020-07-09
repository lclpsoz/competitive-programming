#include <bits/stdc++.h>
using namespace std;

const int MAXS = 4e4;

int i;
int qnt, bef, now, ans;
char c, d, str[20];
bool spaces;

int main ()
{
	scanf("%s ", str);
	d = str[0];
	while (d-'0') {
		ans = 0;
		spaces = true;
		while (spaces) {
			ans++;
			spaces = false;
			c = getchar();
			i = 0;
			d = '&';
			while (c != '\n') {
				if (c == ' ') {
					spaces = true;
					i = 0;
				}
				else if (d == '&')
					d = c;
				c = getchar ();
			}
		}
		printf("%d\n", --ans);
	}

	return 0;
}
