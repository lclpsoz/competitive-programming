#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

char str[MAXN];

int main ()
{
	int n;
	scanf ("%d", &n);
	scanf ("%s", str);
	bool test;
	for (int i = n/2; i > 0; i--) {
		test = true;
		for (int j = 0; j < i; j++)
			if (str[j] != str[j+i]) {
				test = false;
				break;
			}
		if (test) {
			n-= i-1;
			break;
		}
	}

	printf ("%d\n", n);


	return 0;
}
