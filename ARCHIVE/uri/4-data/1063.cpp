//Implementation using 2 queues and 1 stack (station), so that order is correct, using stack would use inverse order
#include <bits/stdc++.h>
using namespace std;

int i;
int qnt;
queue<char> start, after;
stack<char> station;
char c;
bool ans;

int main (){

	scanf("%d", &qnt);
	while (qnt){

		for (i = 0; i < qnt; i++){

			scanf(" %c", &c);
			start.push(c);

		}
		for (i = 0; i < qnt; i++){

			scanf(" %c", &c);
			after.push(c);

		}

		ans = true;
		while (ans && !after.empty()){

			if (!station.empty() && after.front() == station.top()){

				printf("R");
				after.pop();
				station.pop();

			}
			else{

				while (!start.empty() && after.front() != start.front()){

					printf("I");
					station.push(start.front());
					start.pop();

				}
				if (!start.empty() && after.front() == start.front()){

					printf("IR");
					after.pop();
					start.pop();

				}
				else ans = false;

			}

		}
		if (ans) puts("");
		else printf(" Impossible\n");

		while (!after.empty()) after.pop();
		while (!start.empty()) start.pop();
		while (!station.empty()) station.pop();

		scanf("%d", &qnt);
	}

	return 0;
}
