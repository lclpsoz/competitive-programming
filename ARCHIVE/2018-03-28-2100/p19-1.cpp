#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int i, j, k;
int l_i, l_j, r_i, r_j;
int mat[MAXN][MAXN], n, m;
int querries, mini, maxi, max_sqr;
int lef, mid, rig, l_i_aux, l_j_aux, mini_i, maxi_i;

void binary_search_diag (){

	//Binary search (lower bound)
	lef = 0;
	rig = r_i - l_i;
	while (lef <= rig){

		//printf("\tmid: %d\n", mid);
		mid = (lef + rig) >> 1;
		l_i_aux = mid + l_i;
		l_j_aux = mid + l_j;
		if (mat[l_i_aux][l_j_aux] >= mini){

			if (l_i_aux == 0 || l_j_aux == 0)
				break;
			else if (mat[l_i_aux-1][l_j_aux-1] < mini)
				break;

		}

		if (mat[l_i_aux][l_j_aux] < mini)
			lef = mid+1;
		else
			rig = mid-1;

	}
	if (mat[l_i_aux][l_j_aux] >= mini){

		//printf("\tlower: %d %d\n", l_i_aux, l_j_aux);
		mini_i = l_i + mid;

		//Binary search (higher bound)
		//printf("-----\n");
		lef = 0;
		rig = r_i - l_i;
		while (lef <= rig){

			//printf("\tmid: %d\n", mid);
			mid = (lef + rig) >> 1;
			l_i_aux = mid + l_i;
			l_j_aux = mid + l_j;
			if (mat[l_i_aux][l_j_aux] <= maxi){

				if (l_i_aux == n-1 || l_j_aux == m-1)
					break;
				else if (mat[l_i_aux+1][l_j_aux+1] > maxi)
					break;

			}

			if (mat[l_i_aux][l_j_aux] > maxi)
				rig = mid-1;
			else
				lef = mid+1;

		}
		//printf("\thigher: %d %d\n", l_i_aux, l_j_aux);
		if (mat[l_i_aux][l_j_aux] <= maxi){

			maxi_i = l_i + mid;
			max_sqr = max(max_sqr, maxi_i - mini_i + 1);

		}

	}

}

int main ()
{

	//n is the amount of rows and m is the amount of colunms
	while (scanf("%d %d", &n, &m), n || m){

		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);

		scanf("%d", &querries);

		for (i = 0; i < querries; i++){

			max_sqr = 0;
			scanf("%d %d", &mini, &maxi);

			//(n-1,0) and (0, m-1):
			if ((mat[n-1][0] >= mini && mat[n-1][0] <= maxi) || (mat[0][m-1] >= mini && mat[0][m-1] <= maxi))
				max_sqr = 1;

			//First half and principal diagonal
			for (l_i = n-2, l_j = 0, r_i = n-1, r_j = 0; l_i >= 0; l_i--){

				if ((r_j+1) < m)
					r_j++;
				else
					r_i--;

				binary_search_diag();

			}

			//Second half without principal diagonal
			for (l_i = 0, l_j = 1; l_j < m-1; l_j++){

				if ((r_j+1) < m)
					r_j++;
				else
					r_i--;

				binary_search_diag();

			}

			printf("%d\n", max_sqr);

		}
		printf("-\n");

	}

	return 0;
}
