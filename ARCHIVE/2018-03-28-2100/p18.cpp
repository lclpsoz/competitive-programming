#include <bits/stdc++.h>
using namespace std;

int n, big, small;
char str[20], c;
bool liar;

int main (){

	liar = false;
	big = 11;
	small = 0;
	while (scanf("%d", &n), n){

		scanf(" %[^\n] ", str);
		c = str[strlen(str)-1];
		if (c == 'h'){

			if (n <= small+1)
				liar = true;

			if (n < big)
				big = n;

		}
		else if (c == 'w'){

			if (n >= big-1)
				liar = true;

			if (n > small)
				small = n;

		}
		else{

			if (n <= small || n >= big)
				liar = true;

			if (liar)
				printf("Stan is dishonest\n");
			else
				printf("Stan may be honest\n");

			big = 11;
			small = 0;
			liar = false;

		}
		//printf("%d\n", liar);

	}
	return 0;
}
