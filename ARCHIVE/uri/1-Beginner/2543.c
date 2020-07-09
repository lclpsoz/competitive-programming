#include <stdio.h>

int i;
int gameplays, id_player, id, game, count;

int main (void){

	while (scanf("%d %d", &gameplays, &id_player) != EOF){

		for (i = 0; i < gameplays; i++){

			scanf("%d %d", &id, &game);
			if (id == id_player && !game)
				count++;

		}

		printf("%d\n", count);
		count = 0;

	}

	return 0;
}
