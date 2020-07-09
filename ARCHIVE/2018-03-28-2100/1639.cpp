#include <bits/stdc++.h>
using namespace std;


int i, j;
int a, ans;
int arr[10010];
bool check[10010];

int main ()
{
	for (i = 1; i < 10010; i++) {
		a = i;
		ans = 0;
		while (check[a] == false) {
			ans++;
			check[a] = true;
			a *= a;
			a /= 100;
			a %= 10000;
		}
		arr[i] = ans;
		for (j = 0; j < 10010; j++)
			check[j] = false;
	}
	while (scanf ("%d", &a), a)
		printf ("%d\n", arr[a]);
	return 0;
}
