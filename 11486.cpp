#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int hsh[128];
int bck[35];
ll mat[35][35];
ll base[35][35],tmp[35][35];

void rec(int idx,int mask,int cur,int nxMask){
	if(cur==5){
		mat[idx][hsh[nxMask]]++;
		return;
	}
	int cnt=0;
	int tmp=mask;
	int png=-1;
	while(cnt!=cur){
		if(tmp&1)cnt++;
		png++;
		tmp/=2;
	}
	
	if(png>0&&!(nxMask & (1<<(png-1))))rec(idx,mask,cur+1,nxMask|(1<<(png-1)));
	if(png<6&&!(nxMask & (1<<(png+1))))rec(idx,mask,cur+1,nxMask|(1<<(png+1)));
	
}

void consMat(){
	int cnt=0;
	for(int i  = 15;i<128;i++){
		if(__builtin_popcount(i)==4){
			hsh[i]=cnt;
			bck[cnt++]=i;
		}
	}
	for(int i = 0;i<35;i++){
		rec(i,bck[i],1,0);
	}
}

void timpa(){
	for(int i = 0;i<35;i++){
		for(int j = 0;j<35;j++){
			base[i][j]=tmp[i][j];
		}
	}
}

void fast(int n){
	if(n<=1)return;
	fast(n/2);
	
	memset(tmp,0,sizeof tmp);
	for(int i = 0;i<35;i++){
		for(int j = 0;j<35;j++){
			for(int k = 0;k<35;k++){
				tmp[i][j] = (tmp[i][j] + base[i][k] * base[k][j]%MOD)%MOD;
			}
		}
	}
	
	timpa();
	if(n%2==0)return;
	
	memset(tmp,0,sizeof tmp);
	for(int i = 0;i<35;i++){
		for(int j = 0;j<35;j++){
			for(int k = 0;k<35;k++){
				tmp[i][j] = (tmp[i][j] + base[i][k] * mat[k][j]%MOD)%MOD;
			}
		}
	}
	
	timpa();
}

void work(int n,int mask){
	for(int i = 0;i<35;i++)for(int j = 0;j<35;j++)base[i][j]=mat[i][j];
	fast(n-1);
	
	int id = hsh[mask];
	
	ll ans = 0;
	
	for(int i = 0;i<35;i++){
		ans += base[id][i];
	}
	
//	cout<<n<<" "<<mask<<" "<<id<<endl;
//	
//	for(int i = 0;i<35;i++){
//		for(int j = 0;j<35;j++){
//			cout<<base[i][j]<<" ";
//		}cout<<endl;
//	}
	
	cout<<ans%MOD<<endl;
	return;
}

int main(){
	consMat();
	int t;cin>>t;
	while(t--){
		ll n;cin>>n;
		int mask = 0;
		for(int i = 0;i<7;i++){
			int a;cin>>a;
			mask*=2;
			if(a!=0)mask++;
			
		}
		if(n==1)cout<<1<<endl;
		else{
			work(n,mask);
		}
	}
}
