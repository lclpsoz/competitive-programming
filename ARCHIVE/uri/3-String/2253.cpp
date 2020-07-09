#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e6;

int i;
int size;
char str[MAXS], trash;
bool low, up, numb;

int main(){

	while (scanf("%[^\n]\n", str) != EOF){

		low = up = numb = false;
		//printf("%s\n", str);
		size = strlen(str);

		if (size < 6 || size > 32){
		}
		else{

			for (i = 0 ; i < size; i++){

				if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9')){

					//printf("%c\n", str[i]);
					numb = false;
					break;

				}
				else{

					if (str[i] >= '0' && str[i] <= '9')
						numb = true;
					else if (str[i] >= 'a' && str[i] <= 'z')
						low = true;
					else if (str[i] >= 'A' && str[i] <= 'Z')
						up = true;

				}
			}
		}

		if (low && up && numb)
			printf("Senha valida.\n");
		else
			printf("Senha invalida.\n");
	}

	return 0;
}
