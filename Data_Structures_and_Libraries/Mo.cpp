int getAns(int i, int e){}

void removeMo(int pos){}

void includeMo(int pos){}

int MoBucket;
bool MoComp(ii p1, ii p2){
	ll val1(p1.first/MoBucket), val2(p2.first/MoBucket);
	if(val1==val2) return mp(p1.second, p1.first)<mp(p2.second, p2.first);
	else return val1<val2;
}

vi index;
void MoSort(vector<ii> &v){
	index.assign(v.size(),0);
	iota(all(index), 0);
	sort(all(index), [&](int i, int j){return MoComp(v[i],v[j]);});
	sort(all(v), MoComp);
}

template<typename T>
void MoDesort(vector<T> &vi){
	vector<T> next(vi);
	for(int i =	0; i<vi.size(); ++i){
		next[index[i]] = vi[i];
	}
	vi = next;
}

vi doMo(vector<ii> &queries, int Q){
	int currL(0), currR(0);
	MoBucket = max((int)sqrt(Q),1);
	MoSort(queries);
	vi ans;
	for(auto &p:queries){
		int L = p.st-1, R = p.nd; //From [currL, currR) -> [L,R)
		while(currR<R)	includeMo(currR++);
		while(currL>L)	includeMo(--currL);
		while(currR>R)	removeMo(--currR);
		while(currL<L)	removeMo(currL++);
		ans.pb(getAns(L,R));
	}
	MoDesort(ans);
	return ans;
}
