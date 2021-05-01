#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
#define MAXM 1010
#define INF 1000000000

//indexar em 1
//fazer n <= m
// complexidade O(n^2 * m)
int cost[MAXN][MAXM];

vector<int> pu, pv, par, way;

int n, m;

void hungarian(){
	pu.assign(n+1, 0);
	pv.assign(m+1, 0);
	way.assign(m+1, 0);
	par.assign(m+1, 0);

	for(int i = 1; i <= n; i++){
		par[0] = i;
		int j0 = 0;
		vector<int> minv(m+1, INF);
		vector<bool> used(m+1, false);

		do{
			used[j0] = true;
			int i0 = par[j0], delta = INF, j1;

			for(int j = 1; j <= m; j++){
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
		} while(par[j0] != 0);
		do{
			int j1 = way[j0];
			par[j0] = par[j1];
			j0 = j1;
		} while(j0);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> cost[i][j];
			//cost[i][j] += 3;
		}
	}

	hungarian();
	cout << "total: " << -pv[0] << endl;
	for(int i = 1; i <= m; i++){
		if(par[i]){
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

