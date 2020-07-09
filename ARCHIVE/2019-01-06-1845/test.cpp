#include <bits/stdc++.h>
using namespace std; 

int n_line, n_colu, linei, colui, full, grid[250][250], x, y, answer;

void paint(int l, int c){
	if (l <= n_line && l > 0 && c <= n_colu && c > 0){
		if (grid[l][c] == 0){
			answer++; 
			grid[l][c] = 1; 
		}
		paint(l+1, c); 
		paint(l+1, c+1); 
		paint(l-1, c-1); 
		paint(l, c-1); 
		paint(l, c+1); 
		paint(l-1, c-1); 
		paint(l-1, c); 
		paint(l-1, c+1); 
	}
	return; 
}    
int main(){
	scanf("%d %d %d %d %d", &n_line, &n_colu, &linei, &colui, &full); 
	for (int i = 0; i < full; i++){
		scanf("%d %d", &x, &y); 
		grid[x][y] = 1; 
	}
	paint(linei, colui); 
	printf("%d\n", answer); 
}
