#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e8+100, MAXS = 1e7+10;

int i, j, k;
int last, qnt;
bool uniq;
char str[MAXS];
int seqs[MAXN][4];

int main (){

	last = 0;
	qnt = 0;
	while (scanf("%s", str) != EOF){

		uniq = false;
		i = 0;	//Position in the string that is being compared to
		j = 0;	//Line in the matrix that is being compared to

		do{

			switch (str[i]){
				case '\0': k = 0; break;
				case '(': k = 1; break;
				case ')': k = 2; break;
			}

			if (seqs[j][k] > 0){

				j = seqs[j][k];

			}
			else if (seqs[j][k] == 0){

				k ? seqs[j][k] = ++last : seqs[j][k]  = -1;
				j = last;
				uniq = true;

			}

		} while (str[i++] != '\0');

		if (uniq) qnt++;

	}

	printf("%d\n", qnt);

	return 0;
}
