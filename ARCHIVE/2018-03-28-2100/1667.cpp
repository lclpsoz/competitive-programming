#include <bits/stdc++.h>
using namespace std;

char arr[200];
char aux[90];

int main ()
{
	char c, t;
	int pos = 0;
	while (c = getchar (), c != EOF) {
		if ((c == ' ' || c == '\n' || c == '\t') && pos)
			arr[pos++] = ' ';
		while (c == ' ' || c == '\n' || c == '\t')
			c = getchar ();
		if (c == EOF)
			break;
		if (pos > 0 && arr[pos-1] == ' ' && strlen (arr) >= 81) {
			if (arr[pos-1] == ' ') {
				arr[pos-1] = '\0';
				pos--;
			}
			int posAux = 0;
			pos--;
			while (arr[pos] != ' ' && pos >= 0) {
				aux[posAux++] = arr[pos];
				arr[pos] = '\0';
				pos--;
			}
			aux[posAux] = '\0';
			if (arr[pos] == ' ')
				arr[pos] = '\0';
			printf ("%s\n", arr);
			for (int i = 0; i < 170; i++)
				arr[i] = 0;
			pos = 0;
			posAux--;
			while (posAux >= 0) {
				arr[pos++] = aux[posAux];
				aux[posAux--] = '\0';
			}
			arr[pos++] = ' ';
			arr[pos] = '\0';
		}
		if (c == '<') {
			t = getchar ();
			getchar ();
			getchar ();
		}
		if (t == 'b') {
			if (arr[pos-1] == ' ')
				arr[pos-1] = '\0';
			printf ("%s", arr);
			for (int i = 0; i < 170; i++)
				arr[i] = 0;
			pos = 0;
			putchar ('\n');
		}
		else if (t == 'h') {
			if (arr[pos-1] == ' ')
				arr[pos-1] = '\0';
			printf ("%s", arr);
			if (pos)
				putchar ('\n');
			for (int i = 0; i < 170; i++)
				arr[i] = 0;
			for (int i = 0; i < 80; i++)
				putchar ('-');
			pos = 0;
			putchar ('\n');
		}
		else
			arr[pos++] = c;
		t = '\0';
	}
	if (pos) {
		if (arr[pos-1] == ' ')
			arr[pos-1] = '\0';
		printf ("%s\n", arr);
	}

	return 0;
}
