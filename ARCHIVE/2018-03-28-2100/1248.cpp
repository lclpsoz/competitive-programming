#include <bits/stdc++.h>
using namespace std;

int n;
char diet[30], brea[30], lunch[30];

int main ()
{
	scanf ("%d\n", &n);
	for (int i = 0; i < n; i++) {
		brea[0] = diet[0] = lunch[0] = '\0';
		scanf ("%[^\n]", diet);
		getchar();
		scanf ("%[^\n]", brea);
		getchar();
		scanf ("%[^\n]", lunch);
		getchar();
		//printf ("(%s %s %s)\n", diet, brea, lunch);
		bool test = true;
		for (int j = 0; j < strlen(brea) && test; j++) {
			bool sub_test = false;
			for (int k = 0; k < strlen(diet) && !sub_test; k++)
				if (diet[k] == brea[j]) {
					diet[k] = ' ';
					sub_test = true;
				}
			if (!sub_test)
				test = false;
		}
		for (int j = 0; j < strlen(lunch) && test; j++) {
			bool sub_test = false;
			for (int k = 0; k < strlen(diet) && !sub_test; k++)
				if (diet[k] == lunch[j]) {
					diet[k] = ' ';
					sub_test = true;
				}
			if (!sub_test)
				test = false;
		}
		if (!test)
			printf ("CHEATER\n");
		else {
			sort (diet, diet + strlen(diet));
			for (int k = 0; k < strlen(diet); k++) {
				if (diet[k] != ' ')
					printf ("%c", diet[k]);
			}
			printf ("\n");
		}

	}

	return 0;
}
