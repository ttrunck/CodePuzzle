#include<sstream>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

 class KeyDungeonDiv2
        { 
        public: 
        int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) 
            { 
	      int res=0;
	      for(int i=0;i<int(doorR.size());++i){
		int rest = max(doorR[i]-keys[0],0)+max(doorG[i]-keys[1],0);
		if(rest<=keys[2])
		  res++;
	      }
	      return res;
            } 
        
 
        }; 



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
