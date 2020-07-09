#include <bits/stdc++.h>
using namespace std;

int i;
int choosen, size, equals, masc, fem;
char c;

int main (){

	i = 0;
	c = getchar();
	while (c != EOF){

		fem = masc = equals = 0;
		choosen = (c - '0') * 10;
		c = getchar();
		choosen += c - '0';
		c = getchar(); //Will be a \n
		c = getchar();
		while (c != '\n'){

			if (c == ' ') c = getchar();
			size = (c - '0') * 10;
			c = getchar();
			size += (c - '0');
			c = getchar(); //A ' ' char
			c = getchar();
			if (size == choosen){

				c == 'F' ? fem++:masc++;
				equals++;

			}

			c = getchar();
		}

		if (i > 0) printf("\n");
		printf("Caso %d:\n", ++i);
		printf("Pares Iguais: %d\n", equals);
		printf("F: %d\n", fem);
		printf("M: %d\n", masc);

		c = getchar(); //Maybe a new number or a EOF

	}

	return 0;
}
