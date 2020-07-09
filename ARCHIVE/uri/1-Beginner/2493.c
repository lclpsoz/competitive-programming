#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i, j;
int x;
char o;
int expr_qnt, expr[50][3], pl_expr[50], pl_wrong_qnt, opr_sts[3];
char pl_name[50][51], pl_opr[50], pl_wrong[50][51];

void lex_order (char str[50][51], int qnt, int str_size){

    int i, j;
    char *aux;

    aux = (char*) malloc((str_size + 1) * sizeof(char));

    for (i = 0; i < qnt - 1; i++)
        for (j = i + 1; j < qnt; j++)
            if (strcmp(str[i], str[j]) > 0){

                strcpy(aux, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], aux);

            }
}

int main (void){

	while(scanf("%d", &expr_qnt) != EOF){

		for (i = 0; i < expr_qnt; i++)
			scanf("%d %d=%d", &expr[i][0], &expr[i][1], &expr[i][2]);

		for (i = 0; i < expr_qnt; i++){

			scanf("%s %d %c", pl_name[i], &pl_expr[i], &pl_opr[i]);
			pl_expr[i]--;	//To match the index in the array expr

		}



		//Take the wrong players
		for (i = 0; i < expr_qnt; i++){

			//Make the code smaller:
			x = pl_expr[i];
			o = pl_opr[i];

			//If the operation is not possible, the opr_sts index based on (+ - *) will be 1
			if (expr[x][0] + expr[x][1] != expr[x][2])
				opr_sts[0] = 1;
			if (expr[x][0] - expr[x][1] != expr[x][2])
				opr_sts[1] = 1;
			if (expr[x][0] * expr[x][1] != expr[x][2])
				opr_sts[2] = 1;

			if((o == '+' && opr_sts[0]) || (o == '-' && opr_sts[1]) || (o == '*' && opr_sts[2]) || (o == 'I' && (!opr_sts[0] || !opr_sts[1] || !opr_sts[2]))){

				strcpy(pl_wrong[pl_wrong_qnt], pl_name[i]);
				pl_wrong_qnt++;

			}

			for (j = 0; j < 3; j ++)
				opr_sts[j] = 0;
		}

		if (pl_wrong_qnt == expr_qnt)
			printf("None Shall Pass!\n");
		else if (pl_wrong_qnt == 0)
			printf("You Shall All Pass!\n");
		else{

			lex_order(pl_wrong, pl_wrong_qnt, 50);

			for (i = 0; i < pl_wrong_qnt - 1; i++)
				printf("%s ", pl_wrong[i]);

			printf("%s\n", pl_wrong[i]);

		}

		pl_wrong_qnt = 0;
	}

	return 0;
}
