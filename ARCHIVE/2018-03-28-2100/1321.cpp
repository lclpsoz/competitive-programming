#include <bits/stdc++.h>
using namespace std;

int i;
bool cards[55];
int arr[5], ans;

bool ord (const int &a, const int &b) {
	return abs(a) < abs(b);
}

int main ()
{
	for (i = 0; i < 5; i++) {
		scanf ("%d", &arr[i]);
		cards[arr[i]] = true;
		if (i < 3)
			arr[i] *= -1;
	}
	while (arr[0]) {
		sort (arr, arr+5, ord);
		if ((arr[4] < 0 && arr[3] < 0) || (arr[4] < 0 && arr[2] < 0))
			printf ("-1\n");
		else {
			if (arr[4] > 0) {
				if (arr[3] > 0) // - - - + +
					ans = 1;
				else if (arr[2] > 0) // - - + - +
					ans = arr[1];
				else // - + - - + or + - - - +
					ans = arr[3];
			}
			else // - - + + -
				ans = arr[1];
			ans = abs(ans);
			while (cards[ans] && ans < 53)
				ans++;
			if (ans == 53)
				ans = -1;
			printf ("%d\n", ans);
		}
		for (i = 1; i < 53; i++)
			cards[i] = false;
		for (i = 0; i < 5; i++) {
			scanf ("%d", &arr[i]);
			cards[arr[i]] = true;
			if (i < 3)
				arr[i] *= -1;
		}
	}

	return 0;
}
