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
	return a.fi<b.fi;
}

int main(){
	ios_base::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		vector<ii>koor;
		vector<iii>adj;
		int k;cin>>k;
		int x,y;
		while(cin>>x){
			if(x==-1)break;
			cin>>y;
			for(int i = 0;i<koor.size();i++){
				ll xx = x-koor[i].fi;
				ll yy = y-koor[i].se;
				ll dist = ceil(sqrt(xx*xx+yy*yy));
				adj.pb(iii(dist,ii(i,koor.size())));
			}
			koor.pb(ii(x,y));
		}
		sort(adj.begin(),adj.end(),cmp);
		for(int i = 0;i<koor.size();i++)dsu[i]=i;
		vector<int>ans;
		
		for(int i = 0;i<adj.size();i++){
			if(merge(adj[i].se.fi,adj[i].se.se)){
				ans.pb(adj[i].fi);
			}
		}
		int out=0;
		for(int i = (int)(ans.size())-k;i>=0;i--){
			out=max(out,ans[i]);
		}
		cout<<out<<endl;
	}
}
