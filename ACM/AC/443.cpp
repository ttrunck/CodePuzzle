#include<vector>
#include<iostream>
#include<string>

using namespace std;

const int N=5842;

string aux(int n){
  if(n%10==1 && n%100!=11) return "st";
  if(n%10==2 && n%100!=12) return "nd";
  if(n%10==3 && n%100!=13) return "rd";
  return "th";
}

int main(){
  vector<int> h(N+1);
  
  int p1(0), p2(0), p3(0), p4(0), end(0);
  h[0]=1;
  while(end<N){
    while(h[p1]*2<=h[end])++p1;
    while(h[p2]*3<=h[end])++p2;
    while(h[p3]*5<=h[end])++p3;
    while(h[p4]*7<=h[end])++p4;
    if(h[p1]*2<h[p2]*3 && h[p1]*2<h[p3]*5 && h[p1]*2<h[p4]*7)
      h[++end]=h[p1++]*2;
    else if(h[p2]*3<h[p3]*5 && h[p2]*3<h[p4]*7)
      h[++end]=h[p2++]*3;
    else if(h[p3]*5<h[p4]*7)
      h[++end]=h[p3++]*5;
    else h[++end]=h[p4++]*7;
  }
  
  // for(int i=0;i<20;++i)
  //   cerr << h[i] << ' ';
  // cerr << endl;

  int n;
  while(cin >> n && n){
    cout << "The " << n << aux(n) << " humble number is " << h[n-1] << ".\n";
  }
}
