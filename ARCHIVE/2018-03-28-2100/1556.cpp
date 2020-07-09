#include <cstdio>
#include <cstring>

char str[1010];
int mat[1002][30], arr[30];

void alg (char *str_aux, int lst, int pos) {
	int i;
	str_aux[lst] = str[pos-1];
	str_aux[++lst] = '\0';
	printf ("%s", str_aux);
	putchar ('\n');
	for (i = 1; i <= ('z'-'a'+1); i++)
		if (mat[pos][i])
			alg (str_aux, lst, mat[pos][i]);
}

int main ()
{
	int i, j;
	int x;
	char str_aux[1010];
	while (scanf (" %[^\n]", str) != EOF) {
		arr[str[0]-'a'+1] = 1;
		for (i = 1; i < strlen(str); i++) {
			x = str[i]-'a'+1; //(a, 1), (b, 2), (c, 3), ...
			for (j = i-1; j >= 0 && !mat[j+1][x]; j--)
				mat[j+1][x] = i+1;
			if (!arr[x])
				arr[x] = i+1;
		}
		/*for (i = 1; i <= 5; i++)
			printf ("%d ", arr[i]);
		putchar ('\n');
		for (i = 1; i < 4; i++) {
			for (j = 1; j < 5; j++)
				printf ("%d ", mat[i][j]);
			putchar ('\n');
		}*/
		for (i = 1; i <= ('z'-'a'+1); i++)
			if (arr[i]) {
				alg (str_aux, 0, arr[i]);
				arr[i] = 0;
			}
		putchar ('\n');
		for (i = 0; i <= 1000; i++)
			for (j = 1; j < 28; j++)
				mat[i][j] = 0;
	}
	return 0;
}
