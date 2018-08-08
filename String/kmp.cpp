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

// KMP

#define MAXN 100010

vi kmpprep(string pattern){
	int i = 1, j = 0, m = pattern.size();
	vi parray (m, 0);
	while(i < m){
		if(pattern[i] == pattern[j]){
			parray[i] = j + 1;
			j++, i++;
		} else if(j == 0){
			parray[i] = 0;
			i++;
		} else {
			j = parray[j-1];
		}
	}
	return parray;
}

int kmpsearch(string text, string pattern, vi parray){
	int i = 0, j = 0;
	int m = pattern.size(), n = text.size();
	while(i < n){
		if(pattern[j] != text[i] && j > 0){
			j = parray[j-1];
		} else if(pattern[j] == text[i]){
			i++, j++;
		} else {
			i++;
		}

		if(j == m){
			return i - j;
		}
	}
	return -1;
}

int main(){
	string pattern, text;
	pattern = "aabcaabaab";
	text = "aabcaabaacaabcaabaabaab";
	vi parray = kmpprep(pattern);
	assert (10 == kmpsearch(text, pattern, parray));
	pattern = "blade";
	text = "aabcaabaacaabcaabaabaab";
	parray = kmpprep(pattern);
	assert (-1 == kmpsearch(text, pattern, parray));
	text = "blasfemia, meu nome eh bayblade, mas eh lucas";
	parray = kmpprep(pattern);
	assert (26 == kmpsearch(text, pattern, parray));
	return 0;
}