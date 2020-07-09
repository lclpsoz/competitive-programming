//Using tree of three childs logic to organize data. The first parents are the val or fig that is equal in the cards, and the childs the amount of each fig. or val., depending on the tree (Saving only amounts to make it even smaller)
//In this the sets are removed in the end
#include <bits/stdc++.h>
using namespace std;

typedef struct _card{

	int val;
	int fig;

} Card;

int const MAXN = 20, MAXS = 30;

int last, qnt_sets; //First position truly empty in the array arr
int tree[MAXN]; //Stores amount of card that have equal val from position 0 and equal in fig. from position 10
int cards[MAXN]; //Stores the amount of each card, to detect wwhen there's three equals

void remove_card (int a, int b){

	tree[(3 * a) + b]--;
	tree[10 + (3 * b) + a]--;


}

void remove_set (Card tmp, int pos, int remove_type){

	qnt_sets++;

	if (remove_type < 2){

		//Remove the whole set:
		tree[pos]--;
		tree[pos+1]--;
		tree[pos+2]--;

		//Remove each value from the other tree:
		//When the set have equal values:
		if (!remove_type){

			pos = 3 * tmp.val;
			cards[pos]--;
			cards[pos+1]--;
			cards[pos+2]--;
			pos = tmp.val + 10;

		}
		//When the set have equal figures:
		else{

			pos = tmp.fig;
			cards[pos]--;
			cards[pos+3]--;
			cards[pos+6]--;
			pos = tmp.fig + 0;

		}

		tree[pos]--;
		tree[pos+3]--;
		tree[pos+6]--;

	}
	else if (remove_type == 2){

		cards[(3 * tmp.val) + 0 + tmp.fig] -= 3;
		tree[(3 * tmp.val) + 0 + tmp.fig] -= 3;
		tree[(3 * tmp.fig) + 10 + tmp.val] -= 3;

	}
	else if (remove_type == 3){

		int l;
		Card i = {0, tmp.val}, j = {1, tmp.fig}, k = {2, pos};

		cards[i.fig]--;
		cards[j.fig+3]--;
		cards[k.fig+6]--;

		remove_card(i.val, i.fig);
		remove_card(j.val, j.fig);
		remove_card(k.val, k.fig);

	}

}

void insert_card (Card tmp){

	int i, j, k;
	int pos;

	//General tree to detect if one type is equal and the other different
	//Insert in tree of equal values
	pos = (3 * tmp.val) + 0;
	tree[pos + tmp.fig]++;

	//Insert in tree of equal figures
	pos = (3 * tmp.fig) + 10;
	tree[pos + tmp.val]++;

	//Specific array to store amount of each card
	pos = (3 * tmp.val) + tmp.fig;
	cards[pos]++;

}

void count_sets (){


	if (tree[pos] && tree[pos+1] && tree[pos+2])
		remove_set(tmp, pos, 0);
	if (tree[pos] && tree[pos+1] && tree[pos+2])
		remove_set(tmp, pos, 1);
	if (cards[pos] == 3) remove_set(tmp, pos, 2);
	//Detect when there's a set with all different types
	//i is fig 0, j is fig 1, k is fig 2, the value of each is val
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				if (i != j && i != k && j != k)
					if (cards[i] && cards[j+3] && cards[k+6]){

						//In tmp.val will be the first fig, tmp.fig the second and pos the third
						tmp.val = i;
						tmp.fig = j;
						pos = k;
						remove_set(tmp, pos, 3);

					}


}

int main (){

	int i, j;
	int qnt;
	char str1[MAXS], str2[MAXS];
	Card tmp;

	scanf("%d", &qnt);
	while (qnt){

		for (i = 0; i < qnt; i++){

			scanf("%s %s", str1, str2);

			//Using from 0 to 2 to make it easier in the tree logic
			switch (str1[0]){
				case 'u': tmp.val = 0; break;
				case 'd': tmp.val = 1; break;
				case 't': tmp.val = 2; break;
			}
			switch (str2[0]){
				case 'c': tmp.fig = 0; break;
				case 'q': tmp.fig = 1; break;
				case 't': tmp.fig = 2; break;
			}
			//printf("tmp: %d %d\n", tmp.val, tmp.fig);

			insert_card(tmp);
			/*for (j = 0; j < 19; j++){

				printf("%d ", tree[j]);
				if (j == 8){ printf("\n");j++;}

			}
			printf("\nC: ");
			for (j = 0; j < 9; j++)
				printf("%d ", cards[j]);
			printf("\n");*/

		}

		/*for (j = 0; j < 19; j++){

			printf("%d ", tree[j]);
			if (j == 8){ printf("\n");j++;}

		}
		printf("\nC: ");
		for (j = 0; j < 9; j++)
			printf("%d ", cards[j]);
		printf("\n");*/
		count_sets();
		printf("%d\n", qnt_sets);

		for (i = 0; i < 20; i++){

			tree[i] = 0;
			cards[i] = 0;

		}
		qnt_sets = 0;

		scanf("%d", &qnt);
	}

	return 0;
}
