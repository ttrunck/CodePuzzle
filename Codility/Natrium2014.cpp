#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

typedef pair<int, int> pi;

int dico(const vector<pi>& t, int elt){
	int lo=0, hi=t.size();
	while(lo!=hi){
		int x = (lo+hi)/2;
		if(t[x].first>elt)
			lo=x+1;
		else
			hi=x;
	}
	return lo;
}

int solution(vector<int>& A){
	vector<pi> t;
	t.push_back(pi(A[0], 0));
	int res = 0;

	for(int i=0;i<int(A.size());++i){
		if(A[i]<t.back().first)
			t.push_back(pi(A[i], i));
	
		res = max(res, i-t[dico(t, A[i])].second);
	}

	return res;
}

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;++i)
		cin >> a[i];

	cout << solution(a) << endl;
}