#include<cstdio>
#include<set>

using namespace std;

int main(){
  int n;
  scanf("%d",&n);
  while(n!=0){
    long long res=0;
    multiset<int> s;
    for(int i=0;i<n;++i){
      int k;
      scanf("%d",&k);
      for(int j=0;j<k;++j){
	int tmp;
	scanf("%d",&tmp);
	s.insert(tmp);
      }
      res-=*(s.begin());
      res+=*(--s.end());
      s.erase(s.begin());
      s.erase(--s.end());
    }
    printf("%lld\n", res);
  scanf("%d",&n);    
  }
}
