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

#define MAX_N 100010

char T[MAX_N], T2[MAX_N]; //Input string
int n; // Length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; //for counting sort

void countingSort(int k){
	int i, sum, maxi = max(300,n); //up to 255 ASCII chars
	memset(c, 0, sizeof c);
	for(i = 0; i < n; i++) //count frequency of each integer
		c[i+k < n ? RA[i+k] : 0]++;
	for(i = sum = 0; i < maxi; i++){
		int t = c[i]; c[i] = sum; sum += t;
	}
	for(i = 0; i < n; i++){ //shuffle suffix array if necessary
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	}
	for(i = 0; i < n; i++){
		SA[i] = tempSA[i];
	}
}

void constructSA(){
	int i,k,r;
	for(i = 0; i < n; i++) RA[i] = T[i];
	for(i = 0; i < n; i++) SA[i] = i;
	for(k = 1; k < n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++){
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		}
		for(i = 0; i < n; i++){
			RA[i] = tempRA[i];
		}
		if(RA[SA[n-1]] == n-1) break;
	}
}

int Phi[MAX_N], PLCP[MAX_N], LCP[MAX_N];

void computeLCP(){ //longest commom prefix in suffix array
	int i, L;
	Phi[SA[0]] = -1;
	for(i = 1; i < n; i++)
		Phi[SA[i]] = SA[i-1];
	for(i = L = 0; i < n; i++){
		if(Phi[i] == -1){
			PLCP[i] = 0; continue;
		}
		while(T[i+L] == T[Phi[i]+L]) L++; //comput PLCP using theroem
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for(i = 0; i < n; i++) //Put in correct position
		LCP[i] = PLCP[SA[i]]; //look at max value of this array
		// the max value is the length of the longest repeated substring
		// get the highest value position and here is the longest repeated substring
}


int main(){
	scanf("%s", T);
	n = (int)strlen(T);
	T[n++] = '$';
	constructSA();
	for(int i = 0; i < n; i++) printf("%2d\t%s\n", SA[i], T + SA[i]);
	computeLCP();
	for(int i = 0; i < n; i++) printf("%2d\t%s\n", LCP[i], T + SA[i]);

	// Calculando maior substring em comum:
	// scanf("%s", T);
	// scanf("%s", T2);
	// int n1 = (int)strlen(T);
	// int n2 = (int)strlen(T2);
	// T[n1++] = '#';
	// T2[n2++] = '$';


	return 0;
}