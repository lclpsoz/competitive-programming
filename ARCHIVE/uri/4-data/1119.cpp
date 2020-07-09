#include <bits/stdc++.h>
using namespace std;

typedef struct _mov{

	int jmp;
	int lst;

} Mov;

const int MAXN = 50;

int qnt, rest;
Mov counter, clock_w;
bool circle[MAXN];

void turn_clock (){

	int i;
	for (i = 0; i < clock_w.jmp; i++){

		while (!circle[clock_w.lst]){

			clock_w.lst--;
			if (clock_w.lst == 0) clock_w.lst = qnt;

		}
		if (i < clock_w.jmp-1){

			clock_w.lst--;
			if (clock_w.lst == 0) clock_w.lst = qnt;

		}
		while (!circle[clock_w.lst]){

			clock_w.lst--;
			if (clock_w.lst == 0) clock_w.lst = qnt;

		}

	}

	if (clock_w.lst != counter.lst) rest--;

}

void turn_counter (){

	int i;
	for (i = 0; i < counter.jmp; i++){

		while (!circle[counter.lst]){

			counter.lst++;
			if (counter.lst > qnt) counter.lst = 1;

		}
		if (i < counter.jmp-1){

			counter.lst++;
			if (counter.lst > qnt) counter.lst = 1;

		}
		while (!circle[counter.lst]){

			counter.lst++;
			if (counter.lst > qnt) counter.lst = 1;

		}

	}

	rest--;

}

int main (){

	int i;

	scanf("%d", &qnt);
	while (qnt){

		rest = qnt;
		counter.lst = 1;
		clock_w.lst = qnt;
		//Reset array
		for (i = 1; i <= qnt; i++) circle[i] = true;

		scanf("%d %d", &counter.jmp, &clock_w.jmp);

		while (rest){

			turn_counter();
			printf("%3d", counter.lst);

			if (rest){

				turn_clock();
				if (clock_w.lst != counter.lst) printf("%3d", clock_w.lst);

			}

			if (rest) printf(",");
			//for (i = 1; i <= qnt; i++) printf("%d ", circle[i]);
			//printf("cnt_lst: %d\n", counter.lst);
			//printf("clk_lst: %d\n", clock_w.lst);

			circle[counter.lst] = false;
			circle[clock_w.lst] = false;

		}
		printf("\n");

		scanf("%d", &qnt);
	}

	return 0;
}
