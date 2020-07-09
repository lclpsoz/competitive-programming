#include <bits/stdc++.h>
using namespace std;

const int MAXN = 101;

int i;
int n;
int arr[MAXN];
char c, cs[3];

int main (){

	for (i = 1; i < MAXN; i++)
		arr[i] = arr[i-1] + i*i;

	c = getchar();
	i = 0;
	while (c != '\n'){

		cs[i++] = c;
		c = getchar();

	}
	if (i == 1)
		n = cs[0] - '0';
	else if (i == 2){

		n += (cs[0] - '0') * 10;
		n += (cs[1] - '0') * 1;

	}
	else if (i == 3){

		n += (cs[0] - '0') * 100;
		n += (cs[1] - '0') * 10;
		n += (cs[2] - '0') * 1;

	}
	while (n){

		printf("%d\n", arr[n]);

		c = getchar();
		i = 0;
		while (c != '\n'){

			cs[i++] = c;
			c = getchar();

		}
		if (i == 1)
			n = cs[0] - '0';
		else if (i == 2){

			n = (cs[0] - '0') * 10;
			n += (cs[1] - '0') * 1;

		}
		else if (i == 3){

			n = (cs[0] - '0') * 100;
			n += (cs[1] - '0') * 10;
			n += (cs[2] - '0') * 1;

		}

	}

	return 0;
}
