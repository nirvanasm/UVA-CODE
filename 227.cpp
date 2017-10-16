#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

string maps[5];

bool inRange(int x,int y){
	return x>=0&&x<5&&y>=0&&y<5;
}

int main(){
	int tc=1;
	while(getline(cin,maps[0])){
		if(maps[0]=="Z")break;
		if(tc!=1)cout<<endl;
		for(int i = 1;i<5;i++)getline(cin,maps[i]);
		
		int x,y;
		for(int i = 0;i<5;i++){
			for(int j = 0;j<5;j++){
				if(maps[i][j]==' ')x=i,y=j;
			}
		}
		
		
		bool valid=true;
		
		char cmd;
		while(cin>>cmd){
			if(cmd=='0')break;
			if(!valid)continue;
			int nx=x,ny=y;
			if(cmd=='A'){
				nx-=1;
			}else if(cmd=='B'){
				nx+=1;
			}else if(cmd=='L'){
				ny-=1;
			}else if(cmd=='R'){
				ny+=1;
			}
			
			if(inRange(nx,ny)){
				swap(maps[nx][ny],maps[x][y]);
				x=nx,y=ny;
			}
			else {
				valid=false;
			}
		}
		cin.get();
		cout<<"Puzzle #"<<tc++<<":"<<endl;
		if(valid){
			for(int i = 0;i<5;i++){
				for(int j = 0;j<5;j++){
					if(j)cout<<" ";
					cout<<maps[i][j];
				}cout<<endl;
			}
		}else cout<<"This puzzle has no final configuration."<<endl;
	}
}
