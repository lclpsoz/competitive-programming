#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e7, MOD = 131071;

int j;
int i;
int size, rest, resp;
char aux[MAXS], str[MAXS];

int main (){
	char c;
	c = getchar ();
	while (c != EOF){
		i = 0;
		while (c != '#') {
			if (c !=  '\n')
				str[i++] = c;
			c = getchar ();
		}
		getchar (); // '\n'
		c = getchar ();
		resp = 0;


		size = strlen(str);
		//printf("%s\n", str);
		//printf("s: %d\n", size);

		rest = 1;
		if (str[size-1]-'0') resp += rest;
		str[size-1] = '\0';
		for (i = size-2; i >= 0; i--){

			rest *= 2;
			rest %= MOD;

			if (str[i]-'0'){

			   resp += rest;
			   resp %= MOD;

			}
			str[i] = '\0';
			//printf("%d %d\n", rest, resp);
		}

		if (resp) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
