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
#define FOR(I, A, B) for(int (I) = (A); (I) < (B); (I)++)
#define RFOR(I, A, B) for(int (I) = (A); (I) >= (B); (I)--)

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<iii> viii;
typedef vector<ll> vll;

vi zfunction(string s){
	int n = sz(s);
	vi z(n, 0);
	for(int i = 1, l = 0, r = 0; i < n; i++){
		if(i <= r){
			z[i] = min(r - i + 1, z[i-l]);
		}
		while(i + z[i] < n && s[z[i]] == s[i+z[i]]){
			z[i]++;
		}
		if(i + z[i] - 1 > r){
			l = i; 
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main(){
	string s("asdasdasdasd");
	vi zs = zfunction(s);
	cout << s << endl;
	FOR(i, 0, sz(zs)){
		printf("%d ", zs[i]);
	}
	printf("\n");
	return 0;
}