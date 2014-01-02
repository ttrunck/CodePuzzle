#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef long long ll;
const vector<char> t{'A', 'B', 'C'};

ll compute(char first1, char last1, ll nb1, char first2, char last2, ll nb2, int k){
  if(k==1)
    return nb1;
  char first3=first1, last3=last2;
  ll nb3=nb1+nb2;
  if(last1=='A' && first2=='C')
    ++nb3;
  return compute(first2, last2, nb2, first3, last3, nb3, k-1);
}

bool poss(string& s, char first, char last, int nb){
  int n=s.size();
  if(n==1){
    s[0]=first;
    return (nb==0 && first==last);
  }
  s[0]=first;
  s[n-1]=last;
  if(n==2)
    return (nb==1 && first=='A' && last=='C') || (nb==0 && (first!='A' || last!='C'));
  
  int pos=1;
  while(nb>0 && pos<n-2){
    if(s[pos-1]=='A'){
      s[pos]='C';
      --nb;
    }
    else
      s[pos]='A';
    ++pos;
  }

  if(nb==0){
    while(pos<n-1) s[pos++]='B';
    return true;
  }

  if(nb>1)
    return false;
  
  if(s[pos-1]=='A'){
    s[pos]='C';
    return true;
  }

  if(s[n-1]=='C'){
    s[pos]='A';
    return true;
  }
  
  return false;
}

int main(){
  int k, x, n, m;
  cin >> k >> x >> n >> m;

  string res1(n,'A'), res2(m,'A');

  for(char first1:t)
    for(char first2:t)
      for(char last1:t)
	for(char last2:t)
	  for(int nb1=0;nb1<=n/2;++nb1)
	    for(int nb2=0;nb2<=m/2;++nb2)
	      if(compute(first1, last1, nb1, first2, last2, nb2, k)==x){
		cerr << first1 << ' ' << last1 << ' ' << nb1 << ' ' << poss(res1, first1, last1, nb1) << ' '
		     << first2 << ' ' << last2 << ' ' << nb2 << ' ' << poss(res2, first2, last2, nb2) << endl;
		if(poss(res1, first1, last1, nb1) && poss(res2, first2, last2, nb2)){
		  cout << res1 << '\n';
		  cout << res2 << '\n';
		  return 0;
		}
	      }
  cout << "Happy new year!\n";
}
