#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<string,int>si;

char ans[25][25];
char tmp[25][25];

void print(){
	cout<<"********************"<<endl;
	for(int i = 1;i<=20;i++){
		for(int j = 1;j<=20;j++){
			cout<<ans[i][j];
		}cout<<endl;
	}
}

void clear(){
	for(int i = 1;i<=20;i++){
		for(int j = 1;j<=20;j++){
			ans[i][j]=' ';
		}
	}
}

int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

bool inRange(int x,int y){
	return x>=1&&x<=20&&y>=1&&y<=20;
}

int adj(int x,int y){
	int ret=0;
	for(int i = 0;i<8;i++){
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(inRange(nx,ny)&&ans[nx][ny]=='O')ret++;
	}
	return ret;
}

void work(){
	for(int i = 1;i<=20;i++){
		for(int j = 1;j<=20;j++){
			tmp[i][j]=' ';
		}
	}
	for(int i = 1;i<=20;i++){
		for(int j = 1;j<=20;j++){
			int val=adj(i,j);
			if(ans[i][j]==' '){
				if(val==3)tmp[i][j]='O';
			}else{
				if(val==2||val==3)tmp[i][j]='O';
			}
		}
	}
	for(int i = 1;i<=20;i++){
		for(int j = 1;j<=20;j++){
			ans[i][j]=tmp[i][j];
		}
	}
}

int main(){
//	freopen("out.txt","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		cin.get();clear();
		string s;
		while(getline(cin,s)){
			if(s=="")break;
			stringstream ss(s);
			int x,y;ss>>x>>y;
			ans[x][y]='O';
		}
		
		while(n--){
			print();
			work();
		}
		
		cout<<"********************"<<endl;
		if(t)cout<<endl;
	}
}
