
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define vi                 vector<int>
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define sonic               ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define itr(it,c)           for(auto const &it : c)
#define all(c)              c.begin(), c.end()
#define ff                  first
#define ss                  second
#define INF                 INT_MAX
#define REPl(i,a,b)          for (ll i=a;i<b;i++)
#define REPi(i,a,b)			for (ll i=a;i<b;i++)
//*******Uer-Defined Functions*********//

//*******Functions end here************//
//*******Main func starts**************//
int main()
{
    sonic;
	int s, w;
	cin >> s >> w;
	if (s >= w) cout << "unsafe"<<endl;
	else{
		cout << "safe" << endl;
}
//******Main Ends here****************//