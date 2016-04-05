#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

typedef unsigned int uint;

int main()
{
  int size = 32;

  vector<uint> a{0xb0c152f9, 0xebf2831f};
  vector<uint> b(size/16, 0);

  /*
  for (int i = 0; i < size / 16; i++) {
    cin >> hex >> a[i];
  }
  */
for (int j = 0; j < size; j++)
  for (int i = 0; i < size; i++)

    {
      b[(i + j) / 32] ^= ( (a[i / 32] >> (i % 32)) &
		       (a[j / 32 + size / 32] >> (j % 32)) & 1 ) << ((i + j) % 32);
  }

  for(int i = 0; i < size / 16; i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << setfill('0') << setw(8) << hex << b[i];
  }
  cout << endl;
}
