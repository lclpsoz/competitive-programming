#include <stdio.h>

int i;
int qnt, samples[10002], peaks;

int main (void){

	scanf("%d", &qnt);

	while (qnt){

		peaks = 0;
		for (i = 1; i <= qnt; i++)
			scanf("%d", &samples[i]);
		samples[0] = samples[qnt];
		samples[qnt + 1] = samples[1];

		for (i = 1; i <= qnt; i++)
			if ((samples[i] > samples[i - 1] && samples[i] > samples[i + 1]) || (samples[i] < samples[i - 1] && samples[i] < samples[i + 1]))
				peaks++;

		printf("%d\n", peaks);

		scanf("%d", &qnt);

	}

	return 0;
}
