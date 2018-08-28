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

#define ALFA 26 // Número de letras no alfabeto, consideradas minúsculas
#define MAXS 2000009

int nxt[MAXS][ALFA], fail[MAXS], cnt = 0; //Alternativa: trocar o nxt por um map ou lista de adj se o alfabeto for muito grande
vii pats[MAXS];

class AhoCorasick{
private:
	int root;
	int suffix(int x, int c){
		while(x != root && nxt[x][c] == 0) x = fail[x]; //KMP step
		return nxt[x][c] ? nxt[x][c] : root;
	}
	int newnode(){
		int x = ++cnt;
		fail[x] = 0;
		pats[x].clear();
		for(int c = 0; c < ALFA; c++) nxt[x][c] = 0;
		return x;
	}
public:
	AhoCorasick(){
		root = newnode(); // root é o nó 1 mas poderia ser o 0
	}

	void setfails(){
		queue<int> q;
		int x, y;
		q.push(root);
		while(!q.empty()){
			x = q.front();
			q.pop();
			for(int c = 0; c < ALFA; c++){
				y = nxt[x][c];
				if(y == 0) continue;
				fail[y] = (x == root ? x : suffix(fail[x], c));
				pats[y].insert(pats[y].end(), pats[fail[y]].begin(), pats[fail[y]].end());
				q.push(y);
			}
		}
	}

	void insert(string str, int id){
		int n = str.size();
		int x = root;
		for(int i = 0; i < n; i++){
			int &y = nxt[x][str[i]-'a']; // Convertendo char pra int, pode ser mais complexo se puder ter letras maiusculas
			if(y == 0 || y == root) y = newnode();
			x = y;
		}
		pats[x].pb(mp(id, n)); //string de id = id termina em x e ela tem tamanho n
	}

	vii match(string str) { // (id, pos)
		int x = root;
		int n =sz(str); 
		vii ans;
		for(int i = 0; i < n; i++){
			x = suffix(x, str[i] - 'a');	
			for(int j = 0; j < sz(pats[x]); j++){
				ii cur = pats[x][j];
				ans.pb(mp(cur.st, i - cur.nd + 1)); //Adiciona na resposta o id da string e onde ela começa
			}
		}
		return ans;
	}

};

int main(){
	AhoCorasick aho = AhoCorasick();
	aho.insert("dezenove", 19);
	aho.insert("vinte", 20);
	aho.insert("guiguima", 5);
	aho.insert("guilherme", 6);
	aho.insert("vintimatar", 21);
	aho.setfails();
	vii result;
	result = aho.match("vintivintevintimatarguilhermguiguimaguilhermedezdezenove");
	for(int i = 0; i < result.size(); i++){
		printf("%d %d\n", result[i].st, result[i].nd);
	}
	
	return 0;
}