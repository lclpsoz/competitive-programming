#include <stdio.h>

int i;
int n, m;
char act[6];

int main (void){

	scanf("%d %d", &n, &m);

	for (i = 0; i < m; i++){

		scanf("%s", act);
		if (act[0] == 'f')
			n++;
		else
			n--;

	}

	printf("%d\n", n);

	return 0;
}
