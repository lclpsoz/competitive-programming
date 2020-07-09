#include <bits/stdc++.h>
using namespace std;

const int MAXS = 60;

char c;
bool ast, und;

int main (){

	c = getchar();
	while (c != EOF){

		ast = und = false;
		if (c == '\n') c = getchar();
		while (c != '\n' && c != EOF){

			if (c == '*'){

				if (!ast) printf("<b>");
				else printf("</b>");
				ast = !ast;

			}
			else if (c == '_'){

				if (!und) printf("<i>");
				else printf("</i>");
				und = !und;

			}
			else
				printf("%c", c);

			c = getchar();

		}
		printf("\n");

		if (c == '\n') c = getchar();

	}

	return 0;
}
