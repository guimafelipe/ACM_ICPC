//Basic Math

#include <bits/stdc++.h>
//
#define EPS 10e-6

//v = vetor dos coeficiente an, an-1, an-2...

using namespace std;

double logN(double a, double b){
	return log(a)/log(b);
}

vector<double> integratePoly(vector<double> &v){
	vector<double> ans(v.size()+1,0);
	for(int i = 0; i<v.size()-1; ++i){
		ans[i] = v[i]/(v.size()-i);
	}
	return ans;
}

double evaluateHorner(vector<double> &v, double x){
	double val = 0;
	for(double coef:v){
		val*=x;
		val+=coef;
	}
	return val;
}

double ruffiniDivision(vector<double> &px, double r, vector<double> &ans){
	ans.resize(px.size()-1);
	double curr(0);
	for(int i = 0; i<px.size()-1; ++i){
		curr*=r;
		curr+=px[i];
		ans[i] = curr;
	}
	return px.back()+curr*r; //remain;	
}

vector<double> derivePoly(vector<double> &v){
	vector<double> ans(v.size()-1);
	for(int i = 0; i<v.size()-1; ++i){
		ans[i] = (v.size()-i-1)*v[i];
	}
	return ans;
}

double newtonRoot(vector<double> &v, bool &conv, double guess = INT_MAX){
	if(v.size()==2){
		conv=true;
		return v.back();
	}
	vector<double> vlinha = derivePoly(v);
	double last(guess-1);
	int i = 200;
	while(abs(guess-last)>EPS&&i--){
		last = guess;
		guess = guess - evaluateHorner(v, guess)/evaluateHorner(vlinha, guess);
	}
	conv = (abs(guess-last)<=EPS);
	//cout<<endl<<"Intermediary Res: "<<last<<" "<<guess<<" "<<(last-guess)<<" "<<conv<<" "<<(199-i);
	return guess;
}

vector<double> getAllRoots(vector<double> v){
	vector<double> roots;
	bool conv(true);
	vector<double> nextV;
	double guess = INT_MAX;
	while(v.size()>1){
		//cout<<endl<<"Intermediary V:";
		//for(double d:v) cout<<" "<<d;
		double root = newtonRoot(v,conv,guess);
		roots.push_back(root);
		ruffiniDivision(v, root, nextV);
		swap(v,nextV);
		guess = root;
		//cout<<endl<<"Intermediary V:";
		//for(double d:v) cout<<" "<<d;
		//cout<<endl<<"Root "<<root<<" "<<evaluateHorner(nextV, root);
	}
	return roots;
}

//------------------------

class getComb{
public:
	vector<vector<long long>> combs;
	
	getComb(int n):combs(n,vector<long long>(n,-1)){}
	
	get(int n, int k){
		if(k>n-k)	k = n-k;
		long long &val = combs[n][k];
		if(val!=-1) return val;
		if(!k)	val = 1;
		else val = get(n-1,k-1) + get(n-1,k);
		return val;
	}
};

class getCatalan{
public:
	vector<long long> catal;
	
	getComb(int n):catal(n,-1){}
	
	get(long long m){
		long long &val = catal[n];
		if(val!=-1) return val;
		if(!m)	val = 1;
		else	val = get(m-1)*2*m*(2*m-1)/((m+1)*m);
		return val;
	}
};

//-----------------------------------------
typedef long long ll;
typedef vector<int> vi;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++){
		if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i){
				bs[j] = 0;
			}
			primes.push_back((int)i);
		}
	} 
}

ll _sieve_size;
vi lp;
vi primes;

void euler_sieve(ll upperbound){
	_sieve_size = upperbound+1;
	lp.assign(_sieve_size, 0);
	for(int i = 2; i < _sieve_size; ++i){
		if(lp[i] == 0){
			lp[i] = i;
			primes.pb(i);
		} 
		for(int j = 0; j < primes.size() && primes[j] <= lp[i] && i*primes[j] < _sieve_size; ++j){
			lp[i*primes[j]] = primes[j];
		}
	}
}

bool isPrime(ll n) { // a good enough deterministic prime tester
	if (n <= _sieve_size) return bs[n]; // O(1) for small primes

	for (int i = 0; i < (int)primes.size(); i++){
		if (n % primes[i] == 0) return false;
	}
	return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in vi "primes")^2
//------------------------------------------


vi getPrimeFact(ll n) {
	ll ind = 0, pf = primes[0];
	vi ans;
	while (pf*pf <= n) {
		while (n % pf == 0) {
			n /= pf;
			ans.pb(PF); 
		}
		pf = primes[++ind];
	}
	if (n != 1) ans.pb(n);
	return ans;
}

ll numDiv(ll n) {
	ll ind = 0, pf = primes[0], ans = 1; // start from ans = 1
	while (pf*pf <= n) {
		ll power = 0; // count the power
		while (n % pf == 0) {
			n /= pf;
			power++; 
		}
		ans *= (power + 1); // according to the formula
		pf = primes[++ind];
	}
	if (n != 1) ans *= 2; // (last factor has pow = 1, we add 1 to it)
	return ans;
}


//-----------------------------------------
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }

//------------------------------------------

ll EulerPhi(ll N) { //Pra um número
	ll ind = 0, pf = primes[0], ans = n; // start from ans = N
	while (pf*pf <= n) {
		if (n % pf == 0) ans -= ans / pf; // only count unique factor
		while (n % pf == 0) n /= pf;
			pf = primes[++ind];
	}
	if (n != 1) ans -= ans / n; // last factor
	return ans;
}

int EulerPhi[1000001]
void PreProcessEulerPhi(){
	EulerPhi
	for (int i = 1; i <= 1000000; i++) EulerPhi[i] = i;
	for (int i = 2; i <= 1000000; i++)
		if (EulerPhi[i] == i) // i is a prime number
			for (int j = i; j <= 1000000; j += i)
				EulerPhi[j] = (EulerPhi[j] / i) * (i - 1);
}


