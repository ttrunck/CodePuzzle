#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool verif(int n, vector<int> d1, vector<int> d2){
  int a=n%10;
  int b=n/10;

  return(
	 (count(d1.begin(),d1.end(),a)>0 && count(d2.begin(),d2.end(),b)>0)
	 ||(count(d1.begin(),d1.end(),b)>0 && count(d2.begin(),d2.end(),a)>0)
	 );
}

bool ver(vector<int> d1, vector<int> d2){
  return (
	  verif(1,d1,d2)
	  && verif(4,d1,d2)
	  && (verif(9,d1,d2) || verif(6,d1,d2))
	  && (verif(16,d1,d2) || verif(19,d1,d2))
	  && verif(25,d1,d2)
	  && (verif(36,d1,d2) || verif(39,d1,d2))
	  && (verif(49,d1,d2) || verif(46,d1,d2))
	  && (verif(64,d1,d2) || verif(94,d1,d2))
	  && verif(81,d1,d2)
	  );
}

void print(vector<int> d){
  for(int i=0;i<d.size();++i)
    cout << d[i] << ' ';
  cout << '\n';
}

int main(){
  int res=0;
  vector<int> d1;
  vector<int> d2;
  
    for(int n1=0;n1<5;++n1)
      for(int n2=n1+1;n2<6;++n2)
	for(int n3=n2+1;n3<7;++n3)
	  for(int n4=n3+1;n4<8;++n4)
	    for(int n5=n4+1;n5<9;++n5)
	      for(int n6=n5+1;n6<10;++n6)
		for(int m1=0;m1<5;++m1)
		  for(int m2=m1+1;m2<6;++m2)
		    for(int m3=m2+1;m3<7;++m3)
		      for(int m4=m3+1;m4<8;++m4)
			for(int m5=m4+1;m5<9;++m5)
			  for(int m6=m5+1;m6<10;++m6)
			    {
			      d1.clear();
			      d2.clear();
			      d1.push_back(n1);
			      d1.push_back(n2);
			      d1.push_back(n3);
			      d1.push_back(n4);
			      d1.push_back(n5);
			      d1.push_back(n6);
			      d2.push_back(m1);
			      d2.push_back(m2);
			      d2.push_back(m3);
			      d2.push_back(m4);
			      d2.push_back(m5);
			      d2.push_back(m6);
			      if(ver(d1,d2)){
				print(d1);
				print(d2);
				cout << "-----------\n";
				res++;
			      }
			    }
    
    cout << res/2 << '\n';
}
