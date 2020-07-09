#include <stdio.h>

int i, j;
int qnt, marks[5], mark, marks_qnt;

int main (void){

	scanf("%d", &qnt);

	while (qnt){

		for (j = 0; j < qnt; j++){

			marks_qnt = 0;
			for (i = 0; i < 5; i++){

				scanf("%d", &marks[i]);

				if (marks[i] <= 127){

					mark = i;
					marks_qnt++;

				}
			}

			if (marks_qnt > 1 || !marks_qnt)
				printf("*\n");
			else
				printf("%c\n", 'A' + mark);
		}

		scanf("%d", &qnt);
	}

	return 0;
}
