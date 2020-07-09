#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;

int arr[MAXN];
int sq[MAXN];
int sq_v;
int n;

int check_left (int x)
{
	int i;
	for (i = x-1; i>=0 && i%sq_v != (sq_v-1); i--) {
		if (arr[i] > arr[x])
			return i+1;
	}
	if (i%sq_v == (sq_v-1))
		for (i = i/sq_v; i>=0; i--) {
			// printf ("i: %d\n", i);
			if (sq[i] > arr[x]) {
				int j = (i*sq_v)+sq_v-1;
				/*printf ("arr[x] = %d\n", arr[x]);
				printf ("<j: %d\n", j);
				printf ("arr[j] = %d\n", arr[j]);*/
				while (arr[j] <= arr[x]) j--;
				// printf (">j: %d\n", j);
				return j+1;
			}
		}
	return 0;
}

int check_right (int x)
{
	int i;
	for (i = x+1; i < n && i%sq_v != 0; i++) {
		if (arr[i] > arr[x])
			return i+1;
	}
	if (i%sq_v == 0)
		for (i = i/sq_v; i < n; i++) {
			// printf ("i: %d\n", i);
			if (sq[i] > arr[x]) {
				int j = i*sq_v;
				/*printf ("arr[x] = %d\n", arr[x]);
				printf ("<j: %d\n", j);
				printf ("arr[j] = %d\n", arr[j]);*/
				while (arr[j] <= arr[x]) j++;
				// printf (">j: %d\n", j);
				return j+1;
			}
		}
	return 0;
}

int main ()
{
	scanf ("%d", &n);
	sq_v = sqrt (n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &arr[i]);
		sq[i/sq_v] = max(sq[i/sq_v], arr[i]);
	}
	/*for (int i = 0; i < n; i++)
		printf ("%d ", sq[i]);
	putchar ('\n');*/
	/* printf("LEFT:\n");
	for (int i = 0; i < n; i++)
		printf ("%d(%d): %d\n", i, arr[i], check_left (i));
	printf("RIGHT:\n");
	for (int i = 0; i < n; i++)
		printf ("%d(%d): %d\n", i, arr[i], check_right (i));*/


	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, check_left(i)*check_right(i));
	printf ("%d\n", ans);

	return 0;
}
