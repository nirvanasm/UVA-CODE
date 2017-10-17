#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int>ii;

int main(){
	int n;
	int tc=1;
	while(cin>>n){
		if(n==0)break;
		int tot=0;
		vector<int>ls,bte;
		while(tot!=n){
			int a;cin>>a;
			ls.pb(a);
			tot+=a;
		}
		
		for(int i = 5;i<=ls.size();i+=5){
			int tot=0;
			for(int j = i-5;j<i;j++){
				tot+=ls[j];
			}
			bte.pb(tot);
		}
		
		cout<<"Output for data set "<<tc++<<", "<<n<<" bytes:"<<endl;
		for(int i = 0;i<bte.size();i++){
			cout<<"   Time remaining: ";
			if(bte[i]==0)cout<<"stalled"<<endl;
			else{
				n-=bte[i];
				int ans = ceil(n*5.0/bte[i]);
				cout<<ans<<" seconds"<<endl;
			}
		}
		cout<<"Total time: "<<ls.size()<<" seconds"<<endl<<endl;
	}
}
