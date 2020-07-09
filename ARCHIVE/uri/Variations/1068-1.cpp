//Using stack
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e4+10;

int i;
stack<bool> parent;
char str[MAXS];
bool test;

int main (){

	while (scanf("%s", str) != EOF){

		test = true;
		for (i = 0; i < strlen(str); i++){

			if (str[i] == '(')
				parent.push(1);
			else if (str[i] == ')'){

				if (!parent.empty())
					parent.pop();
				else{

					test = false;
					break;

				}
			}
		}
		if (!parent.empty()) test = false;

		if (test) printf("correct\n");
		else printf("incorrect\n");

		for (i = 0; i < parent.size(); i++)
			parent.pop();

	}

	return 0;
}
