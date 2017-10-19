#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;

ll dp[15];

ll rec(int n){
	if(n<=1)return 1;
	if(dp[n]!=-1)return dp[n];
	ll ret=0;
	for(int i = 1;i<=n;i++){
		ret+=rec(i-1)*rec(n-i);
	}
	return dp[n]=ret;
}

int main(){
	memset(dp,-1,sizeof dp);
	int n;bool fi=true;
	while(cin>>n){
		if(!fi)cout<<endl;
		fi=false;
		cout<<rec(n)<<endl;
	}
}
