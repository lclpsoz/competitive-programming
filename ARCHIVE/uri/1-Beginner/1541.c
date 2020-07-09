#include <stdio.h>
#include <math.h>

int side_1, side_2, area; 
double perc;

int main (void){

        scanf("%d", &side_1);

        while (side_1 != 0){

                scanf("%d%lf", &side_2, &perc);

                area = sqrt((side_1 * side_2) / (perc / 100));
                printf("%d\n", area);

                scanf("%d", &side_1);

        }

        return 0;
}