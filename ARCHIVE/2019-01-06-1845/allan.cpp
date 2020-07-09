#include <bits/stdc++.h>
using namespace std; 

int lines, colus, boat_id[111][111], x, y, last_id, shots, drown;       
char grid[111][111]; 
set<pair<int, int>> boats[111];  


void dfs(int l, int c, int id) {
	if (grid[l][c] != '#' or boat_id[l][c] != 0) return;
	boat_id[l][c] = id; 
	boats[id].insert(make_pair(l, c));  
	for (int i = -1; i <= 1; i+=2) {
		dfs(l+i, c, id);
		dfs(l, c+i, id);
	}
}
int main(){
	cin >> lines >> colus;
	
	for (int i = 1; i <= lines; i++){
		for (int j = 1; j <= colus; j++){
			char c;
			cin >> c; 
			grid[i][j] = c;
		}
	}
	
	
	for (int i = 1; i <= lines; i++)
		for (int j = 1; j <= colus; j++)
			if (grid[i][j] == '#' and boat_id[x][y] == 0)
				dfs(i, j, ++last_id);
	
	cin >> shots;
	for (int i = 0; i < shots; i++){
		cin >> x >> y;
		if (boat_id[x][y] != 0){
			int id = boat_id[x][y];
			if (boats[id].count ({x, y}) == 1)
				boats[id].erase(make_pair(x, y));
			if (boats[id].empty())
				drown++;
			boat_id[x][y] = 0;
		}
	}
	cout << drown << '\n';
}
