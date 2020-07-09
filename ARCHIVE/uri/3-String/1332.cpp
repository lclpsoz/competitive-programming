#include <bits/stdc++.h>
using namespace std;

int i, j;
int qnt, cnt1;
char str[10];
char str1[4] = {"one"};

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		cnt1 = 0;
		scanf("%s", str);

		if (str[3] == '\0'){

			for (j = 0; j < 3; j++)
				if (str[j] == str1[j])
					cnt1++;


			//printf("%d %d\n", cnt1, cnt2);

			(cnt1 >= 2) ? printf("1\n"): printf("2\n");

		}
		else
			printf("3\n");

		for (j = 0; j < 10; j++)
			str[j] = '\0';

	}

	return 0;
}
