#include <stdio.h>

int i;
int amnt, out;
char raj[7], shel[7];

int main (void){

	scanf("%d", &amnt);

	for (i = 1; i <= amnt; i++){

		scanf("%s %s", shel, raj);
		if (shel[2] == raj[2])
			printf("Caso #%d: De novo!\n", i);
		else{

			switch (shel[2]){
				case 'd':
					if (raj[2] == 'g' || raj[2] == 's')
						out = 1;
					break;
				case 'p':
					if (raj[2] == 'd' || raj[2] == 'o')
						out = 1;
					break;
				case 's':
					if (raj[2] == 'p' || raj[2] == 'g')
						out = 1;
					break;
				case 'g':
					if (raj[2] == 'o' || raj[2] == 'p')
						out = 1;
					break;
				case 'o':
					if (raj[2] == 's' || raj[2] == 'd')
						out = 1;
					break;
			}

		if (out == 0)
			printf("Caso #%d: Raj trapaceou!\n", i);
		else
			printf("Caso #%d: Bazinga!\n", i);

		out = 0;

		}
	}

	return 0;
}
