#include <iostream>
#include <list>
using namespace std;
list<int>* adjList;
int visited[100005];
int color[100005];
bool goback=false;
void bfs(int i)
{
	if(goback) return;
	if(!visited[i])
	{
	    visited[i] = 1;
		for(list<int>::iterator it=adjList[i].begin();it!=adjList[i].end();it++)
		{
			if(color[*it]==0)
			{
				color[*it] = (color[i]==1)?2:1;
				bfs(*it);
			}
			else if(color[*it] == color[i])
			{
				goback = true;
				return;
			}
		}
	
	}
}
int main() {
	int t;
	cin >> t;
	while(t!=0)
	{
		int n;
		cin >> n;
		for(int i=0;i<=n+5;i++)
		{
			visited[i] = 0;
			color[i] = 0;
		}
		goback=false;
		adjList = new list<int>[n+5];
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin >> x >> y;
			adjList[x].push_back(y);
			adjList[y].push_back(x);
		}
		color[0] = 1;
		for(int i=0;i<n;i++)
		{
			bfs(i);
		}
		cin >> t;
		if(goback) 
			cout << "NOT BICOLORABLE." << endl;
		else cout << "BICOLORABLE." << endl;
	}
	
	return 0;
}