#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

struct dt{
	bool bump;
	int cost,val;
	dt(bool a=0,int b=0,int c=0){
		bump=a;
		cost=c;
		val=b;
	}
};

dt maps[105][105];
int r,c;
int wl,p;

bool isWall(int x,int y){
	return x==1||y==1||x==r||y==c;
}

bool inRange(int x,int y){
	return x>=1&&x<=r&&y>=1&&y<=c;
}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
	cin>>r>>c;
	cin>>wl;
	cin>>p;
	
	while(p--){
		int x,y,val,cost;
		cin>>x>>y>>val>>cost;
		maps[x][y]=dt(1,val,cost);
	}
	
	int x,y,dir,life;
	
	int tot=0;
	
	while(cin>>x>>y>>dir>>life){
		int cur=0;
		while(life>0){
			int nx=x+dx[dir];
			int ny=y+dy[dir];
			
			//cout<<x<<" "<<y<<" "<<nx<<" "<<ny<<" "<<life<<endl;
			
			if(isWall(nx,ny)){
				life--;
				if(life>0){
					life-=wl;
					dir=(dir+3)%4;
				}
			}else{
				life--;
				if(life>0){
					if(maps[nx][ny].bump){
						cur+=maps[nx][ny].val;
						life-=maps[nx][ny].cost;
						dir=(dir+3)%4;
					}else{
						x=nx;y=ny;
					}
				}
			}
		}
		cout<<cur<<endl;
		tot+=cur;
	}
	cout<<tot<<endl;
	
}
