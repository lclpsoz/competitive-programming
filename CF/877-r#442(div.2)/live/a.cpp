#include <bits/stdc++.h>
using namespace std;

const int MAXS = 110;

int i;
char str[MAXS];
char *point[5];
int test;

int main (){

	scanf("%s", str);

	point[0] = strstr(str, "Danil");
	point[1] = strstr(str, "Olya");
	point[2] = strstr(str, "Slava");
	point[3] = strstr(str, "Ann");
	point[4] = strstr(str, "Nikita");

	if (point[0] != NULL){

		strncpy(point[0], "---", 3);
		test = 1;

	}
	if (point[1] != NULL){

		strncpy(point[1], "---", 3);
		if (test == 0) test = 1;
		else test = 2;

	}
	if (point[2] != NULL){

		strncpy(point[2], "---", 3);
		if (test == 0) test = 1;
		else test = 2;

	}
	if (point[3] != NULL){

		strncpy(point[3], "---", 3);
		if (test == 0) test = 1;
		else test = 2;

	}
	if (point[4] != NULL){

		strncpy(point[4], "---", 3);
		if (test == 0) test = 1;
		else test = 2;

	}

	if (test == 0 || test == 2)
		puts("NO");
	else{

		point[0] = strstr(str, "Danil");
		point[1] = strstr(str, "Olya");
		point[2] = strstr(str, "Slava");
		point[3] = strstr(str, "Ann");
		point[4] = strstr(str, "Nikita");

		bool is_null = true;
		for (i = 0; i < 5; i++)
			if (point[i] != NULL)
				is_null = false;

		if (test == 1 && is_null)
			puts("YES");
		else
			puts("NO");

	}

	return 0;
}
