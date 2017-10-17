#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

char maps[5][5];

bool inRange(int x,int y){
	return x>=0&&y>=0&&x<3&&y<3;
}

bool win(int x,int y){
	//KIRI KANAN
	int cnt=1;
	int nx=x,ny=y+1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])ny++,cnt++;
	ny=y-1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])ny--,cnt++;
	
	if(cnt==3)return true;
	
	//ATAS BAWAH
	cnt=1;
	nx=x+1,ny=y;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])nx++,cnt++;
	nx=x-1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])nx--,cnt++;
	if(cnt==3)return true;
	
	//DIAGONAL
	cnt=1;
	nx=x+1,ny=y+1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])nx++,ny++,cnt++;
	nx=x-1,ny=y-1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])nx--,ny--,cnt++;
	if(cnt==3)return true;
	
	//ANTIDIAGONAL
	
	cnt=1;
	nx=x+1,ny=y-1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])nx++,ny--,cnt++;
	nx=x-1,ny=y+1;
	while(inRange(nx,ny)&&maps[nx][ny]==maps[x][y])nx--,ny++,cnt++;
	if(cnt==3)return true;
	
	return false;
}

int main(){
	int t;cin>>t;
	while(t--){
		int cntx=0,cnto=0;
		for(int i =0;i<3;i++){
			for(int j = 0;j<3;j++){
				cin>>maps[i][j];
				if(maps[i][j]=='X')cntx++;
				else if(maps[i][j]=='O')cnto++;
			}
		}
		
		bool winx=false,wino=false;
		
		for(int i = 0;i<3;i++){
			for(int j = 0;j<3;j++){
				if(maps[i][j]=='X')winx|=win(i,j);
				else if(maps[i][j]=='O')wino|=win(i,j);
			}
		}
		
		if(cntx<cnto||cntx-1>cnto)cout<<"no"<<endl;
		else if(wino&&cntx!=cnto)cout<<"no"<<endl;
		else if(winx&&cntx!=cnto+1)cout<<"no"<<endl;
		else if(winx&&wino)cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
}
