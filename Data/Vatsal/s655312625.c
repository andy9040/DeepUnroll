#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<list>
#include<algorithm>
  
#define NMAX 2000000+10
using namespace std;
   
  
   
int main(void){
   
    int n;
    string inp;
    int x;
    list<int> data;
    list<int>::iterator iter,fun;
  
    cin>>n;
   
    while(n--){

        cin>>inp;
        
		if(inp.length()!=6){
			if(inp[6]=='F') data.pop_front();
			else if(inp[6]=='L') data.pop_back();
		}
		else{
			cin>>x;
			if(inp[0]=='i') data.push_front(x);
			else{
				fun=find(data.begin(),data.end(),x);
				if(fun!=data.end()) data.erase(fun);
			}
		}
	}
   
    iter=data.begin();
    while(iter!=data.end()){
        if(iter!=data.begin()) cout<<" ";
        cout<<*iter;
        iter++;
    }
    cout<<endl;
  
    return 0;
}