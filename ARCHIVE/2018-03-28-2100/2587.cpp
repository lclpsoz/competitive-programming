#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;

int i, j, k;
int qnt, pos1, pos2;
char str_1[MAXN], str_2[MAXN], guess[MAXN];

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf(" %[^\n]", str_1);
		scanf(" %[^\n]", str_2);
		scanf(" %[^\n]", guess);

		for (j = pos1 = pos2 = 0; guess[j] != '\0'; j++)
			if (guess[j] == '_')
				if (!pos1)
					pos1 = j;
				else
					pos2 = j;

		if (str_1[pos1] == str_2[pos2] || str_1[pos2] == str_2[pos1])
			printf("Y\n");
		else
			printf("N\n");

	}

	return 0;
}
