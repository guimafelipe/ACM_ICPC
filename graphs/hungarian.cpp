#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define MAXM 1010
#define INF 1000000000

// essa versão é indexada em 0
//fazer n <= m
// complexidade O(n^2 * m)
int cost[MAXN][MAXM];

vector<int> pu, pv, par, way;

int n, m;

void hungarian(){
	pu.assign(n, 0);
	pv.assign(m+1, 0);
	way.assign(m+1, m);
	par.assign(m+1, -1);

	for(int i = 0; i < n; i++){
		par[m] = i;
		int j0 = m;
		vector<int> minv(m+1, INF);
		vector<bool> used(m+1, false);

		do{
			used[j0] = true;
			int i0 = par[j0], delta = INF, j1;

			for(int j = 0; j < m; j++){
				if(!used[j]){
					int cur = cost[i0][j] - pu[i0] - pv[j];
					if(cur < minv[j]){
						minv[j] = cur;
						way[j] = j0;
					}
					if(minv[j] < delta){
						delta = minv[j];
						j1 = j;
					}
				}
			}

			for(int j = 0; j <= m; j++){
				if(used[j]){
					pu[par[j]] += delta;
					pv[j] -= delta;
				} else {
					minv[j] -= delta;
				}
			}

			j0 = j1;
		} while(par[j0] != -1);
		do{
			int j1 = way[j0];
			par[j0] = par[j1];
			j0 = j1;
		} while(j0 != m);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> cost[i][j];
			//cost[i][j] += 3;
		}
	}

	hungarian();
	cout << "total cost: " << -pv[m] << endl;
	for(int i = 0; i < m; i++){
		if(par[i] != -1){
			cout << par[i] << " " << i << endl;
		}
	}
	return 0;
}

/*

3 4
3 4 1 2
7 1 -3 5
8 2 3 -3

*/

