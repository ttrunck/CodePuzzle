#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cassert>
#include<queue>

using namespace std;

template<typename RandomAccessIterator, typename GetFonction>
void radix_sort(RandomAccessIterator begin, RandomAccessIterator end, GetFonction getValue){
  const int digits = 2;        	 //Digits
  const int r = 8;                 //Bits
  const int radix = 1 << r;         //Bins
  const int mask = radix - 1;  

  vector< typename iterator_traits<RandomAccessIterator>::value_type > B(end-begin);
  vector<int> cnt(radix);
  for(int pass = 0, shift = 0; pass < digits   ; ++pass, shift += r){
    cnt.assign(radix,0);
    for(RandomAccessIterator it=begin;it!=end;++it)
      cnt[(getValue(*it) >> shift) & mask]++;
    for(int i = 1; i < radix; ++i)
      cnt[i] += cnt[i - 1];
  
    for(RandomAccessIterator it=end-1;it!=begin;--it)
      B[--cnt[((getValue(*it) >> shift) & mask)]] = *it;
    B[--cnt[((getValue(*begin) >> shift) & mask)]] = *begin;

    int curr=0;
    for(RandomAccessIterator it=begin;it!=end;++it)
      *it = B[curr++];
  }
}

struct entry{
  pair<int, int> p;
  int pos;
  bool operator < (const entry & a) const{
    return p<a.p;
  }
};

int f1(const entry & a){
  return a.p.first;
}

int f2(const entry & a){
  return a.p.second;
}

void concrete_suffix(const string & s, vector<vector<int> > & p){
  int N=s.size();
 
  p.push_back(vector<int>(N));
  for(int i = 0; i < N; i++)
    p[0][i] = s[i] - 'a';
  
  for(int stp = 1, k = 1; k/2 < N; ++stp, k *=2 ){
    p.push_back(vector<int>(N));
    vector<entry> tmp(N);
    for(int i = 0; i < N; i ++){
      tmp[i].p.first = p[stp - 1][i];
      tmp[i].p.second = i + k < N ? p[stp - 1][i + k] : -1;
      tmp[i].pos = i;
    }

    sort(tmp.begin(), tmp.end());
    //radix_sort(tmp.begin(), tmp.end(), f2);
    //radix_sort(tmp.begin(), tmp.end(), f1);


    p[stp][tmp[0].pos]=0; 
    for(int i = 1; i < N; i ++)
      p[stp][tmp[i].pos]=(tmp[i].p==tmp[i-1].p)?p[stp][tmp[i-1].pos]:i; 
  }
}

int lcp(int x, int y, const vector<vector<int> > & p, const string & s){
  if(x==y) return s.size()-x;
  if(s[x]!=s[y]) return 0;
  int res=0;
  int k=p.size()-1;
  while(k>=0 && x<int(s.size()) && y<int(s.size())){
    if(p[k][x]==p[k][y]){
      res+= (1<<k);
      x+= (1<<k);
      y+= (1<<k);
    }
    k--;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  // freopen("substr.in", "r", stdin);
  int m;
  string s;
  while(cin >> m >> s && m){
    if(m==1){
      cout << s.size() << " 0\n";
    }
    else{
    vector<vector<int> > t;
    concrete_suffix(s, t);

    vector<int> suf(s.size());
    for(int i=0;i<int(t[t.size()-1].size());++i)
      suf[t[t.size()-1][i]]=i;
   
    int maxi=0;
    int res=0;

    priority_queue<pair<int, int > > rangs;
    for (int i = 0; i < m-1; i++)
      rangs.push(make_pair(suf[i], i));

    for(int i=0;i+m-1<int(suf.size());++i){
      rangs.push(make_pair(suf[i+m-1], i+m-1));
      int tmp=lcp(suf[i], suf[i+m-1], t, s);
      
      if(maxi<tmp){
	while (rangs.top().second < i)
	  rangs.pop();
	maxi=tmp;
	res=rangs.top().first;
      }
	else if(maxi==tmp){
	  while (rangs.top().second < i)
	  rangs.pop();
	  res=max(res, rangs.top().first);
	}
    
      
    }
    if(maxi>0)
      cout << maxi << ' ' << res << '\n';
    else
      cout << "none\n";
    }
  }
}
