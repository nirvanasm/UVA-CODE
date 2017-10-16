#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

char maps[8][8];

bool inRange(int x,int y){
	return x>=0&&y>=0&&x<8&&y<8;
}
void turnOver(char &cur){
	if(cur=='B')cur='W';
	else cur='B';
}

bool legal(int x,int y,char ply){
	char trg=(ply=='B')?'W':'B';
	
	for(int i = 0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		if(inRange(nx,ny)&&maps[nx][ny]==trg){
			while(inRange(nx,ny)&&maps[nx][ny]==trg){
				nx+=dx[i];ny+=dy[i];
			}
			if(inRange(nx,ny)&&maps[nx][ny]==ply)return true;
		}
	}
	return false;
}

void move(int x,int y,char ply){
	char trg=(ply=='W')?'B':'W';
	maps[x][y]=ply;
	for(int i = 0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		
		bool turnIt=false;
		
		if(inRange(nx,ny)&&maps[nx][ny]==trg){
			while(inRange(nx,ny)&&maps[nx][ny]==trg){
				nx+=dx[i];ny+=dy[i];
			}
			if(inRange(nx,ny)&&maps[nx][ny]==ply)turnIt=true;
		}
		
		if(turnIt){
			nx=x+dx[i];
			ny=y+dy[i];
			while(inRange(nx,ny)&&maps[nx][ny]==trg){
				turnOver(maps[nx][ny]);
				nx+=dx[i];ny+=dy[i];
			}
		}
	}
}

void lst(char cur){
	vector<ii>ls;
	for(int i = 0;i<8;i++){
		for(int j = 0;j<8;j++){
			if(maps[i][j]!='-')continue;
			if(legal(i,j,cur))ls.pb(ii(i,j));
		}
	}
	if(ls.size()==0)cout<<"No legal move."<<endl;
	else{
		for(int i = 0;i<ls.size();i++){
			if(i)cout<<" ";
			cout<<"("<<ls[i].fi+1<<","<<ls[i].se+1<<")";
		}cout<<endl;
	}
}

int main(){
	int t;cin>>t;cin.get();
	while(t--){
		for(int i =0;i<8;i++){
			for(int j = 0;j<8;j++){
				cin>>maps[i][j];
			}
		}
		
		char cur;cin>>cur;
		
		char cm;
		while(cin>>cm){
			if(cm=='Q')break;
			if(cm=='M'){
				
				char xx,yy;cin>>xx>>yy;
				int x=xx-'0',y=yy-'0';x--;y--;
				
				if(!legal(x,y,cur)){
					turnOver(cur);
				}
				
				move(x,y,cur);
				turnOver(cur);
				
				int bl=0,wh=0;
				for(int i = 0;i<8;i++){
					for(int j = 0;j<8;j++){
						if(maps[i][j]=='B')bl++;
						else if(maps[i][j]=='W')wh++;
					}
				}
				
				printf("Black - %2d White - %2d\n",bl,wh);
				
			}else{
				lst(cur);
			}
		}
		for(int i = 0;i<8;i++){
			for(int j =0;j<8;j++){
				cout<<maps[i][j];
			}cout<<endl;
		}
		if(t)cout<<endl;
	}
}
