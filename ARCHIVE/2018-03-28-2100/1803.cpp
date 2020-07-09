#include <bits/stdc++.h>
using namespace std;

int mat[6][100];
int arr[100];

int main ()
{
	char c = ' ';
	int i = 0;
	int j;
	int n = 0;
	while (c != EOF) {
		j = 0;
		while (c = getchar (), c != '\n' && c != EOF)
			mat[i][j++] = c-'0';
		n = max(j, n);
		i++;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
			arr[i] += pow(10, 3-j)*mat[j][i];

	for(int i = 1; i < n-1; i++) {
		int a = 0;
		a = (arr[0]*arr[i] + arr[n-1])%257;
		c = a;
		putchar (c);
	}
	putchar ('\n');


	return 0;
}
