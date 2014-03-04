#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int const N=1000000;

bool palindrome(string s){
  int l=s.size();  
  for(int i=0;i<l;++i)
    if(s[i]!=s[l-1-i]) return false;
  return true;
}

int main(){
  long long res=0;
  for(int i=1;i<N;++i){
    ostringstream oss;
    oss << i;
    if(palindrome(oss.str())){
      ostringstream oss2;
      int tmp=i;
      while(tmp!=0){
	oss2 << (tmp%2);
	tmp/=2;
      }
      if(palindrome(oss2.str())){
	//cout << i << ' ' << oss2.str() << '\n';
	res+=i;
	if(res<=0) cout << "FFFUUUUCKKK\n";
      }
    }
  }
  cout << res << '\n';
}
