#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int win[105],lose[105];

int comp(string a,string b){
	if(a==b)return 0;
	
	if(a=="rock"){
		if(b=="paper")return -1;
		else return 1;
	}
	if(a=="paper"){
		if(b=="scissors")return -1;
		else return 1;
	}
	if(a=="scissors"){
		if(b=="rock")return -1;
		else return 1;
	}
	
	return 0;
}

int main(){
	cout<<fixed<<setprecision(3);
	int n;
	bool fi=true;
	while(cin>>n){
		if(n==0)break;
		if(!fi)cout<<endl;
		fi=false;
		int k;cin>>k;
		for(int i = 0;i<n;i++){
			win[i]=0;
			lose[i]=0;
		}
		
		for(int i = 0;i<k*n*(n-1)/2;i++){
			int p1,p2;string s1,s2;
			cin>>p1>>s1>>p2>>s2;p1--;p2--;
			
			int val=comp(s1,s2);
			if(val==-1)win[p2]++,lose[p1]++;
			else if(val==1)win[p1]++,lose[p2]++;
		}
		
		for(int i = 0;i<n;i++){
			if(lose[i]+win[i]==0)cout<<"-"<<endl;
			else cout<<(double)(win[i])/(lose[i]+win[i])<<endl;
		}
	}
	
}
