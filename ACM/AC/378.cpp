#include<iostream>
#include<iomanip>

using namespace std;

int main(){
  int N;
  cin >> N;
  cout << "INTERSECTING LINES OUTPUT\n";
  while(N--){
    double ax,ay,bx,by,cx,cy,dx,dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double num=(ay-cy)*(dx-cx)-(ax-cx)*(dy-cy);
    double den=(bx-ax)*(dy-cy)-(by-ay)*(dx-cx);
    if(num==0)
      cout << "LINE\n";
    else if(den==0)
      cout << "NONE\n";
    else{
      cout << "POINT ";
      cout << setprecision(2) << fixed << ax+num/den*(bx-ax) << ' ' << ay+num/den*(by-ay) << '\n';
    }

  }
    cout << "END OF OUTPUT\n";
}
