#include <bits/stdc++.h>
using namespace std;

int i;
int ans;
char str[9][40] = {"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};
int main ()
{
	int x;
	for (i = 0; i < 9; i++) {
		scanf ("%d", &x);
		ans += x;
	}
	printf ("%s\n", str[(ans-1)%9]);
	return 0;
}
