#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

vector<string>ls;

int ar[255];
int tmp[2005][255];

string s;
vector<string>ill;

bool found(string x){
	for(int i = 0;i<ill.size();i++){
		if(x==ill[i])return true;
	}
	return false;
}

void rec(int idx,vector<string>ans){
//	cout<<idx<<endl;
//	for(int i = 'A';i<='Z';i++){
//		cout<<ar[i]<<" ";
//	}cout<<endl;
//	cout<<"LIST"<<endl;
//	for(int i = 0;i<ans.size();i++){
//		cout<<ans[i]<<endl;
//	}cout<<endl;
	
	if(idx==ls.size()){
		bool zero=true;
		for(char i = 'A';i<='Z';i++){
			if(ar[i]!=0){
				zero=false;
				break;
			}
		}
		if(zero){
			cout<<s<<" =";
			for(int i = 0;i<ans.size();i++){
				cout<<" "<<ans[i];
			}cout<<endl;
		}
		return;
	}
	
	if(found(ls[idx]))rec(idx+1,ans);
	else{
		bool ok=true;
		for(char i = 'A';i<='Z';i++){
			if(tmp[idx][i]>ar[i]){
				ok=false;
				break;
			}
		}
		
		if(ok){
			for(char i = 'A';i<='Z';i++){
				ar[i]-=tmp[idx][i];
			}
			vector<string>nx=ans;
			nx.pb(ls[idx]);
			rec(idx+1,nx);
			for(char i = 'A';i<='Z';i++){
				ar[i]+=tmp[idx][i];
			}
		}
		rec(idx+1,ans);
	}
}

int main(){
//	freopen("out.txt","w",stdout);
	while(getline(cin,s)){
		if(s=="#")break;
		if(s==""||s==" ")continue;
		ls.pb(s);
	}
	
	for(int i = 0;i<ls.size();i++){
		string x=ls[i];
		for(int j= 0;j<x.length();j++){
			if(x[j]==' ')continue;
			tmp[i][x[j]]++;
		}
	}
	
	while(getline(cin,s)){
		if(s=="#")break;
		vector<string>tmpz;
		memset(ar,0,sizeof ar);
		for(int i = 0;i<s.length();i++){
			if(s[i]==' ')continue;
			ar[s[i]]++;
		}
		
		stringstream ss(s);
		string x;ill.clear();
		while(ss>>x){
			ill.pb(x);
		}
		
//		cout<<"PROCESSING "<<s<<endl;
		rec(0,tmpz);
	}
	
}
