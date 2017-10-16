#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<int,string>si;

int val(char x){
	if(!isdigit(x))return 10;
	else return x-'0';
}

int main(){
	string s;
	while(getline(cin,s)){
		if(s=="Game Over")break;
		
		string x;
		for(int i = 0;i<s.length();i++){
			if(s[i]==' ')continue;
			x+=s[i];
		}
		
		int ans=0,cnt=1;
		
		int twice=0;
		
		for(int i = 0;i<x.length();i++){
			cout<<x[i]<<" "<<ans<<" "<<cnt<<endl;
			if(x[i]=='X'){
				ans+=val(x[i]);
				if(cnt<=10){
					ans+=val(x[i+1]);
					if(x[i+2]=='/'){
						ans+=val(x[i+2])-val(x[i+1]);
					}else ans+=val(x[i+2]);
				}
				twice=2;
			}else if(x[i]=='/'){
				ans+=val(x[i])-val(x[i-1]);
				cout<<val(x[i])-val(x[i-1])<<endl;
				if(cnt<=10)ans+=val(x[i+1]);
				twice++;
			}else{
				ans+=val(x[i]);
				twice++;
			}
			if(twice==2)twice=0,cnt++;
			else if(cnt>=10)twice=0,cnt++;
		}
		
		cout<<ans<<endl;
	}
}
