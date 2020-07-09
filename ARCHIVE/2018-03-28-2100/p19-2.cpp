#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;

int i, j, k;
int lower_b;
int mat[MAXN][MAXN], n, m;
int querries, mini, maxi, max_sqr;
int lef, mid, rig, l_i_aux, l_j_aux, mini_i, maxi_i;

int binary_search_diag (int l_i, int l_j){

	//Binary search (higher bound)
	lef = 0;
	if ((n-1 - l_i) < (m-1 - l_j))
		rig = n-1 - l_i;
	else
		rig = m-1 - l_j;

	//printf("   (%d, %d): %d\n", l_i, l_j, rig);

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

	//printf("    %d\n", mid+1);
	if (lef <= rig)
		return mid + 1;
	else
		return 0;

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

			scanf("%d %d", &mini, &maxi);

			max_sqr = 0;
			//(n-1,0) and (0, m-1):
			if ((mat[n-1][0] >= mini && mat[n-1][0] <= maxi) || (mat[0][m-1] >= mini && mat[0][m-1] <= maxi))
				max_sqr = 1;

			lower_b = m-1;
			//printf("%d: %d\n", 0, lower_b);
			for (j = 0; j < n; j++){

				lower_b = (int) (lower_bound (mat[j], mat[j] + lower_b + 1, mini) - mat[j]);
				//printf("{%d} ", lower_b);
				if (lower_b < m)
					max_sqr = max(max_sqr, binary_search_diag(j, lower_b));
				else
					lower_b = m-1;
				//printf("%d: %d\n", j+1, lower_b);

			}

			printf("%d\n", max_sqr);

		}
		printf("-\n");

	}

	return 0;
}
