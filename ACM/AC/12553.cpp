#include<iostream>
#include<vector>
#include<string>

using namespace std;

inline int abs(int a){
  return (a>0)?a:-a;
}

struct op{
  int a, b;
  char r;
  op(int aa, int bb, char cc):a(aa), b(bb), r(cc){};
};

vector<op> s_final;

void op_print(op p){
  cout << p.a << ' ' << p.r << ' ' << p.b << " = ";
  if(p.r=='+')
    cout << p.a+p.b;
  else if(p.r=='-')
    cout << p.a-p.b;
  else if(p.r=='*')
    cout << p.a*p.b;
  else if(p.r=='/')
    cout << p.a/p.b;
  cout << '\n';
}

void approx(vector<int> & t, const int T, int & opt, vector<op> & s){

  if(opt==T)
    return;
  
  if(t.size()==1){
    if(abs(T-t[0])<abs(T-opt)){
      s_final.clear();
      for(int i=0;i<int(s.size());++i)
	s_final.push_back(s[i]);
      opt=t[0];
    }
    return;
  }
  
  int a=t[0];
  t[0]=t.back();
  t.pop_back();
  approx(t,T,opt,s);
  t.push_back(t[0]);
  t[0]=a;

  for(int i=0;i<int(t.size());++i)
    for(int j=i+1;j<int(t.size());++j){
      int a=t[i];
      int b=t[j];
      t[j]=t[t.size()-1];      
      t.pop_back();   
      t[i]=t[t.size()-1];
      t.pop_back();

      t.push_back(a+b);
      op p(a,b,'+');
      s.push_back(p);
      approx(t,T,opt,s);

      if(a>b){
	op p(a,b,'-');
	s[s.size()-1]=p;
	t[t.size()-1]=(a-b);
	approx(t,T,opt,s);
      }
      
      if(b>a){
	op p(b,a,'-');
	s[s.size()-1]=p;
	t[t.size()-1]=(b-a);
	approx(t,T,opt,s);
      }

      if(a*b!=0){
	op p(a,b,'*');
	s[s.size()-1]=p;
	t[t.size()-1]=(a*b);
	approx(t,T,opt,s);
      }

      if(b!=0 && (a%b)==0){
	op p(a,b,'/');
	s[s.size()-1]=p;
	t[t.size()-1]=(a/b);
	approx(t,T,opt,s);
      }

      if(a!=0 && (b%a)==0){
	op p(b,a,'/');
	s[s.size()-1]=p;
	t[t.size()-1]=(b/a);
	approx(t,T,opt,s);
      }

      t.pop_back();
      s.pop_back();

      t.push_back(t[i]);
      t.push_back(t[j]);
      t[j]=b;
      t[i]=a;
    }
}

int main(){
  ios::sync_with_stdio(false);
  int C;
  cin >> C;
  while(C--){
    int T;
    vector<int> t;
    for(int i=0;i<6;++i){
      int tmp;
      cin >> tmp;
      if(tmp!=0)
	t.push_back(tmp);
    }
    if(t.size()==0)
      t.push_back(0);

    cin >> T;
    cout << "Target: " << T << '\n';
    s_final.clear();
    int opt = t[0];
    vector<op> s;
    approx(t, T, opt, s);

    for(int i=0;i<int(s_final.size());++i)
      op_print(s_final[i]);
    cout << "Best approx: " << opt << "\n\n";
  }
}
