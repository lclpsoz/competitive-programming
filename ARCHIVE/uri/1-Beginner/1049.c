#include <stdio.h>
#include <string.h>

int main(){

	int i, x, y, z;
	char* table[4][3][2] = {
		{{"ave"}, {"carnivoro", "aguia"}, {"onivoro", "pomba"}},
		{{"mamifero"}, {"onivoro", "homem"}, {"herbivoro", "vaca"}},
		{{"inseto"}, {"hematofago", "pulga"}, {"herbivoro", "lagarta"}},
		{{"anelideo"}, {"hematofago", "sanguessuga"}, {"onivoro", "minhoca"}}	};
	char class1[15] = { '\0' }, class2[15] = { '\0' }, class3[15] = { '\0' }, animal;
	scanf("%15s%15s%15s", class1, class2, class3);

	for (i = 0; i < 4; ++i){

		if (strcmp(table[i][0][0], class2) == 0){

			for (x = 1; x < 3; ++x){

				if (strcmp(table[i][x][0], class3) == 0){

					printf("%s\n", table[i][x][1]);

				}
			}
		}
	}

	return 0;
}