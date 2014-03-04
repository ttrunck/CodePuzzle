#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int aux(string & s){
  int i=0, j=1, k=0, len=s.size();
  s+=s;
  while(i<len && j<len){
    if(s[i+k]==s[j+k]){
      k++;
      if(k==len) break;
    }
    else if(s[i+k]<s[j+k]){
      j=max(j+k+1,i+1);
      k=0;
    }
    else{
      i=max(i+k+1,j+1);
      k=0;
    }
  }
  return min(i,j);
}

int main(){
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  while(n--){
    string s;
    cin >> s;
    cout << aux(s)+1 << '\n';
  }
}
