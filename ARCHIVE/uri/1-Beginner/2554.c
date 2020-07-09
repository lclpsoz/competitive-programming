#include <stdio.h>

int i, j;
int guests, dates;
int date[3];
int presence, test_guest, test_print;	//Boolean

int main (void){

	while (scanf("%d %d", &guests, &dates) != EOF){

		test_print = 1;
		for (i = 0; i < dates; i++){

			scanf("%d/%d/%d", &date[0], &date[1], &date[2]);

			test_guest = 1;
			for (j = 0; j < guests; j++){

				scanf("%d", &presence);

				if (!presence && test_guest == 1)
					test_guest = 0;

			}

			if (test_guest && test_print){

				printf("%d/%d/%d\n", date[0], date[1], date[2]);
				test_print = 0;

			}
		}

		if (test_print)
			printf("Pizza antes de FdI\n");

	}

	return 0;
}
