#include <bits/stdc++.h>
using namespace std;

int n;
int x, y;
int num;
int arr[105];

int main ()
{
	while (scanf ("%d", &n) != EOF) {
		for (int i = 0; i < 105; i++)
			arr[i] = 0;
		while (n--) {
			scanf ("%d %d", &x, &y);
			for (int i = x; i <= y; i++)
				arr[i]++;
		}
		scanf ("%d", &num);
		int st = 0;
		int en = 0;
		if (arr[num]) {
			for (int i = 1; i < num; i++)
				st += arr[i];
			en = st+arr[num]-1;
			printf ("%d found from %d to %d\n", num, st, en);
		}
		else
			printf ("%d not found\n", num);
	}

	return 0;
}
