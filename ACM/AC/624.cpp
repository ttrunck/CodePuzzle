#include<iostream>
#include<vector>

using namespace std;

int N, nb;
vector<int> t;
vector<int> res;
int val;

int pow(int a, int b){
  if(b==0) return 1;
  int tmp=pow(a, b/2);
  if(b%2==0) return tmp*tmp;
  else return tmp*tmp*a;
}

int main(){
  while(cin >> N){
    t.clear();
    res.clear();
    val=0;
    cin >> nb;
    for(int i=0;i<nb;++i){
      int tmp;
      cin >> tmp;
      t.push_back(tmp);
    }

    int BOUND=pow(2, nb);
    for(int i=0;i<BOUND;++i){
      int curr=0;
      int nn=i;
      for(int j=0;j<nb;++j){
	if(nn%2==0){
	  curr+=t[j];
	}
	  nn/=2;
      }
      if(curr<=N && curr>val){
	res.clear();
	nn=i;
	for(int j=0;j<nb;++j){
	  if(nn%2==0)
	    res.push_back(t[j]);
	  nn/=2;
	}
	val=curr;
      }
    }

    for(int i=0;i<res.size();++i)
      cout << res[i] << ' ';
    cout << "sum:" << val << endl;
  }
}
