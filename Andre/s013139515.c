#include <bits/stdc++.h>
using namespace std;

int main(){
    int s, w;
    cin >> s >> w;
    bool f;
    if(w >= s) f = 1;
    else f = 0;
    cout << (f ? "unsafe" : "safe") << endl;
    return 0;
}
