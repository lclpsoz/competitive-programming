#include <bits/stdc++.h>
using namespace std;


void printer (int &x, int base, int spaces)
{
	if (x >= base) {
		x-=base;
		putchar ('o');
	}
	else
		putchar (' ');
	if (base > 1)
		for (int i = 0; i < spaces; i++)
			putchar (' ');
}

int main ()
{
	int hh, mm;
	while (scanf ("%d:%d", &hh, &mm) != EOF) {
		printf (" ____________________________________________\n");
		printf ("|                                            |\n");
		printf ("|    ____________________________________    |_\n");
		printf ("|   |                                    |   |_)\n");
		printf ("|   |   8         4         2         1  |   |\n");
		printf ("|   |                                    |   |\n");
		printf ("|   |   ");
		printer (hh, 8, 9);
		printer (hh, 4, 9);
		printer (hh, 2, 9);
		printer (hh, 1, 9);
		printf ("  |   |\n");
		printf ("|   |                                    |   |\n");
		printf ("|   |                                    |   |\n");
		printf ("|   |   ");
		printer (mm, 32, 5);
		printer (mm, 16, 5);
		printer (mm, 8, 5);
		printer (mm, 4, 5);
		printer (mm, 2, 5);
		printer (mm, 1, 5);
		printf ("  |   |\n");
		printf ("|   |                                    |   |\n");
		printf ("|   |   32    16    8     4     2     1  |   |_\n");
		printf ("|   |____________________________________|   |_)\n");
		printf ("|                                            |\n");
		printf ("|____________________________________________|\n");
		putchar ('\n');
	}
	return 0;
}
