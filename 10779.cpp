#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;

int mat[55][55];
int par[55];
vector<int>adj[55];
int n,m;

bool stick(int x){
	return x>n&&x<=n+m;
}

int bfs(int s,int f){
	memset(par,-1,sizeof par);
	queue<iii>q;q.push(iii(1e9,ii(s,s)));
	
	int ret=0;
	
	while(!q.empty()){
		iii now=q.front();q.pop();
		int mn = now.fi;
		int id = now.se.fi;
		int fr = now.se.se;
		
		if(par[id]!=-1)continue;
		par[id]=fr;
		
		if(id==f){
			ret = mn;
			break;
		}
		
//		cout<<id<<" "<<fr<<endl;
		
		for(int i = 0;i<adj[id].size();i++){
			int nx=adj[id][i];
//			cout<<" --> "<<nx<<endl;
			if(mat[id][nx]>0){
				q.push(iii(min(mn,mat[id][nx]),ii(nx,id)));
			}
		}
	}
	
	if(ret==0)return 0;
	while(par[f]!=f){
		int bef=par[f];
		mat[bef][f]-=ret;
		mat[f][bef]+=ret;
		f=bef;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	int tc=1;
	while(t--){
		memset(mat,0,sizeof mat);
		for(int i =0;i<55;i++)adj[i].clear();
		cin>>n>>m;
		for(int i = 1;i<=n;i++){
			int a;cin>>a;
			for(int j = 0;j<a;j++){
				int b;cin>>b;
				mat[i][b+n]++;
			}
			for(int j = n+1;j<=n+m;j++){
				if(mat[i][j]==0){
					mat[j][i]=1;
				}else if(mat[i][j]>0){
					if(i!=1)mat[i][j]--;
				}
				adj[i].pb(j);
				adj[j].pb(i);
			}
		}
//		cout<<"LIST"<<endl;
//		for(int i = 0;i<adj[3].size();i++){
//			cout<<adj[3][i]<<" ";
//		}cout<<endl;
		
		int sink = n+m+1;
		for(int i = n+1;i<=n+m;i++){
			mat[i][sink]=1;
			adj[i].pb(sink);
			adj[sink].pb(i);
		}
		
		int ans=0;
		while(true){
			int val=bfs(1,sink);
			if(val==0)break;
			ans+=val;
//			for(int i = 1;i<=n+m+1;i++){
//				for(int j = 1;j<=n+m+1;j++){
//					cout<<mat[i][j]<<" ";
//				}cout<<endl;
//			}cout<<endl;
		}
		
		cout<<"Case #"<<tc++<<": "<<ans<<"\n";
	}
}
