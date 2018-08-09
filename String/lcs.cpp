#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000
#define INFLL 0x3f3f3f3f3f3f3f3fLL 
#define EPS 10e-9
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define st first
#define nd second
#define sz(v) int(v.size())
#define all(X) (X).begin(), (X).end()

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

#define MAXN 1000

int PD[MAXN][MAXN];

int pd(int i, int j, string A, string B){
	int n = A.size(), m = B.size();

	if(i == n || j == m) return 0;

	int &mem = PD[i][j];
	if(mem != -1) return mem;

	if(A[i] == B[j])
		mem = max(mem, pd(i+1, j+1, A, B) + 1);
	mem = max(mem, pd(i+1, j, A, B));
	mem = max(mem, pd(i, j+1, A, B));

	return mem;
}

int main(){

	memset(PD, -1, sizeof PD);
	assert(pd(0,0,"AGCATGC","ACAATCC") == 5);
	memset(PD, -1, sizeof PD);
	assert(pd(0,0,"apple","people") == 4);
	
	return 0;
}