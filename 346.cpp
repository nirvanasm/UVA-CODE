#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;
typedef pair<string,int>si;

string ls1[12]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
string ls2[12]={"B#","Db","D","Eb","Fb","E#","Gb","G","Ab","A","Bb","Cb"};
int range[6]={2,2,1,2,2,2};
int major[2]={4,3};
int minor[2]={3,4};

map<vector<string>,si>vis;

void pre(){
	for(int i = 0;i<12;i++){
		vector<string>tmp;tmp.pb(ls1[i]);
		int cur=i;
		for(int j = 0;j<2;j++){
			cur=(cur+major[j])%12;
			tmp.pb(ls1[cur]);
		}
		sort(tmp.begin(),tmp.end());
		
		vis[tmp]=si(ls1[i],0);
	}
	
	for(int i = 0;i<12;i++){
		vector<string>tmp;tmp.pb(ls1[i]);
		int cur=i;
		for(int j = 0;j<2;j++){
			cur=(cur+minor[j])%12;
			tmp.pb(ls1[cur]);
		}
		sort(tmp.begin(),tmp.end());
		vis[tmp]=si(ls1[i],1);
	}
}

int find(string x){
	for(int i = 0;i<12;i++){
		if(ls2[i]==x)return i;
	}
	return -1;
}

void conv(string &x){
	int val=find(x);
	if(val==-1)return;
	x=ls1[val];
}

int main(){
	pre();
	string a,b,c;
	while(cin>>a>>b>>c){
		
		cout<<a<<" "<<b<<" "<<c<<" is ";
		
		a[0]=toupper(a[0]);
		b[0]=toupper(b[0]);
		c[0]=toupper(c[0]);
		
		conv(a);conv(b);conv(c);
		
		vector<string>tmp;
		tmp.pb(a);tmp.pb(b);tmp.pb(c);
		sort(tmp.begin(),tmp.end());
		
		if(!vis.count(tmp))cout<<"unrecognized."<<endl;
		else{
			cout<<"a "<<vis[tmp].fi;
			if(vis[tmp].se==0)cout<<" Major chord."<<endl;
			else cout<<" Minor chord."<<endl;
		}
	}
}
