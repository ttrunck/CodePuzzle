#include <iostream>
#include <vector>

using namespace std;

const int P = 10000000;

int main() {
  vector<bool> prime(P, true);
  vector<int> p;
  prime[0] = prime[1] = false;
  for(int i=2;i<P;++i)
    if(prime[i]) {
      p.push_back(i);
      for(int j=i+i;j<P;j+=i)
        prime[j] = false;
      }

  int n;
  cin >> n;

  vector<int> constPrime {
    3,
    10000019,
    15000031,
    20000033,
    25000069,
    30000071,
    35000083,
    40000123,
    45000133,
    50000141,
    55000163,
    60000209,
    65000213,
    70000267,
    75000271,
    80000273,
    85000283,
    90000293,
    95000303,
    100000357,
    105000361,
    110000377,
    115000409,
    120000449,
    125000461,
    130000469,
    135000499,
    140000503,
    145000507,
    150000517,
    155000533,
    160000541,
    165000553,
    170000557,
    175000559,
    180000571,
    185000597,
    190000633,
    195000653,
    200000677,
    205000711,
    210000737,
    215000741,
    220000763,
    225000767,
    230000773,
    235000811,
    240000821,
    245000831,
    250000843,
    255000847,
    260000857,
    265000889,
    270000893,
    275000911,
    280000927,
    285000929,
    290000959,
    295000969,
    300000991,
    305001007,
    310001011,
    315001039,
    320001043,
    325001059,
    330001109,
    335001137,
    340001141,
    345001147,
    350001181,
    355001189,
    360001207,
    365001209,
    370001237,
    375001247,
    380001257,
    385001297,
    390001327,
    395001361,
    400001369,
    405001393,
    410001409,
    415001429,
    420001453,
    425001461,
    430001479,
    435001487,
    440001503,
    445001521,
    450001523,
    455001563,
    460001579,
    465001601,
    470001617,
    475001627,
    480001631,
    485001641,
    490001651,
    495001669,
    500001707,
    505001719,
    510001741,
    515001827,
    520001857,
    525001859,
    530001863,
    535001869,
    540001871,
    545001881,
    550001917,
    555001921,
    560001983,
    565002013,
    570002039,
    575002061,
    580002083,
    585002111,
    590002151,
    595002173,
    600002189,
    605002193,
    610002199,
    615002233,
    620002241,
    625002269,
    630002297,
    635002339,
    640002359,
    645002387,
    650002399,
    655002419,
    660002423,
    665002433,
    670002439,
    675002443,
    680002459,
    685002467,
    690002471,
    695002481,
    700002487,
    705002497,
    710002499,
    715002503,
    720002531,
    725002583,
    730002599,
    735002623,
    740002661,
    745002667,
    750002681,
    755002747,
    760002779,
    765002789,
    770002823,
    775002841,
    780002849,
    785002853,
    790002859,
    795002893,
    800002897,
    805002929,
    810002933,
    815002939,
    820003001,
    825003043,
    830003123,
    835003129,
    840003137,
    845003179,
    850003199,
    855003221,
    860003231,
    865003267,
    870003287,
    875003291,
    880003321,
    885003331,
    890003333,
    895003349,
    900003361,
    905003389,
    910003399,
    915003431,
    920003449,
    925003463,
    930003467,
    935003479,
    940003487,
    945003523,
    950003539,
    955003541,
    960003581,
    965003609,
    970003651,
    975003683,
    980003693,
    985003717,
    990003737,
    995003753
  };

  vector<int> res;
  for(int i=constPrime.size()-1;i>=0;--i) {
    int x = constPrime[i];
    if(x<n-2) {
      n -= x;
      res.push_back(x);
      break;
    }
  }

  for(int i=0;i<p.size();++i) {
    if(p[i] == n) {
      res.push_back(p[i]);
      break;
    }
    if(prime[n-p[i]]) {
      res.push_back(p[i]);
      res.push_back(n-p[i]);
      break;
    }
  }

  cout << res.size() << '\n';
  for(int x:res)
    cout << x << ' ';
}
