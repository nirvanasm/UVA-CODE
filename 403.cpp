#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

//CHARACTER IN 5*6
string ls[26][5]={
	(".***.."),
	("*...*."),
	("*****."),
	("*...*."),
	("*...*."),
	
	("****.."),
	("*...*."),
	("****.."),
	("*...*."),
	("****.."),
	
	(".****."),
	("*...*."),
	("*....."),
	("*....."),
	(".****."),
	
	("****.."),
	("*...*."),
	("*...*."),
	("*...*."),
	("****.."),
	
	("*****."),
	("*....."),
	("***..."),
	("*....."),
	("*****."),
	
	("*****."),
	("*....."),
	("***..."),
	("*....."),
	("*....."),
	
	(".****."),
	("*....."),
	("*..**."),
	("*...*."),
	(".***.."),
	
	("*...*."),
	("*...*."),
	("*****."),
	("*...*."),
	("*...*."),
	
	("*****."),
	("..*..."),
	("..*..."),
	("..*..."),
	("*****."),
	
	("..***."),
	("...*.."),
	("...*.."),
	("*..*.."),
	(".**..."),
	
	("*...*."),
	("*..*.."),
	("***..."),
	("*..*.."),
	("*...*."),
	
	("*....."),
	("*....."),
	("*....."),
	("*....."),
	("*****."),
	
	("*...*."),
	("**.**."),
	("*.*.*."),
	("*...*."),
	("*...*."),
	
	("*...*."),
	("**..*."),
	("*.*.*."),
	("*..**."),
	("*...*."),
	
	(".***.."),
	("*...*."),
	("*...*."),
	("*...*."),
	(".***.."),
	
	("****.."),
	("*...*."),
	("****.."),
	("*....."),
	("*....."),
	
	(".***.."),
	("*...*."),
	("*...*."),
	("*..**."),
	(".****."),
	
	("****.."),
	("*...*."),
	("****.."),
	("*..*.."),
	("*...*."),
	
	(".****."),
	("*....."),
	(".***.."),
	("....*."),
	("****.."),
	
	("*****."),
	("*.*.*."),
	("..*..."),
	("..*..."),
	(".***.."),
	
	("*...*."),
	("*...*."),
	("*...*."),
	("*...*."),
	(".***.."),
	
	("*...*."),
	("*...*."),
	(".*.*.."),
	(".*.*.."),
	("..*..."),
	
	("*...*."),
	("*...*."),
	("*.*.*."),
	("**.**."),
	("*...*."),
	
	("*...*."),
	(".*.*.."),
	("..*..."),
	(".*.*.."),
	("*...*."),
	
	("*...*."),
	(".*.*.."),
	("..*..."),
	("..*..."),
	("..*..."),
	
	("*****."),
	("...*.."),
	("..*..."),
	(".*...."),
	("*****."),
	
};

char ans[65][65];

bool inRange(int x,int y){
	return x>=1&&y>=1&&x<=60&&y<=60;
}

void P(){
	string x;cin>>x;
	bool big=false;
	if(x=="C5")big=true;
	int r,c;cin>>r>>c;
	getline(cin,x);
	while(x[0]!='|')x.erase(0,1);
	x.erase(0,1);
	while(x[x.length()-1]!='|')x.erase(x.length()-1,1);
	x.erase(x.length()-1,1);
	
	if(big){
		for(int i = 0;i<x.length();i++){
			if(isspace(x[i])){
				c+=6;
				continue;
			}
			
			int id=x[i]-'A';
			
			for(int j = r;j<r+5;j++){
				for(int k = c;k<c+6;k++){				
					if(inRange(j,k)&&ls[id][j-r][k-c]=='*')ans[j][k]=ls[id][j-r][k-c];
				}
			}
			
			c+=6;
		}
	}else{
		for(int i = 0;i<x.length();i++){
			if(isspace(x[i])){
				c++;continue;
			}
			if(inRange(r,c))ans[r][c++]=x[i];
		}
	}
}

