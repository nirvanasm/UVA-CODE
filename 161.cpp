#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

bool gr[105][18005];
int val[105];
int cnt;

void proc(int x){
	int l=0,r=x-5;
	while(l<=18000){
		for(int i = l;i<r;i++)gr[cnt][i]=true;
		l=r+x+5;r=l+x-5;
		if(r>18000)r=18001;
	}
	cnt++;
}

int main(){
	int x;
	while(cin>>x){
		if(x==0)break;
		cnt=0;
		memset(gr,0,sizeof gr);
		val[cnt]=x;proc(x);
		while(cin>>x){
			if(x==0)break;
			val[cnt]=x;proc(x);
		}
		
		int ans=-1;
		
		for(int i = 10;i<=18000;i++){
			bool ok=true;int n=0;
			for(int j = 0;j<cnt;j++){
				if(!gr[j][i]){
					ok=false;
					break;
				}
				if(i<val[j]){
					n++;
				}
			}
			if(ok&&cnt!=n){
				ans=i;
				break;
			}
		}
		
		if(ans==-1)cout<<"Signals fail to synchronise in 5 hours"<<endl;
		else printf("%02d:%02d:%02d\n",ans/3600,(ans/60)%60,ans%60);
	}
}
