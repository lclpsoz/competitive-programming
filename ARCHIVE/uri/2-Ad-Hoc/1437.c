#include <stdio.h>

int i;
int qnt, dir;
char mov, ori[4] = {'N', 'L', 'S', 'O'};

int main (void){

	scanf("%d", &qnt);

	while (qnt){

		dir = 0;
		for (i = 0; i < qnt; i++){

			scanf(" %c", &mov);

			if (mov == 'E')
				dir--;
			else
				dir++;

			if (dir == -1)
				dir = 3;
			else if (dir == 4)
				dir = 0;

		}

		printf("%c\n", ori[dir]);
		scanf("%d", &qnt);

	}

	return 0;
}
