#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, arr[6], ans;
char c;

int main () {
	scanf ("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		ans = 0;
		for (int j = 0; j < 6; j++) {
			scanf (" %c ", &c);
			if (c == '*')
				arr[j] = 0;
			else
				arr[j] = c-'0';
		}
		if (!arr[0] && !arr[5])
			ans++;
		if (!arr[1] && !arr[3])
			ans++;
		if (!arr[2] && !arr[4])
			ans++;
		if (ans == 0)
			printf ("1\n");
		else if (ans == 1)
			printf ("2\n");
		else if (ans == 2)
			printf ("8\n");
		else if (ans ==3)
			printf ("48\n");

	}
	return 0;
}
