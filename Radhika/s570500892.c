#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;
constexpr int INF = 2e9;
int main(){ 
  int a, b;
  cin >> a >> b;
  if (a <= b) cout << "unsafe" << endl;
  else cout << "safe" << endl;
  return 0;
} 