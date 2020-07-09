#include <bits/stdc++.h>
using namespace std;

int t;
int n;
char arr[50];
int vals[50];
int ans, x, sum;

bool func (int pos)
{
	pos++;
	// printf ("SUM: %d\n", sum);
	while (pos < strlen(arr) && sum > n) {
		if (vals[pos] > 0) {
			sum -= vals[pos]/2;
			vals[pos-1] = vals[pos]/2;
			vals[pos] = -1;
			ans++;
		}
		pos++;
	}
	// printf ("SUM: %d\n", sum);
	return sum <= n;
}

int main ()
{
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%d %s", &n, arr);
		sum = 0;
		for (int i = 0; i < strlen(arr); i++)
			if (arr[i] == 'S')
				sum++;
		ans = 0;
		if (sum > n)
			ans = -1;
		else {
			int x = 1;
			sum = 0;
			for (int i = 0; arr[i] != '\0'; i++) {
				if (arr[i] == 'S') {
					vals[i] = x;
					sum += x;
				}
				else {
					vals[i] = -1;
					x *= 2;
				}
			}
			/*for (int i = 0; arr[i] != '\0'; i++)
				printf ("%d ", vals[i]);
			putchar ('\n');*/
			if (sum <= n)
				ans = 0;
			else {
				int i = strlen(arr)-2;
				while (arr[i] != 'C' || arr[i+1] != 'S') i--;
				while (!func (i)) {
					// printf ("%d\n", i);
					i--;
					/*for (int i = 0; arr[i] != '\0'; i++)
						printf ("%d ", vals[i]);
					putchar ('\n');*/
					while (vals[i] != -1 || vals[i+1] == -1) i--;
				}
			}
		}



		printf ("Case #%d: ", i);
		if (ans == -1)
			printf ("IMPOSSIBLE\n");
		else
			printf ("%d\n", ans);
	}

	return 0;
}
