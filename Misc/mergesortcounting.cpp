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

vi bailarinas;
vi max_dir;
vi min_dir;

ll resp = 0;
int n;

void merge(int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp bailarinasays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp bailarinasays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = bailarinas[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = bailarinas[m + 1+ j]; 
  
    /* Merge the temp bailarinasays back into bailarinas[l..r]*/
    i = 0; // Initial index of first subbailarinasay 
    j = 0; // Initial index of second subbailarinasay 
    k = l; // Initial index of merged subbailarinasay 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            bailarinas[k] = L[i]; 
            i++; 
        } 
        else
        { 
            bailarinas[k] = R[j]; 
            resp+=(n1 - i);
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    {
        bailarinas[k] = L[i];
        i++;
        k++;
    }
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        bailarinas[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int l, int r) { 
    if (l < r) { 
        int m = l+(r-l)/2; 
  
        mergeSort(l, m); 
        mergeSort(m+1, r); 
  
        merge(l, m, r); 
    } 
} 

int main(){
	cin >> n;
	for(int i = 0; i < n ; i++){
		int aux;
		scanf("%d", &aux);
		bailarinas.pb(aux);
	}

	// max_dir.assign(n, 0);
	// min_dir.assign(n, 0);
	// max_dir[n-1] = min_dir[n-1] = bailarinas[n-1];
	// for(int i = n-2; i >= 0; i--){
	// 	max_dir[i] = max(max_dir[i+1], bailarinas[i]);
	// 	min_dir[i] = min(min_dir[i+1], bailarinas[i]);
	// }

	// for(int i = 0; i < n; i++){
	// 	for(int j = i+1; j < n; j++){
	// 		if(bailarinas[i] > max_dir[j]){
	// 			resp += n - j;
	// 			break;
	// 		} else if(bailarinas[i] < min_dir[j]){
	// 			break;
	// 		}
	// 		if(bailarinas[i] > bailarinas[i+1]) resp++;
	// 	}
	// }

	mergeSort(0, n-1);
	// for(int i = 0; i < n ; i++){
	// 	cout << bailarinas[i] << " ";
	// }

	cout << resp << endl;
	
	return 0;
}