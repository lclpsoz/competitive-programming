#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e7+100, MAXS = 5e6+10;

int i, j, last;
char str[MAXS];
bool inser;
int qnt, ent;
int seqs[MAXN][4];	//Stores sequences by a 'tree logic', but not using direct expression like 2n+1 in a binary tree
//Pos 0: Value -1 (in that case '\0', that ends a sequence)
//Pos 1: Position of the child in that reference type (in that case '(')
//Pos 2: Position of the child in that reference type (in that case ')')
//If the value is 0, that sequence don't exist, it qnts +1 sequences and add a new child at the end of the array

int bef = -1;
void print(){

	if (bef != last){
		bef = last;

		printf("\n");
		for (i = 0; i <= last; i++){

			printf("%d:\t", i);
			for (j = 0; j < 3; j++)
				printf("%d\t", seqs[i][j]);
			printf("\n");

		}
		printf("\n");
	}
	else
		printf(".");
}

int main (){

	last = 0;	//Marks the last position in the matrix seqs
	qnt = 0;	//Counts amount of unique sequences
	while (scanf("%s", str) != EOF){

		inser = false;
		i = 0;
		j = 0;	//Marks the position to be tested
		do{

			//Save in variable 'ent' position relative of the input in the seqs matrix
			switch (str[i]){
				case '\0': ent = 0; break;
				case '(': ent = 1; break;
				case ')': ent = 2; break;
			}

			if (inser){

				ent ? seqs[last][ent] = ++last : seqs[last][ent] = -1;

			}
			else if (seqs[j][ent] == 0){

				inser = true;
				ent ? seqs[j][ent] = ++last : seqs[j][ent] = -1;

			}
			else if (seqs[j][ent] != -1)
				j = seqs[j][ent];

		} while (str[i++] != '\0');

		if (inser) qnt++;
		//print();

	}

	printf("%d\n", qnt);

	return 0;
}
