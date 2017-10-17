#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int,int>ii;
typedef pair<ii,ii>iiii;
typedef pair<int,iiii>iiiii;

struct dt{
	int m,b,t;
	int idx;
	int note;
	int ty;
	dt(int a=0,int c=0,int d=0,int e=0,int f=0,int g=0){
		m=a;b=c;t=d;idx=e;
		note=f;ty=g;
	}
};

int quan[9]={0,60,120,180,240,300,360,420,480};

void cut(int &m, int &b, int&t){
	int idx=-1,sel=1000;
	for(int i = 0;i<9;i++){
		if(abs(t-quan[i])<=sel){
			sel=abs(t-quan[i]);
			idx=i;
		}
	}
	
	if(idx==8){
		t=0;
		b++;
		if(b==5){
			b=1;
			m++;
		}
	}else{
		t=quan[idx];
	}
}

int main(){
	int n;
	
	while(cin>>n){
		if(n==-1)break;
		vector<dt>ans;
		
		for(int i = 0;i<n;i++){
			int ty,note,m,b,t;
			cin>>ty>>note>>m>>b>>t;
			cut(m,b,t);
			if(ty==1){
				ans.pb(dt(m,b,t,i,note,ty));
			}else{
				bool dup=false;
				for(int j = 0;j<ans.size();j++){
					if(ans[j].ty==1&&ans[j].m==m&&ans[j].b==b&&ans[j].t==t&&ans[j].note==note){
						ans.erase(ans.begin()+j);
						dup=true;
						break;
					}
				}
				if(!dup){
					ans.pb(dt(m,b,t,i,note,ty));	
				}
			}
		}
		cout<<ans.size()<<endl;
		for(int i = 0;i<ans.size();i++){
			cout<<ans[i].ty<<" "<<ans[i].note<<" "<<ans[i].m<<" "<<ans[i].b<<" "<<ans[i].t<<endl;
		}
	}
	cout<<-1<<endl;
	
}
