#include <bits/stdc++.h>
using namespace std;

int total, c;
char arr[150];
bool valid;

int main ()
{
	while (scanf (" %[^\n]", arr) != EOF) {
		total = c = 0;
		char *aux = strtok (arr, " ");
		while (aux) {
			valid = true;
			for (int i = 0; valid && aux[i] != '\0'; i++) {
				if (aux[i] >= '0' && aux[i] <= '9')
					valid = false;
				else if (aux[i] == '.' && (aux[i+1] != '\0' || strlen (aux) == 1))
					valid = false;
				else if (aux[i] == '.' && aux[i+1] == '\0')
					aux[i] = '\0';
			}
			// printf ("%s ", aux);
			// valid ? printf ("VALID\n") : printf ("NOT\n");
			if (valid) {
				total++;
				c += strlen (aux);
			}
			aux = strtok (NULL, " ");
		}
		if (total)
			c /= total;
		else
			c = 0;
		// putchar ('\t');
		if (c <= 3)
			printf ("250\n");
		else if (c <= 5)
			printf ("500\n");
		else
			printf ("1000\n");
		// printf ("---------------------\n");
	}
	return 0;
}
