#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll C[2005][2005];
ll dp[100005][13];


int main(){
    int S,W;
    cin >> S >> W;
    if (S<=W) {
        cout << "unsafe" << endl;
    }else{
        cout << "safe" << endl;
    }
}