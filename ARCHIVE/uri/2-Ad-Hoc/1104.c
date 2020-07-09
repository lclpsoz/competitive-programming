#include <stdio.h>

typedef struct cards_s{

	int raw[10000];
	int set[10000];
	int raw_qnt;
	int set_qnt;

} cards;

int pos, total_raw, dup;
cards a, b;

int bin_search (cards *stct, int val){

	int i;
	int left = 0, right = stct->set_qnt - 1;
	int mid;

	while (left <= right){

		mid = (left + right) / 2;

		if (stct->set[mid] == val)
			return 1;
		else if (stct->set[mid] > val)
			right = mid - 1;
		else
			left = mid + 1;

	}

	return 0;
}


int main (void){

	int i;

	scanf("%d %d", &a.raw_qnt, &b.raw_qnt);

	while (a.raw_qnt){

		//Read the numbers
		for (i = 0; i < a.raw_qnt; i++)
			scanf("%d", &a.raw[i]);

		for (i = 0; i < b.raw_qnt; i++)
			scanf("%d", &b.raw[i]);

		//Tranfer only unique values to 'set' array of each struct
		pos = 0;	//Position in the 'set' array, to comparission
		a.set[0] = a.raw[0];
		for (i = 1; i < a.raw_qnt; i++)
			if (a.raw[i] != a.set[pos])
				a.set[++pos] = a.raw[i];
		a.set_qnt = pos + 1;

		pos = 0;
		b.set[0] = b.raw[0];
		for (i = 1; i < b.raw_qnt; i++)
			if (b.raw[i] != b.set[pos])
				b.set[++pos] = b.raw[i];
		b.set_qnt = pos + 1;

		//Qnt of ab before removing duplicated values
		total_raw = a.set_qnt + b.set_qnt;

		//Count duplicated values in both arrays
		dup = 0;
		if (a.set_qnt > b.set_qnt){

			for (i = 0; i < b.set_qnt; i++)
				if (bin_search(&a, b.set[i]))
					dup++;

		}
		else
			for (i = 0; i < a.set_qnt; i++)
				if (bin_search(&b, a.set[i]))
					dup++;

		if (a.set_qnt > b.set_qnt)
			printf("%d\n", b.set_qnt - dup);
		else
			printf("%d\n", a.set_qnt - dup);

		scanf("%d %d", &a.raw_qnt, &b.raw_qnt);

	}

	return 0;
}
