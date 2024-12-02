#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <assert.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a % 3 == 0 || a % 5 == 0) {
      cout << "APPROVED" << endl;
      return 0;
    }
  }
  cout << "DENIED" << endl;
  return 0;
}
