#include <bits/stdc++.h>
using namespace std;

char arr[12][105], aux;
int p = 0;

void adic (char c)
{
	arr[1][p++] = c;
	arr[1][p] = '\0';
}

int proc (int i, char c)
{
	for (int j = 0; arr[i][j] != '\0'; j++)
		if (arr[i][j] == c)
			return j;
}

void func (int i, int ant)
{
	printf ("%d %d\n", i, ant);
	int j = 0;
	while (arr[i][j] == '-') j++;

	if (arr[i][j] != '\0') {
		aux = arr[i][j];
		arr[i][j] = '-';
		if (aux != '1' && aux != ant+'0')
			func (aux-'0', i);
		else if (aux == '1') {
			// printf (">1\n");
			adic ('0'+i);
			func (i, ant);
		}
		else if (aux == ant+'0')
			func (i, ant);
	}
}

int main ()
{
	int n;
	while (scanf ("%d", &n), n > -1) {
		p = 0;
		arr[1][0] = '\0';
		for (int i = 0; i < n-1; i++)
			scanf ("%s", arr[i+2]);
		func (2, 10);
		printf ("%s\n", arr[1]);
		 printf ("\n-----------------------------------------------\n\n", arr[1]);
	}
	return 0;
}
