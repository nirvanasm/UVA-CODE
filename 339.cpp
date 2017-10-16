#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,string>si;

int maps[105][105];
bool vis[105][105];
int r,c;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

bool inRange(int x,int y){
	return x>=0&&y>=0&&x<r&&y<c;
}

int ff(int x,int y){
	vis[x][y]=true;
	int ret=1;
	for(int i  =0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(inRange(nx,ny)&&!vis[nx][ny]&&maps[nx][ny]==maps[x][y])ret+=ff(nx,ny);
	}
	return ret;
}

void del(int x,int y,int trg){
	maps[x][y]=-1;
	for(int i  =0;i<4;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(inRange(nx,ny)&&maps[nx][ny]==trg)del(nx,ny,trg);
	}
}

void down(){
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			if(maps[i][j]==-1){
				int x=i;
				while(x>0){
					swap(maps[x-1][j],maps[x][j]);
					x--;
				}
			}
		}
	}
}

void lft(){
	for(int i = c-1;i>=0;i--){
		bool almin=true;
		for(int j = 0;j<r;j++){
			if(maps[j][i]!=-1)almin=false;
		}
		if(almin){
			int y=i;
			while(y+1<c){
				for(int j =0;j<r;j++){
					swap(maps[j][y],maps[j][y+1]);
				}
				y++;
			}
		}
	}
}

bool empty(){
	for(int i = 0;i<r;i++){
		for(int j = 0;j<c;j++){
			if(maps[i][j]!=-1)return false;
		}
	}
	return true;
}

int main(){
	int tc=1;
	while(cin>>r>>c){
		if(r==0||c==0)break;
		memset(maps,-1,sizeof maps);
		for(int i  =r-1;i>=0;i--){
			for(int j = 0;j<c;j++){
				cin>>maps[i][j];
			}
		}
		
//		for(int i = 0;i<r;i++){
//			for(int j = 0;j<c;j++){
//				cout<<maps[i][j]<<" ";
//			}cout<<endl;
//		}
		
		int x,y;
		while(cin>>x>>y){
			if(x==0)break;
			x--;y--;x=r-x-1;
			if(!inRange(x,y))continue;
			if(maps[x][y]==-1)continue;
			memset(vis,0,sizeof vis);
			if(ff(x,y)<2)continue;
			else{
				del(x,y,maps[x][y]);
				down();lft();
			}
//			for(int i = 0;i<r;i++){
//				cout<<"    ";
//				for(int j = 0;j<c;j++){
//					if(j)cout<<" ";
//					if(maps[i][j]==-1)cout<<" ";
//					else cout<<maps[i][j];
//				}cout<<endl;
//			}
		}
		if(tc!=1)cout<<endl;
		cout<<"Grid "<<tc++<<"."<<endl;
		if(empty())cout<<"    Game Won"<<endl;
		else{
			for(int i = 0;i<r;i++){
				cout<<"    ";
				for(int j = 0;j<c;j++){
					if(j)cout<<" ";
					if(maps[i][j]==-1)cout<<" ";
					else cout<<maps[i][j];
				}cout<<endl;
			}
		}
	}
	
}
