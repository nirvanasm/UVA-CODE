#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

bool maps[5][5];
int num[5][5];

bool inRange(int x,int y){
	return x>=0&&y>=0&&x<5&&y<5;
}

bool win(int x,int y){
	//KIRI KANAN
	int cnt=1;
	int nx=x,ny=y+1;
	while(inRange(nx,ny)&&maps[nx][ny])ny++,cnt++;
	ny=y-1;
	while(inRange(nx,ny)&&maps[nx][ny])ny--,cnt++;
	
	if(cnt==5)return true;
	
	//ATAS BAWAH
	cnt=1;
	nx=x+1,ny=y;
	while(inRange(nx,ny)&&maps[nx][ny])nx++,cnt++;
	nx=x-1;
	while(inRange(nx,ny)&&maps[nx][ny])nx--,cnt++;
	if(cnt==5)return true;
	
	//DIAGONAL
	cnt=1;
	nx=x+1,ny=y+1;
	while(inRange(nx,ny)&&maps[nx][ny])nx++,ny++,cnt++;
	nx=x-1,ny=y-1;
	while(inRange(nx,ny)&&maps[nx][ny])nx--,ny--,cnt++;
	if(cnt==5)return true;
	
	//ANTIDIAGONAL
	
	cnt=1;
	nx=x+1,ny=y-1;
	while(inRange(nx,ny)&&maps[nx][ny])nx++,ny--,cnt++;
	nx=x-1,ny=y+1;
	while(inRange(nx,ny)&&maps[nx][ny])nx--,ny++,cnt++;
	if(cnt==5)return true;
	
	return false;
}

ii koor[100];

int main(){
	int t;cin>>t;
	while(t--){
		memset(maps,0,sizeof maps);
		for(int i = 0;i<100;i++){
			koor[i]=ii(-1,-1);
		}
		for(int i = 0;i<5;i++){
			for(int j = 0;j<5;j++){
				if(i==2&&j==2)maps[i][j]=true;
				else {
					cin>>num[i][j];
					koor[num[i][j]]=ii(i,j);
				}
			}
		}
		int bingo=-1;
		for(int i =0;i<75;i++){
			int a;cin>>a;
			if(bingo!=-1)continue;
			ii xy = koor[a];
			if(xy.fi==-1)continue;
			maps[xy.fi][xy.se]=true;
			
			
			if(win(xy.fi,xy.se)){
				bingo=i+1;
			}
		}
		
		cout<<"BINGO after "<<bingo<<" numbers announced"<<endl;
	}
}
