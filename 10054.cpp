#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

vector<int>adj[55];
int mat[55][55];
int deg[55];
vector<int>ans;

void rmvEdge(int a,int b){
	mat[a][b]--;
	mat[b][a]--;
}

void addEdge(int a,int b){
	mat[a][b]++;
	mat[b][a]++;
}

bool vis[55];

void dfs(int idx){
	for(int i = 0;i<adj[idx].size();i++){
		int nex = adj[idx][i];
		if(mat[idx][nex]==0)continue;
		rmvEdge(idx,nex);
		dfs(nex);
	}
	ans.pb(idx);
}

int isEuler(int idx){
	if(vis[idx])return 0;
	vis[idx]=true;
	
	int ret = (deg[idx]%2==1);
	for(int i = 0;i<adj[idx].size();i++){
		int nx = adj[idx][i];
		ret += isEuler(nx);
	}
	
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int t;cin>>t;
	int tc=1;
	int n;
	while(t--){
		cin>>n;
		memset(mat,0,sizeof mat);
		memset(deg,0,sizeof deg);
		for(int i = 0;i<55;i++)adj[i].clear();
		
		for(int i = 0;i<n;i++){
			int a,b;cin>>a>>b;
			deg[a]++;
			deg[b]++;
			if(mat[a][b]==0){
				adj[a].pb(b);
				adj[b].pb(a);
			}
			addEdge(a,b);
			
		}
		
		memset(vis,0,sizeof vis);
		ans.clear();
		for(int i = 1;i<=50;i++){
			if(adj[i].size()==0)continue;
			if(vis[i])continue;
			int val = isEuler(i);
			if(val>2)continue;
			
			dfs(i);
			break;
		}
		
		if(tc!=1)cout<<endl;
		cout<<"Case #"<<tc++<<endl;
		if(ans.size()==0)cout<<"some beads may be lost"<<endl;
		else{
			for(int i = 0;i<ans.size()-1;i++){
				cout<<ans[i]<<" "<<ans[i+1]<<endl;
			}
		}
		
	}
}
