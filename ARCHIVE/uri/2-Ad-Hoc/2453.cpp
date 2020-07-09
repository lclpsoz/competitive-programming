#include <bits/stdc++.h>
using namespace std;

char c;

int main (){

	c = getchar();
	while (c != EOF){

		if (c == 'p')
			c = getchar();

		printf("%c", c);

		c = getchar();

	}

	return 0;
}
