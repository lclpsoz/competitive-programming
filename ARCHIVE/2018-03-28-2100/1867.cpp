#include <bits/stdc++.h>
using namespace std;

char a[150], b[150];
int a1, b1, aux;

int main ()
{
	while (scanf (" %s %s", a, b), (a[0]-'0') || (b[0]-'0')) {
		a1 = b1 = 0;
		for (int i = 0; i < strlen(a); i++)
			a1 += a[i]-'0';
		for (int i = 0; i < strlen(b); i++)
			b1 += b[i]-'0';
		aux = 0;
		while (a1 > 9) {
			while (a1 > 0) {
				aux += a1%10;
				a1 /= 10;
			}
			a1 = aux;
		}
		aux = 0;
		while (b1 > 9) {
			while (b1 > 0) {
				aux += b1%10;
				b1 /= 10;
			}
			b1 = aux;
		}
		if (a1 > b1)
			printf ("1\n");
		else if (b1 > a1)
			printf ("2\n");
		else
			printf ("0\n");
	}
	return 0;
}
