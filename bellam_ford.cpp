#include<bits/stdc++.h>
using namespace std;
vector<int> bellam_ford(int src,vector<vector<int>> &e,int vertices,int edges)
{
	int u,v,w;
	vector<int> dis(vertices,INT_MAX);
	dis[src]=0;
	bool state=true;
	for(int i=0;i<vertices-1;i++)
	{
		for(auto j:e)
		{
			u=j[0];
			v=j[1];
			w=j[2];
			if(dis[u]!=INT_MAX&&(dis[v]>dis[u]+w))
			{
					dis[v]=dis[u]+w;
			}		
		}
	}
	for(auto j:e)
	{
		u=j[0];
		v=j[1];
		w=j[2];
		if(dis[u]!=INT_MAX&&dis[v]>dis[u]+w)
		{
			state=false;
			break;
		}
	}
	if(state)
		return dis;
	else
		return {-1};
}
int main()
{
	int vertices,edges,u,v,w;
	cin>>vertices>>edges;
	vector<vector<int>> e;
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	int src;
	cin>>src;
	vector<int> ans=bellam_ford(src,e,vertices,edges);
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;
}