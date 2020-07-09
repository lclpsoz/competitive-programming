#include <bits/stdc++.h>
using namespace std;

int t, q;
int ans;
int arr[1050];

int main ()
{
	int w;
	scanf ("%d", &t);
	while (t--) {
		for (int i = 0; i < 1050; i++)
			arr[i] = 0;
		scanf ("%d", &q);
		while (q--) {
			int a, b;
			scanf ("%d %d", &a, &w);
			// Caso w seja valido
			if (w >= 10 && w <= 100) {
				if (arr[a] < 10 || arr[a] > 100)
					arr[a] = w;
				else if (w > arr[a])
					arr[a] = w;
			}
			// Caso w seja invalido
			else if (arr[a] == 0)
				arr[a] = w;
			else if (w > arr[a] && (arr[a] < 10 || arr[a] > 100))
				arr[a] = w;
		}
		ans = 0;
		for (int i = 0; i < 1050; i++) {
			ans += arr[i];
			arr[i] = 0;
		}
		printf ("%d\n", ans);
	}

	return 0;
}
