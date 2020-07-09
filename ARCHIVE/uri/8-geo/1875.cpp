#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnta, qntb;
int arr[3]; // R, G, B
char win, space, lose;

int main (){

	scanf("%d", &qnta);
	for (i = 0; i < qnta; i++){

		scanf("%d ", &qntb);
		for (j = 0; j < qntb; j++){

			win = getchar();
			space = getchar();
			lose = getchar();
			space = getchar();
			//printf("%c %c\n", win, lose);
			if (win == 'R'){

				if (lose == 'G')
					arr[0] += 2;
				else
					arr[0]++;

			}
			else if (win == 'G'){

				if (lose == 'B')
					arr[1] += 2;
				else
					arr[1]++;

			}
			if (win == 'B'){

				if (lose == 'R')
					arr[2] += 2;
				else
					arr[2]++;

			}
		}

		if (arr[0] > arr[1] && arr[0] > arr[2])
			printf("red\n");
		else if (arr[1] > arr[0] && arr[1] > arr[2])
			printf("green\n");
		else if (arr[2] > arr[0] && arr[2] > arr[1])
			printf("blue\n");
		else if (arr[0] == arr[1] && arr[0] == arr[2])
			printf("trempate\n");
		else
			printf("empate\n");

		arr[0] = arr[1] = arr[2] = 0;

	}

	return 0;
}
