#include <bits/stdc++.h>
using namespace std;

typedef struct inter{

	int n, mini, maxi;

} Inter;

int size;
Inter i, j;

void prt(){

	int k, l;

	for (k = 0; k < size; k++){

		for (l = 0; l < size; l++)
			if (i.n == k && j.n == l)
				printf("X");
			else
				printf("O");
		printf("\n");

	}
	printf("@\n");

}

int main(){

	scanf("%d", &size);

	while (size){

		i.n = i.maxi = i.mini = size/2;
		j.n = j.maxi = j.mini = size/2;
		prt();
		while (i.maxi < size-1){

			i.maxi++;
			j.maxi++;
			i.mini--;
			j.mini--;

			j.n++; prt();
			while (i.n > i.mini){ i.n--; prt();}
			while (j.n > j.mini){ j.n--; prt();}
			while (i.n < i.maxi){ i.n++; prt();}
			while (j.n < j.maxi){ j.n++; prt();}

		}

		scanf("%d", &size);

	}

	return 0;
}
