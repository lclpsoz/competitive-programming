#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10;

int i, j;
int val, lst;
int sqrs[101], arr[100];
bool pos[MAXN];
char c;

int main (){

	for (i = 0; i < 101; i++)
		sqrs[i] = i * i;

	lst = 101;
	for (i = 0; i < lst; i++)
		for (j = i; j < lst; j++)
			if ((sqrs[i] + sqrs[j])	<= 1e4+5) pos[sqrs[i] + sqrs[j]] = true;
			else lst = j;

	i = 0;
	c = getchar();
	while (c != EOF){

		if (c >= '0' && c <= '9')
			arr[i++] = c - '0';
		else if (c == '-')
			arr[i++] = -1;
		else{

			i--;
			for (j = 0; i >= 0; i--, j++){

				val += arr[i] * pow(10, j);
				arr[i] = 0;

			}

			if (val >= 0 && val <= 1e4 && pos[val]) printf("YES\n");
			else printf("NO\n");
			val = 0;
			i = 0;

		}

		c = getchar();

	}

	return 0;
}

