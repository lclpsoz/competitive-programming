#include <bits/stdc++.h>
using namespace std;

typedef struct _numb{

	char str[15];
	int size;

} Numb;



int i, j, k;
Numb a, b;
int val, qnt, carry, big;
char res[15];

int main (){

	scanf("%s %s", a.str, b.str);
	while (a.str[0] != '0' || b.str[0] != '0'){

		qnt = 0;
		carry = 0;
		a.size = strlen(a.str);
		b.size = strlen(b.str);

		if (a.size > b.size) big = a.size;
		else big = b.size;

		//printf("\n%s %s\n", a.str, b.str);
		for (i = a.size-1, j = b.size-1, k = big; i >= 0 || j >= 0; i--, j--, k--){

			if (j >= 0 && i >= 0) val = carry + a.str[i]-'0' + b.str[j]-'0';
			else if (i >= 0) val = carry + a.str[i]-'0';
			else if (j >= 0) val = carry + b.str[j]-'0';
			//printf("%d\n", val);
			if (val > 9){

				qnt++;
				res[k] = val - 10 + '0';
				carry = 1;


			}
			else{

				res[k] = val;
				carry = 0;

			}
		}

		if (qnt == 0) printf("No carry operation.\n");
		else if (qnt == 1) printf("%d carry operation.\n", qnt);
		else printf("%d carry operations.\n", qnt);
		scanf("%s %s", a.str, b.str);

	}

	return 0;
}