void L(){
	string x;cin>>x;
	bool big=false;
	if(x=="C5")big=true;
	int r,c;cin>>r;c=1;
	getline(cin,x);
	while(x[0]!='|')x.erase(0,1);
	x.erase(0,1);
	while(x[x.length()-1]!='|')x.erase(x.length()-1,1);
	x.erase(x.length()-1,1);
	
	if(big){
		for(int i = 0;i<x.length();i++){
			if(isspace(x[i])){
				c+=6;
				continue;
			}
			
			int id=x[i]-'A';
			
			for(int j = r;j<r+5;j++){
				for(int k = c;k<c+6;k++){				
					if(inRange(j,k)&&ls[id][j-r][k-c]=='*')ans[j][k]=ls[id][j-r][k-c];
				}
			}
			
			c+=6;
		}
	}else{
		for(int i = 0;i<x.length();i++){
			if(isspace(x[i])){
				c++;continue;
			}
			if(inRange(r,c))ans[r][c++]=x[i];
		}
	}
}

void R(){
	string x;cin>>x;
	bool big=false;
	if(x=="C5")big=true;
	int r,c;cin>>r;c=60;
	getline(cin,x);
	while(x[0]!='|')x.erase(0,1);
	x.erase(0,1);
	while(x[x.length()-1]!='|')x.erase(x.length()-1,1);
	x.erase(x.length()-1,1);
	
	if(big){
		for(int i = (int)(x.length())-1;i>=0;i--){
			if(isspace(x[i])){
				c-=6;
				continue;
			}
			
			int id=x[i]-'A';
			
			for(int j = r;j<r+5;j++){
				for(int k = c;k>=c-5;k--){				
					if(inRange(j,k)&&ls[id][j-r][k-c+5]=='*')ans[j][k]=ls[id][j-r][k-c+5];
				}
			}
			
			c-=6;
		}
	}else{
		for(int i = (int)(x.length())-1;i>=0;i--){
			if(isspace(x[i])){
				c--;continue;
			}
			if(inRange(r,c))ans[r][c--]=x[i];
		}
	}
}

void C(){
	string x;cin>>x;
	bool big=false;
	if(x=="C5")big=true;
	int r,c;cin>>r;
	getline(cin,x);
	while(x[0]!='|')x.erase(0,1);
	x.erase(0,1);
	while(x[x.length()-1]!='|')x.erase(x.length()-1,1);
	x.erase(x.length()-1,1);
	
	if(big){
		c = 30-(x.length())*3+1;
		for(int i = 0;i<x.length();i++){
			if(isspace(x[i])){
				c+=6;
				continue;
			}
			
			int id=x[i]-'A';
			
			for(int j = r;j<r+5;j++){
				for(int k = c;k<c+6;k++){				
					if(inRange(j,k)&&ls[id][j-r][k-c]=='*')ans[j][k]=ls[id][j-r][k-c];
				}
			}
			
			c+=6;
		}
	}else{
		c = 30-((x.length())/2)+1;
		for(int i = 0;i<x.length();i++){
			if(isspace(x[i])){
				c++;continue;
			}
			if(inRange(r,c))ans[r][c++]=x[i];
		}
	}
}

int main(){
	string s;
//	freopen("out.txt","w",stdout);
	
	while(cin>>s){
		for(int i =0;i<65;i++){
			for(int j = 0;j<65;j++){
				ans[i][j]='.';
			}
		}
		while(s!=".EOP"){
			if(s==".P")P();
			if(s==".L")L();
			if(s==".R")R();
			if(s==".C")C();
			cin>>s;
		}
		
		for(int i = 1;i<=60;i++){
			for(int j = 1;j<=60;j++){
				cout<<ans[i][j];
			}cout<<endl;
		}
		cout<<endl;
		for(int i = 1;i<=60;i++)cout<<"-";
		cout<<endl<<endl;
		
	}
}
