#include <bits/stdc++.h>
using namespace std;

char c;
char val1[100], val2[100];
long long unsigned var1, var2;
int dec1, dec2;
char str[200];
char cpf[22];

int main ()
{
	cpf[11] = '\0';
	c = getchar();
	int i = 0;
	while (c != '\n'){
		if (c >= '0' && c <= '9' || c == '.')
			str[i++] = c;
		c = getchar();
	}
	str[i++] = ' ';
	c = getchar();
	while (c != '\n'){
		if (c >= '0' && c <= '9' || c == '.')
			str[i++] = c;
		c = getchar();
	}
	str[i] = '\0';
	printf ("cpf ");
	int n = 0;
	for (i = 0; n < 11 && i < strlen(str); i++)
		if (str[i] >= '0' && str[i] <= '9') {
			putchar (str[i]);
			n++;
		}
	putchar ('\n');
	int ponto = 0;
	int j = 0;
	for (;i < strlen(str) && str[i] != ' '; i++) {
		if (str[i] == '.')
			ponto++;
		if (!ponto && str[i] >= '0' && str[i] <= '9')
			val1[j++] = str[i];
		if (ponto && ponto < 3 && str[i] >= '0' && str[i] <= '9') {
			if (ponto == 1)
				dec1 = 10*(str[i]-'0');
			else
				dec1 += str[i]-'0';
			ponto++;
		}
	}
	val1[j] = '\0';
	ponto = 0;
	j = 0;
	for (;i < strlen(str) && i != '\0'; i++) {
		if (str[i] == '.')
			ponto++;
		if (!ponto && str[i] >= '0' && str[i] <= '9')
			val2[j++] = str[i];
		if (ponto && ponto < 3 && str[i] >= '0' && str[i] <= '9') {
			if (ponto == 1)
				dec2 = 10*(str[i]-'0');
			else
				dec2 += str[i]-'0';
			ponto++;
		}
	}
	val2[j] = '\0';

	sscanf (val1, "%llu", &var1);
	sscanf (val2, "%llu", &var2);

	var1 += var2;
	dec1 += dec2;
	if (dec1 >= 100) {
		dec1-=100;
		var1++;
	}

	printf ("%llu.%02d\n", var1, dec1);

	return 0;
}
