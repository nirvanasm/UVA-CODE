#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,string>si;

map<int,ii> ec;
map<ii,int> hsh;

void pre(){
	int cnt=1;
	for(int i = 0;i<2;i++){
		for(int j = 2;j<5;j++){
			hsh[ii(i,j)]=cnt;
			ec[cnt++]=ii(i,j);
		}
	}
	for(int i = 2;i<5;i++){
		for(int j = 0;j<7;j++){
			hsh[ii(i,j)]=cnt;
			ec[cnt++]=ii(i,j);
		}
	}
	for(int i = 5;i<7;i++){
		for(int j = 2;j<5;j++){
			hsh[ii(i,j)]=cnt;
			ec[cnt++]=ii(i,j);
		}
	}
}

bool maps[10][10];

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool inRange(int x,int y){
	return hsh.count(ii(x,y));
}

bool move(){
	int mx=0,fr=0;
	for(int i = 0;i<7;i++){
		for(int j = 0;j<7;j++){
			if(maps[i][j]){
				
				int from = hsh[ii(i,j)];
				for(int k = 0;k<4;k++){
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(inRange(nx,ny)&&maps[nx][ny]){
						
						if(inRange(nx+dx[k],ny+dy[k])&&!maps[nx+dx[k]][ny+dy[k]]){
							int val=hsh[ii(nx+dx[k],ny+dy[k])];
							
							if(val==mx){
								if(fr<from)fr=from;
							}else if(val>mx){
								mx=val;fr=from;
							}
						}
					}
				}
			}
		}
	}
	
	if(mx==0)return false;
	
	ii f = ec[mx];//FINISH
	ii s = ec[fr];//START
	
	maps[s.fi][s.se]=false;
	maps[f.fi][f.se]=true;
	
	if(s.fi==f.fi){
		if(s.se<f.se){//MOVE DOWN
			maps[s.fi][s.se+1]=false;
		}else{
			maps[s.fi][s.se-1]=false;
		}
	}else{
		if(s.fi<f.fi){
			maps[s.fi+1][s.se]=false;
		}else{
			maps[s.fi-1][s.se]=false;
		}
	}
	
	return true;
}

int main(){
	int n;cin>>n;
	pre();
	cout<<"HI Q OUTPUT"<<endl;
	while(n--){
		int a;
		memset(maps,0,sizeof maps);
		while(cin>>a){
			if(a==0)break;
			ii cur = ec[a];
			maps[cur.fi][cur.se]=true;
		}
	
		while(move());
		
		int ans=0;
		
		for(int i = 0;i<7;i++){
			for(int j =0;j<7;j++){
				if(maps[i][j]){
					
					ans+=hsh[ii(i,j)];
				}
			}
		}
		cout<<ans<<endl;
	}
	cout<<"END OF OUTPUT"<<endl;
}
