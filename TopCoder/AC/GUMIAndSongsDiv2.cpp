#include<sstream>
#include<string>
#include<vector>
#include<iostream>
#include<cassert>
#include<algorithm>

using namespace std;

int aux(const int done, const int T, const vector<int>& duration, const vector<int>& tone){
  int N=duration.size();
  
  bool first=true;
  int t_tot=0;
  int res=0;
  int tone_=0;
  
  for(int i=0;i<N;++i){
    if((done&(1<<i))!=0){
      if(first){
	first=false;
	++res;
	t_tot+=duration[i];
	tone_=tone[i];
      }
      else{
	++res;
	t_tot+=duration[i]+abs(tone_ - tone[i]);
	tone_=tone[i];
      }
    }
  }
  if(t_tot<=T) return res;
  return -1;
}

 class GUMIAndSongsDiv2
        { 
        public: 
        int maxSongs(vector <int> duration, vector <int> tone, int T) 
            { 
	      int N=duration.size();	      
	      for(int i=0;i<N;++i)
		for(int j=0;j<N-1;++j)
		  if(tone[j+1]>tone[j]){
		    swap(tone[j], tone[j+1]);
		    swap(duration[j], duration[j+1]);
		  }

	      /*
	      for(int i=0;i<N;++i)
		cerr << duration[i] << ' ';
	      cerr << endl;
	      for(int i=0;i<N;++i)
		cerr << tone[i] << ' ';
	      cerr << endl;
	      */
	      int res=0;
	      for(int i=0;i<(1<<N);++i)
		res=max(res, aux(i,T,duration, tone));
	      return res;
	  
	    };
        
 
        }; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
