#include <bits/stdc++.h>
using namespace std;

int arr[20], val1, val2;
map<string, int> vars;
char aux[10], name[10], name_lst[10], c;

int main (){

	while (scanf(" %s := ", name) != EOF){

		strcpy(name_lst, name);

		scanf("%s", aux);
		if (aux[0] >= '0' && aux[0] <= '9')
			sscanf(aux, "%d", &val1);
		else
			val1 = vars[aux];
		//printf("val1: %d\n", val1);

		c = getchar();
		if (c == '\n')
			vars[name] = val1;
		else{

			scanf("+ %s ", aux);
			if (aux[0] >= '0' && aux[0] <= '9')
				sscanf(aux, "%d", &val2);
			else
				val2 = vars[aux];
			//printf("val2: %d\n", val2);

			vars[name] = val1 + val2;

		}

	}

	printf("%d\n", vars[name_lst]);

	return 0;
}
