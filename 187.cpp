#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

map<int,string>acc;

vector<ii>ls;

void cetak(int x){
	ll tot=0;
	
	for(int i = 0;i<ls.size();i++){
		tot+=ls[i].se;
	}
	
	if(tot==0)return;
	
	printf("*** Transaction %03d is out of balance ***\n",x);
	
	for(int i = 0;i<ls.size();i++){
		printf("%03d %-30s %10.2lf\n",ls[i].fi,acc[ls[i].fi].c_str(),ls[i].se/100.0);
	}
	printf("%03d %-30s %10.2lf\n\n",999,"Out of Balance",-tot/100.0);
}

int main(){
	string s;
	while(getline(cin,s)){
		int num=0;
		for(int i = 0;i<3;i++){
			num*=10;num+=s[i]-'0';
		}
		s.erase(0,3);
		if(num==0)break;
		
		acc[num]=s;
	}
	bool fi=true;
	int bef=-1;
	while(getline(cin,s)){
		int trn=0;
		for(int i = 0;i<3;i++){
			trn*=10;trn+=s[i]-'0';
		}s.erase(0,3);
		
		int acc=0;
		for(int i = 0;i<3;i++){
			acc*=10;acc+=s[i]-'0';
		}s.erase(0,3);
		
		while(s[0]==' ')s.erase(0,1);
		
		int val;
		stringstream ss(s);
		ss>>val;
		
		if(!fi&&bef!=trn){
			cetak(bef);
			ls.clear();
		}
		
		if(trn==0)break;
		
		fi=false;
		bef=trn;
		ls.pb(ii(acc,val));
	}
}
