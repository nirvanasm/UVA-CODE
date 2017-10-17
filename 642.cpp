#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int ar[1005][255];
string ls[1005];
int cur[255];

int main(){
	int n=0;
	string s;
	while(getline(cin,s)){
		if(s=="XXXXXX")break;
		ls[n]=s;
		for(int j = 0 ;j<s.length();j++){
			ar[n][s[j]]++;
		}
		n++;
	}
	while(getline(cin,s)){
		if(s=="XXXXXX")break;
		memset(cur,0,sizeof cur);
		for(int i = 0;i<s.length();i++){
			cur[s[i]]++;
		}
		vector<string>ans;
		for(int i = 0;i<n;i++){
			bool ok=true;
			for(int j = 'a';j<='z';j++){
				if(ar[i][j]!=cur[j]){
					ok=false;
					break;
				}
			}
			
			if(ok)ans.pb(ls[i]);
		}
			
		if(ans.size()==0)cout<<"NOT A VALID WORD"<<endl;
		else{
			sort(ans.begin(),ans.end());
			for(int i = 0;i<ans.size();i++){
				cout<<ans[i]<<endl;
			}
		}
		cout<<"******"<<endl;
	}
}
