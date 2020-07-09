#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;

int i;
int size;
char str[MAXN], c;
bool test;

int main (){

	scanf(" %[^\n]", str);
	while (str[0] != '*'){

		size = strlen(str);
		test = true;
		for (i = 0; i < size; i++){

			if (!i) c = tolower(str[0]);
			else if (str[i-1] == ' ' && tolower(str[i]) != c)
				test = false;

		}

		if (test) puts("Y");
		else puts("N");

		scanf(" %[^\n]", str);
	}


	return 0;
}
