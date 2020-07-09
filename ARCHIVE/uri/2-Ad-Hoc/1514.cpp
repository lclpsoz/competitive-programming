#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int i, j;
int qnt_peop, qnt_q, ans, aux, val;
int ques[MAXN];
bool a, b, c, d;

int main (){

	scanf("%d %d", &qnt_peop, &qnt_q);
	while (qnt_peop || qnt_q){

		a = b = c = d = true;
		for (i = 0; i < qnt_peop; i++){

			aux = 0;
			for (j = 0; j < qnt_q; j++){

				scanf("%d", &val);
				if (val){

					aux++;
					ques[j]++;

				}
			}
			if (aux == qnt_q) a = false;
			if (!aux) d = false;

		}

		for (i = 0; i < qnt_q; i++){

			if (!ques[i]) b = false;
			if (ques[i] == qnt_peop) c = false;
			ques[i] = 0;

		}

		printf("%d\n", a+b+c+d);


		scanf("%d %d", &qnt_peop, &qnt_q);
	}

	return 0;
}
