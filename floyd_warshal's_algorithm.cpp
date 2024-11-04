#include<bits/stdc++.h>
using namespace std;
int main()
{
	int no_of_nodes;
	int no_of_edges;
	cin>>no_of_nodes>>no_of_edges;
	vector<vector<int>> dp(no_of_nodes,vector<int>(no_of_nodes,1e9));
	int u,v,w;
	for(int i=0;i<no_of_edges;i++)
	{
		cin>>u>>v>>w;
		dp[u][v]=w;
	}
	for(int i=0;i<no_of_nodes;i++)
		dp[i][i]=0;
	for(int k=0;k<no_of_nodes;k++)
	{
		for(int i=0;i<no_of_nodes;i++)
		{
			for(int j=0;j<no_of_nodes;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=0;i<no_of_nodes;i++)
	{
		for(int j=0;j<no_of_nodes;j++)
		{
			if(dp[i][j]==1e9)
			cout<<-1<<" ";
			else
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}