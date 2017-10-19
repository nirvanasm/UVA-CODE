#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<string,string>ss;

bool vis[1000005];
int ar[50005];
stack<int>st;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0;i<n;i++){
		scanf("%d",ar+i);
	}
	
	while(m--){
		char q[2];scanf("%s",&q);
		int a,b;scanf("%d%d",&a,&b);
		if(q[0]=='Q'){
			int ans=0;
			for(int i = a;i<b;i++){
				if(!vis[ar[i]]){
					st.push(ar[i]);
					vis[ar[i]]=true;
					ans++;
				}
			}
			printf("%d\n",ans);
			while(!st.empty()){
				vis[st.top()]=false;
				st.pop();
			}
		}else{
			ar[a]=b;
		}
	}
}
