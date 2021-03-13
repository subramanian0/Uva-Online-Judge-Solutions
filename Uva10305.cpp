#include <iostream>
#include <list>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
int visited[1000];
list<int>* adjList;
vector<int> res;
void bdfs(int s)
{
	if(!visited[s])
	{
		if(adjList[s].size())
		{
			for(list<int>::iterator it = adjList[s].begin(); it!=adjList[s].end();it++)
			{
				bdfs(*it);
			}
		}
			visited[s] = 1;
			res.push_back(s);
	}
}
int main() {
	int x,y;
	int n,m;
	while(scanf("%d %d",&n,&m) == 2 && !(n==0 && m==0))
	{
		for(int i=0;i<=n;i++) visited[i] = 0;
		adjList = new list<int>[n+1];
		res.clear();
		while(m--)
		{
			cin >> x >> y;
			adjList[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
		bdfs(i);
		for(int i=1;i<=n;i++)
		{
			if(!visited[i]) res.push_back(i);
		}
		for(vector<int>::reverse_iterator it = res.rbegin(); it!=res.rend();it++)
		{
			cout << *it << " ";
		}
	   cout << endl;
	}
	return 0;
}