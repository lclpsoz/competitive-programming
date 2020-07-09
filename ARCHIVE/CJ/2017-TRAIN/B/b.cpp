#include <bits/stdc++.h>
using namespace std;

char arr[20];

void func (int i)
{
	if (arr[i+1] != '\0') {
		if (arr[i] <= arr[i+1])
			func (i+1);
		if (arr[i] > arr[i+1]) {
			arr[i]--;
			for (int j = i+1; arr[j] != '\0'; j++)
				arr[j] = '9';
		}
	}
}

int main ()
{
	int t;
	long long n;
	scanf ("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf ("%s", arr);
		func (0);
		sscanf (arr, "%lld", &n);
		printf ("Case #%d: %lld\n", i, n);
	}

	return 0;
}
