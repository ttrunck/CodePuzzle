#include<iostream>
#include<string>

using namespace std;

int convert(const string & s){
  if(s=="No") return 0;
  else if(s=="+y") return 1;
  else if(s=="-y") return 2;
  else if(s=="+z") return 3;
  else return 4;
}

string convert(int x){
  switch(x){
  case 1: return "+x";
  case 2: return "-x";
  case 3: return "+y";
  case 4: return "-y";
  case 5: return "+z";
  default: return "-z";
  }
}

int main(){
  int l;
  while(cin >> l && l){
    int curr=1;
    for(int i=0;i<l-1;++i){
      string tmp;
      cin >> tmp;
      int dir=convert(tmp);
      switch(curr){
      case 1:
	switch(dir){
	case 0:
	  curr=curr;
	  break;
	case 1:
	  curr=3;
	  break;
	case 2:
	  curr=4;
	  break;
	case 3:
	  curr=5;
	  break;
	case 4:
	  curr=6;
	  break;
	}
	break;
      
      case 2:
	switch(dir){
	case 0:
	  curr=curr;
	  break;
	case 1:
	  curr=4;
	  break;
	case 2:
	  curr=3;
	  break;
	case 3:
	  curr=6;
	  break;
	case 4:
	  curr=5;
	  break;
	}
	break;

      case 3:
	switch(dir){
	case 0:
	  curr=curr;
	  break;
	case 1:
	  curr=2;
	  break;
	case 2:
	  curr=1;
	  break;
	case 3:
	  curr=curr;
	  break;
	case 4:
	  curr=curr;
	  break;
	}
	break;

      case 4:
	switch(dir){
	case 0:
	  curr=curr;
	  break;
	case 1:
	  curr=1;
	  break;
	case 2:
	  curr=2;
	  break;
	case 3:
	  curr=curr;
	  break;
	case 4:
	  curr=curr;
	  break;
	}
	break;

      case 5:
	switch(dir){
	case 0:
	  curr=curr;
	  break;
	case 1:
	  curr=curr;
	  break;
	case 2:
	  curr=curr;
	  break;
	case 3:
	  curr=2;
	  break;
	case 4:
	  curr=1;
	  break;
	}
	break;

      case 6:
	switch(dir){
	case 0:
	  curr=curr;
	  break;
	case 1:
	  curr=curr;
	  break;
	case 2:
	  curr=curr;
	  break;
	case 3:
	  curr=1;
	  break;
	case 4:
	  curr=2;
	  break;
	}
	break;

      }
    }

    cout << convert(curr) << '\n';

  }
}
