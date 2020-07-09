#include <bits/stdc++.h>
using namespace std;

int i, j, k;
int notes[14]; //C, C#, D, D#, ... From 1 to 12 in bits (the 13 is C, that's the same as 1)
int note, aux;
char str[1010], *substr;
char notes_str[12][3] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
bool print;

int main ()
{
	for (i = 1; i < 13; i++) {
		j = i;
		k = 1;
		do {
			notes[i] |= 1 << j;
			if (k == 3 || k == 7)
				j++;
			else
				j+=2;
			k++;
			if (j > 12)
				j-=12;
		} while (k < 9);
		/*printf ("%02d:", i);
		for (j = 1; j < 13; j++)
			if (notes[i] & (1 << j))
				putchar ('1');
			else
				putchar ('0');
		putchar ('\n');*/
	}
	while (scanf (" %[^\n]", str), str[1] != 'N') {
		substr = strtok (str, " ");
		note = 0;
		while (substr != NULL) {
			switch (substr[0]) {
				case 'C': if (substr[1] == '\0')
							  note |= 1 << 1;
						  else
							  note |= 1 << 2;
						  break;
				case 'D': if (substr[1] == '\0')
							  note |= 1 << 3;
						  else
							  note |= 1 << 4;
						  break;
				case 'E': note |= 1 << 5;
						  break;
				case 'F': if (substr[1] == '\0')
							  note |= 1 << 6;
						  else
							  note |= 1 << 7;
						  break;
				case 'G': if (substr[1] == '\0')
							  note |= 1 << 8;
						  else
							  note |= 1 << 9;
						  break;
				case 'A': if (substr[1] == '\0')
							  note |= 1 << 10;
						  else
							  note |= 1 << 11;
						  break;
				case 'B': note |= 1 << 12;
						  break;
			}
			substr = strtok (NULL, " ");
		}
		/*for (j = 1; j < 13; j++)
			if (note & (1 << j))
				putchar ('1');
			else
				putchar ('0');
		putchar ('\n');*/
		print = false;
		for (i = 1; i < 13; i++) {
			aux = note;
			aux ^= notes[i];
			aux &= note;
			if (!(__builtin_popcount (aux)))
				if (!print) {
					printf ("%s", notes_str[i-1]);
					print = true;
				}
				else
					printf (" %s", notes_str[i-1]);
		}
		putchar ('\n');
	}
	return 0;
}
