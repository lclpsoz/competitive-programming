//First idea, incomplete, would create two lines for each new card that didn't fit in a previous set
#include <bits/stdc++.h>
using namespace std;

typedef _card{

	int val;
	int fig;

} Card;

int const MAXN = 1ea3+1, MAXS = 30;

int last, qnt_sets; //First position truly empty in the array arr
Card arr[MAXN][3]; //Two lines are for one card, so 0 and 1, 2 and 3, 4 and 5, ...

void remove_set (int i){

	int j;
	int aux = i;
	qnt_sets++;

	for (;i < aux+2; i++){

		for (j = 0; j < 3; j++){

			arr[i][j].val = 0;
			arr[i][j].fig = 0;

		}
	}
}

void insert_card (Card tmp){

	int i, j = 0;

	for (i = 0; i <= last; i+=2){

		if (tmp.val == arr[i][0].val && tmp.fig != arr[i][0].fig){

			if (!arr[i][1].val){

				arr[i][1].val = tmp.val;
				arr[i][1].fig = tmp.fig;
				return;

			}
			else if (arr[i][1].fig != tmp.fig){

				remove_set(i);

			}


		}
	}
}

int main (){

	int i;
	int qnt;
	char str1[MAXS], str2[MAXS];
	Card tmp;

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%s %s", &str1, &str2);

		switch (str1[0]){
			case 'u': tmp.val = 1; break;
			case 'd': tmp.val = 2; break;
			case 't': tmp.val = 3; break;
		}
		switch (str2[0]){
			case 'c': tmp.fig = 1; break;
			case 'q': tmp.fig = 2; break;
			case 't': tmp.fig = 3; break;
		}





	}

	return 0;
}
