#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,string>si;

char maps[15][15];
int num[15][15];

int main(){
	int tc=1;
	int r,c;
	while(cin>>r){
		if(r==0)break;
		cin>>c;
		cin.get();
		int cnt=1;
		for(int i = 0;i<15;i++){
			for(int j = 0;j<15;j++){
				maps[i][j]='*';
				num[i][j]=0;
			}
		}
		
		for(int i = 1;i<=r;i++){
			for(int j = 1;j<=c;j++){
				cin>>maps[i][j];
			}
		}
		
		for(int i = 1;i<=r;i++){
			for(int j = 1;j<=c;j++){
				if(maps[i][j]=='*')continue;
				if(maps[i-1][j]=='*')num[i][j]=cnt++;
				else if(maps[i][j-1]=='*')num[i][j]=cnt++;
			}
		}
		
		if(tc!=1)cout<<endl;
		cout<<"puzzle #"<<tc++<<":"<<endl;
		//ACROSS
		cout<<"Across"<<endl;
		for(int i = 1;i<=r;i++){
			int col=1;
			string cur;
			while(col<=c+1){
				if(maps[i][col]=='*'){
					if(cur==""){
						col++;
						continue;
					}
					printf("%3d.%s\n",num[i][col-cur.length()],cur.c_str());
					cur="";
				}else{
					cur+=maps[i][col];
				}
				col++;
			}
		}
		//DOWN
		cout<<"Down"<<endl;
		vector<si>ls;
		for(int i = 1;i<=c;i++){
			int row=1;
			string cur;
			while(row<=r+1){
				if(maps[row][i]=='*'){
					if(cur==""){
						row++;continue;
					}
					ls.pb(si(num[row-cur.length()][i],cur));
					cur="";
				}else{
					cur+=maps[row][i];
				}
				row++;
			}
		}
		
		sort(ls.begin(),ls.end());
		
		for(int i = 0;i<ls.size();i++){
			printf("%3d.%s\n",ls[i].fi,ls[i].se.c_str());
		}
	}
	
}
