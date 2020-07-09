#include <bits/stdc++.h>
using namespace std;

int i;
int n, total, arr[30], guess, wrong, win;
char str1[1000], str2[1000];

int main (void){

	while (scanf("%d", &n), n != -1){

		win = false;
		wrong = 0;
		scanf("%s", str1);
		scanf("%s", str2);
		total = strlen(str1);
		for (i = 0; i < total; i++)
			arr[str1[i]-'a']++;

		for (i = 0; i < strlen(str2); i++){

			guess = str2[i]-'a';
			if (arr[guess] == 0){

				arr[guess] = -1;
				wrong++;

			}
			else if (arr[guess] > 0){

				total -= arr[guess];
				arr[guess] = -1;
				if (total == 0 && wrong < 7)
					win = true;

			}

		}

		printf("Round %d\n", n);
		if (total == 0 && win)
			printf("You win.\n");
		else if (wrong >= 7)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");

		for (i = 0; i < 30; i++)
			arr[i] = 0;


	}

	return 0;
}
