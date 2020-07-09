#include <bits/stdc++.h>
using namespace std;

int arr[4];

int mdc (int a, int b) {
	if (!a)
		return b;
	else
		mdc (b%a, a);
}

int mmc (int a, int b) {
	return (a*b)/mdc(a,b);
}

int main ()
{
	for (int i = 0; i < 4; i++)
		scanf ("%d", &arr[i]);
	if (arr[1] == arr[3]) {
		arr[0] += arr[2];
		printf ("%d %d\n", arr[0]/(mdc(arr[0], arr[1])), arr[1]/mdc(arr[0], arr[1]));

	}
	else {
		int d = mmc (arr[1], arr[3]);
		arr[0] *= d/arr[1];
		arr[2] *= d/arr[3];
		arr[0] += arr[2];
		int c = mdc (arr[0], d);
		arr[0] /= c;
		d /= c;
		printf ("%d %d\n", arr[0], d);
	}

	return 0;
}
