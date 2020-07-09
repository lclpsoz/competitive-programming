#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e5;

int i, j;
int qnt, size;
char str[MAXS], c;
stack<char> exp, opr, par; //Expression, Operation, Parenthesis

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s", str);
		size = strlen(str);

		for (j = 0; j < size; j++){

			c = str[i];
			if (c == '+' || c == '-' || c == '*' || c == '^')
				opr.push(c);
			else if (c == '('){
				if (!opr.empty()){

					par.push(opr.top());
					opr.pop();

				}
			}
			else if (c == ')'){
				while (!par.empty()){

					exp.push(par.top());
					par.pop();

				}
			}
			else if (c == '/'){



			}




		}
	}

	return 0;
}
