#include <bits/stdc++.h>
using namespace std;

int n;
int arr[510];

int main ()
{
	while (scanf ("%d", &n), n > -1) {
		for (int i = 1; i <= n; i++)
			scanf ("%d", &arr[i]);

		int i = 1;
		while (i <= n) {
			if (arr[i] == i) {
				arr[i] = 0;
				for (int j = 1; j < i; j++)
					arr[j]++;
				i = 1;
			}
			else
				i++;
		}

		bool test = true;
		for (i = 1; i <= n; i++) {
			if (arr[i])
				test = false;
			arr[i] = 0;
		}
		test ? puts("S") : puts("N");
	}

	return 0;
}
