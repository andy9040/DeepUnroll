#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int s, w;
  cin >> s >> w;
  if (w >= s) {
    cout << "unsafe\n";
  } else {
    cout << "safe\n";
  }
}
