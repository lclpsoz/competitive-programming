#include <stdio.h>

int i;
int vote_qnt, vote, favor;
double min_votes;

int main (void){

	while (scanf("%d", &vote_qnt) != EOF){

		for (i = 0; i < vote_qnt; i++){

			scanf("%d", &vote);
			favor += vote;

		}

		min_votes = vote_qnt * (2 / 3.0);
		if (favor >= min_votes)
			printf("impeachment\n");
		else
			printf("acusacao arquivada\n");

		favor = 0;

	}

	return 0;
}
