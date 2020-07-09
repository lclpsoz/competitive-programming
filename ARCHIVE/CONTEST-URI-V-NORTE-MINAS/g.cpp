#include <bits/stdc++.h>
using namespace std;

double Cx, Cy, Ex, Ey;
double v;
double Txe, Tye, Txd, Tyd;
double sup;
double inf;

int main ()
{
	while (scanf ("%lf %lf %lf %lf %lf", &Cx, &Cy, &Ex, &Ey, &v) != EOF) {
		scanf ("%lf %lf %lf %lf", &Txe, &Tye, &Txd, &Tyd);
		// Caminho superior:
		sup = Txd-Txe;
		// Casa-Terreno
		sup += sqrt(((Txe-Cx)*(Txe-Cx))+((Tyd-Cy)*(Tyd-Cy)));
		// Terreno-Escola
		sup += sqrt(((Txd-Ex)*(Txd-Ex))+((Tyd-Ey)*(Tyd-Ey)));

		// Caminho inf:
		inf = Txd-Txe;
		// Casa-Terreno
		inf += sqrt(((Txe-Cx)*(Txe-Cx))+((Tye-Cy)*(Tye-Cy)));
		// Terreno-Escola
		inf += sqrt(((Txd-Ex)*(Txd-Ex))+((Tye-Ey)*(Tye-Ey)));
		if (inf < sup)
			printf ("%.1lf\n", inf/v);
		else
			printf ("%.1lf\n", sup/v);

	}

	return 0;
}
