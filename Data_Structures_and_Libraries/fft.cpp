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


typedef complex<double> base;

vector<base> recursive_fft(vector<base> a, bool invert){
	int n = sz(a);
	if(n == 1) return a;
	double ang = 2*acos(-1.0)/n * (invert ? -1: 1);
	base wn(cos(ang), sin(ang));
	base w(1);
	vector<base> even;
	vector<base> odd;
	for(int i = 0; i < n; i++){
		if(i%2) odd.pb(a[i]);
		else even.pb(a[i]);
	}
	even = recursive_fft(even, invert);
	odd = recursive_fft(odd, invert);
	vector<base> y(n, base(0));
	for(int i = 0; i < n/2;i++){
		y[i] = even[i] + w*odd[i];
		y[i + n/2] = even[i] - w*odd[i];
		w*=wn;
	}
	return y;
}

void fft(vector<base> &a, bool invert){
	int n = sz(a);
	for(int i = 1, j = 0; i < n; i++){
		int bit = n >> 1;
		for(; j >= bit; bit >>= 1) j-=bit;
		j+=bit;
		if(i < j) swap(a[i], a[j]);
	}
	for(int len = 2; len <= n; len <<= 1){
		double ang = 2*acos(-1.0)/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for(int i = 0; i < n; i+=len){
			base w(1);
			for(int j = 0; j < len/2; j++){
				base u = a[i+j], v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j + len/2] = u - v;
				w *= wlen;
			}
		}
	}
	for(int i = 0; invert && i < n; i++) a[i]/=n;
}

void convolution(vector<base> & a, vector<base> & b, vector<base> & c) {
	int n = 1;
	while(n < (int)max(a.size(), b.size())) n <<=1;
	n <<= 1;
	a.resize(n); b.resize(n);
	fft(a, false); fft(b, false);
	c.resize(n);
	for(int i=0; i<n; i++) c[i] = a[i]*b[i];
	fft(c, true);
}

vector<base> convolution2(vector<base> a, vector<base> b){
	int n = 1;
	while(n < (int)max(a.size(), b.size())) n <<=1;
	n <<= 1;
	a.resize(n); b.resize(n);
	vector<base> y1 = recursive_fft(a, false); 
	vector<base> y2 = recursive_fft(b, false);
	vector<base> c;
	c.resize(n);
	for(int i=0; i<n; i++) c[i] = y1[i]*y2[i];
	c = recursive_fft(c, true);
	for(int i=0; i < n; i++) c[i]/=n;
	return c;
}

int main(){
	// vector<base> a, b;
	// for(int i = 0; i < 15; i++){
	// 	a.pb(i);
	// }

	// for(int i = 19; i >= 0; i--){
	// 	b.pb(i);
	// }
	// vector<base> c;
	// convolution(a, b, c);
	// for(int i = 0; i < c.size(); i++){
	// 	cout << c[i].real() << " ";
	// }
	// cout << endl;

	// vector<base> d, y;
	// for(int i = 0; i < 4; i++){
	// 	d.pb(2*i);
	// }
	// d.resize(8);
	// y = recursive_fft(d, false);
	// fft(d, false);
	// for(int i = 0; i < d.size(); i++){
	// 	cout << d[i] << endl;
	// }
	// for(int i = 0; i < y.size(); i++){
	// 	cout << y[i] << endl;
	// }

	vector<base> a,b,c,d;

	for(int i = 0; i < 7; i++) a.pb(i*19);
	for(int i = 0; i < 12; i++) b.pb(i*3);


	d = convolution2(a, b);
	convolution(a, b, c);

	for(int i = 0; i < c.size(); i++){
		cout << c[i].real() << " ";
	}
	cout << endl;
	for(int i = 0; i < d.size(); i++){
		cout << d[i].real() << " ";
	}
	cout << endl;

	return 0;
}
