#include <stdio.h>

int main (void){

        int numb;
        while (scanf("%d", &numb) != EOF)
                if (numb == 0)
                        printf("vai ter copa!\n");
                else
                        printf("vai ter duas!\n");

        return 0;
}
