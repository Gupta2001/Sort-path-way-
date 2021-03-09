
#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define rep(i,a,n) for(lli i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define sz(v) v.size()
#define pi 3.141592653589793238
#define fr first;
#define sc second
#define ins insert
using namespace std;
vector<lli>v;
vector<pair<lli,lli>>adj[100002];
bool vis[100002];
lli t,n,k,dis[200002];
lli pa[200000];
void dij(){
	set<pair<lli,lli>>ss;
	ss.insert({0,1});
    dis[1]=0;
	int w,c,ck;
	while(!ss.empty()){
	   
	    c=(ss.begin()->second);
	    ss.erase(ss.begin());
	   
	    
	    for(auto it:adj[c]){
	        
	        ck=it.first;
	        w=it.second;
	       // cout<<ck<<" "<<w<<endl;
	        
	        if(dis[ck]>dis[c]+w){
	            ss.erase({dis[ck],ck});
	            dis[ck]=dis[c]+w;
	            pa[ck]=c;
	            ss.insert({dis[ck],ck});
	            
	        }
	
	    }
	    
	}
	
	
}
int main()
{

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	cin>>n>>k;
	lli x,y,w;
	
	while(k--){
	    cin>>x>>y>>w;
	    adj[x].pb({y,w});
	    adj[y].pb({x,w});
	}
	
	rep(i,0,200002) dis[i]=100000000000000;
	
	dij();
	
    if(dis[n]==100000000000000)
    {
        cout<<-1;
        return 0;
    }
	
	
	for(int i=n;i!=1;i=pa[i]) v.pb(i);
	v.pb(1);
	reverse all(v);
	rep(i,0,v.size()) cout<<v[i]<<" ";
	
	return 0;
}