#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,ii>iii;

int mat[1505][1505];
vector<int>adj[1505];
int par[1505];

int bfs(int s,int f){
	memset(par,-1,sizeof par);
	queue<iii>q; q.push(iii(1e5,ii(s,s)));
	
	int ret=0;
	
	while(!q.empty()){
		iii now=q.front();q.pop();
		int mn = now.fi;
		int id = now.se.fi;
		int fr = now.se.se;
		
		if(par[id]!=-1)continue;
		par[id]=fr;
		
		if(id==f){
			ret=mn;
			break;
		}
		
		for(int i = 0;i<adj[id].size();i++){
			int nx=adj[id][i];
			
			if(mat[id][nx]>0){
				q.push(iii(min(mn,mat[id][nx]),ii(nx,id)));
			}
		}
	}
	
//	cout<<"MINIMUM "<<ret<<endl;
	
	if(ret==0)return 0;
	while(par[f]!=f){
		int bef=par[f];
//		cout<<bef<<endl;
		mat[bef][f]-=ret;
		mat[f][bef]+=ret;
		f=bef;
	}
	return ret;
}

int main(){
	int t;cin>>t;
	cin.get();
	cin.get();
	
	while(t--){
		string s;
			
		for(int i = 0;i<1505;i++){
			adj[i].clear();
			for(int j = 0;j<1505;j++){
				mat[i][j]=0;
			}
		}
		
		map<string,int>name, pol, clb;
		vector<string>encode;
		set<int>politic,club,listName;
		
		int cnt=0;
		
		while(getline(cin,s)&&s.length()>0){
			stringstream ss(s);
			string curName, curParty;
			ss >> curName >> curParty;
			
			int idxName, idxParty;
			
			if(name.count(curName))idxName = name[curName];
			else{
				idxName = name[curName] = cnt++;
				listName.insert(idxName);
				encode.pb(curName);
			}
			
			if(pol.count(curParty))idxParty = pol[curParty];
			else{
				idxParty = pol[curParty] = cnt++;
				politic.insert(idxParty);
				encode.pb(curParty);
			}
			
			mat[idxName][idxParty] = 1;
			adj[idxName].pb(idxParty);
			adj[idxParty].pb(idxName);
			
			string clubName;
			
			while(ss>>clubName){
				int idxClub;
				
				if(clb.count(clubName))idxClub = clb[clubName];
				else{
					idxClub = clb[clubName] = cnt++;
					club.insert(idxClub);
					encode.pb(clubName);
				}
				
				mat[idxClub][idxName]=1;
				adj[idxClub].pb(idxName);
				adj[idxName].pb(idxClub);
			}
		}
		
		int totClub = club.size();
		int maxCap = (totClub-1)/2;
		
		for(set<int>::iterator it = politic.begin();it != politic.end(); it++){
			int cur=*it;
			mat[cur][cnt+2]=maxCap;
			adj[cur].pb(cnt+2);
			adj[cnt+2].pb(cur);
		}
		
		for(set<int>::iterator it = club.begin();it != club.end(); it++){
			int cur=*it;
			mat[cnt+1][cur]=1;
			adj[cnt+1].pb(cur);
			adj[cur].pb(cnt+1);
		}
		
//		for(int i = 0;i<encode.size();i++){
//			cout<<i<<" --> ";
//			if(listName.count(i))cout<<"PEOPLE";
//			else if(club.count(i))cout<<"CLUB";
//			else cout<<"POLITIC";
//			cout<<" "<<encode[i]<<endl;
//		}
		
		int flow = 0;
		while(true){
			int val = bfs(cnt+1,cnt+2);
			if(val==0)break;
			flow+=val;
		}
		
//		for(int i = 0;i<cnt+3;i++){
//			for(int j = 0;j<cnt+3;j++){
//				cout<<mat[i][j]<<" ";
//			}cout<<endl;
//		}
		
		if(flow!=totClub)cout<<"Impossible."<<endl;
		else{
			for(set<int>::iterator it=listName.begin(); it!=listName.end();it++){
//				cout<<encode[*it]<<" --> "<<*it<<endl;
				int cur = *it;
				for(int i = 0;i<adj[cur].size();i++){
					int nx = adj[cur][i];
//					cout<<"NEXT --> "<<encode[nx]<<" "<<mat[cur][nx]<<" "<<mat[nx][cur]<<endl;
					if(!club.count(nx))continue;
					
					if(mat[cur][nx]==1 && mat[nx][cur]==0){
						cout<<encode[cur]<<" "<<encode[nx]<<endl;
						break;
					}
				}
			}
		}
		if(t)cout<<endl;
	}
}
