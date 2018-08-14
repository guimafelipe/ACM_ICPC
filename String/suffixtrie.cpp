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

#define NALF 26

class Node{
public:
	char val;
	int s_ending, w_ending;
	Node *next[NALF];

	Node(char val){
		this->val = val;
		s_ending = 0;
		w_ending = 0;
	}

	void add_child(char val){
		if(next[val-'a'] != NULL) return;
		next[val - 'a'] = new Node(val);
	}

	Node* get_next(char val){
		return next[val -'a'];
	}

	void set_s_end(){
		s_ending++;
	}

	void set_w_end(){
		w_ending++;
	}
};

class SuffixTrie{
public:
	Node *root;

	SuffixTrie(){
		root = new Node('\0');
	}

	void insert_word(string str){
		int n = str.size();
		for(int i = 1; i < n; i++){
			insert_suffix(str.substr(i, n-i), false);
		}
		insert_suffix(str, true);
	}

	void insert_suffix(string str, bool is_full){
		Node *curr = root;
		int n = str.size();
		for(int i = 0; i < n; i++){
			curr->add_child(str[i]);
			curr = curr->get_next(str[i]);
		}
		if(is_full) curr->set_w_end();
		curr->set_s_end();
	}

	Node* search(string str){
		Node *curr = root;
		int n = str.size();
		for(int i = 0; i < n && curr != NULL; i++){
			curr = curr->get_next(str[i]);
		}
		return curr;
	}

	bool check_word(string str){
		Node* curr = search(str);
		if(curr == NULL) return false;
		if(curr->w_ending > 0) return true;
		return false;
	}

	bool check_suffix(string str){
		Node* curr = search(str);
		if(curr == NULL) return false;
		if(curr->s_ending > 0) return true;
		return false;
	}
};

int main(){
	SuffixTrie *st = new SuffixTrie();

	st->insert_word("cat");
	st->insert_word("car");
	st->insert_word("rat");
	assert(st->check_word("car") == true);
	assert(st->check_word("cad") == false);
	assert(st->check_suffix("ar") == true);
	assert(st->check_suffix("ra") == false);

	return 0;
}