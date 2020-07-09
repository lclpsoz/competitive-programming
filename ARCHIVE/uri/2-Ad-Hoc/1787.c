#include <stdio.h>
#include <math.h>

int i, j, k;
int qnt, two[30], uri[3], max, max_p, uri_sc[3];

int main (void){

	scanf("%d", &qnt);

	if (qnt)
		for (i = 0; i < 30; i++)
			two[i] = (int) pow(2, i + 1);

	while (qnt){

		for (i = 0; i < qnt; i++){

			scanf("%d %d %d", &uri[0], &uri[1], &uri[2]);

			max = 0;
			for (j = 0; j < 3; j++)
				if (uri[j] > max){

					max = uri[j];
					max_p = j;

				}

			for (j = 0; j < 3; j++)
				if (j != max_p && uri[j] == max)
					max_p = -1;

			//printf("%d: %d\n", max_p, max);
			//printf("URI: %d %d %d\n", uri[0], uri[1], uri[2]);

			for (j = 0; j < 3; j++)
				for (k = 0; uri[j] >= two[k] && k < 30; k++)
					if (uri[j] == two[k]){

						uri_sc[j]++;

						if (max_p == j)
						   uri_sc[j]++;

					}
		}

		//printf("sc: %d %d %d\n", uri_sc[0], uri_sc[1], uri_sc[2]);
		//printf("p: %d\n", max_p);
		max = -1;
		max_p = -2;
		for (i = 0; i < 3; i++)
			if (uri_sc[i] > max){

				max = uri_sc[i];
				max_p = i;

			}

		//printf("p: %d\n", max_p);
		//printf("max: %d\n", max);

		for (i = 0; i < 3; i++){

			//printf("comp: i(%d): %d == %d\n", i, max, uri_sc[i]);
			if (i != max_p && max == uri_sc[i])
				max_p = -1;

			uri_sc[i] = 0;

		}
		//printf("p: %d\n", max_p);

		switch (max_p){

			case -1: printf("URI\n"); break;
			case 0: printf("Uilton\n"); break;
			case 1: printf("Rita\n"); break;
			case 2: printf("Ingred\n"); break;

		}

		scanf("%d", &qnt);
	}

	return 0;
}
