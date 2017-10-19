#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;

int dsu[100005];

int find(int x){
	if(dsu[x]==x)return x;
	return dsu[x]=find(dsu[x]);
}

bool merge(int x,int y){
	int a=find(x);
	int b=find(y);
	if(a==b)return false;
	dsu[a]=b;
	return true;
}

vector<iii>adj;

bool cmp(iii a,iii b){
	return a.fi>b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		adj.clear();
		int n,m;cin>>n>>m;
		int tot=0;
		for(int i = 1;i<=n;i++)dsu[i]=i;
		for(int i = 0;i<m;i++){
			int a,b,c;cin>>a>>b>>c;
			tot+=c;
			adj.pb(iii(c,ii(b,a)));
		}
		sort(adj.begin(),adj.end(),cmp);
		for(int i = 0;i<m;i++){
			int fr=adj[i].se.fi;
			int to=adj[i].se.se;
			if(merge(fr,to)){
				tot-=adj[i].fi;
			}
		}
		cout<<tot<<endl;
	}
	cin>>t;
}
