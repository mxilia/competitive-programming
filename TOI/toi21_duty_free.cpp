#include <bits/stdc++.h>
using namespace std; 

int p[2000050];
vector<int> vec;

int fSet(int n){
	if(p[n]==n) return n;
	return p[n]=fSet(p[n]);
}

void uSet(int c, int p){
	::p[c]=p;
	vec.push_back(c);
}

int minimum_bag_rearrangement_time(vector<int> max_allowed_positions) {
	int ans = 0;
	int n = max_allowed_positions.size();
	iota(p+1,p+n+1,1);
	for(int i=0;i<n;i++){
		int e = max_allowed_positions[i];
		int pa = fSet(e);
		if(pa==0){
			ans++;
			for(auto &f:vec) p[f]=f;
			vec.clear();
			uSet(e, e-1);
		}
		else uSet(pa, fSet(pa-1));
	}
  	return ans;
}