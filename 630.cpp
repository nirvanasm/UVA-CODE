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
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		memset(ar,0,sizeof ar);
		for(int i = 0;i<n;i++){
			string s;cin>>s;
			ls[i]=s;
			for(int j = 0 ;j<s.length();j++){
				ar[i][s[j]]++;
			}
		}cin.get();
		string s;
		while(getline(cin,s)){
			if(s=="END")break;
			memset(cur,0,sizeof cur);
			for(int i = 0;i<s.length();i++){
				cur[s[i]]++;
			}
			
			cout<<"Anagrams for: "<<s<<endl;
			
			int cnt=1;
			for(int i = 0;i<n;i++){
				bool ok=true;
				for(int j = 'a';j<='z';j++){
					if(ar[i][j]!=cur[j]){
						ok=false;
						break;
					}
				}
				
				if(ok)printf("%3d) %s\n",cnt++,ls[i].c_str());
			}
			
			if(cnt==1)cout<<"No anagrams for: "<<s<<endl;
		}
		if(t)cout<<endl;
	}
}
