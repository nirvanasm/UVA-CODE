#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;

int main(){
	ll a,b;int tc=1;
	while(cin>>a>>b){
		if(a==0&&b==0)break;
		cout<<"Case "<<tc++<<": "<<a*(a-1)/2*b*(b-1)/2<<endl;
	}
}
