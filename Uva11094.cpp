#include<iostream>
using namespace std;
char a[50][50];
int n,m;
int visited[50][50];
int ans = 0;
int cnt = 0;
void dfs(int x, int y, int components)
{

	if(x<0 || y<0 || x>=m || y>=n) return;
	if(!visited[x][y])
	{
		
	     visited[x][y] = 555;
	     cnt++;
	     if(components > ans) ans = components;
		if(x+1<m && a[x+1][y]==a[x][y])
			dfs(x+1,y,components+1);
		if(y+1<n && a[x][y+1]==a[x][y])
			dfs(x,y+1,components+1);
		if(y == n-1 && a[x][y] == a[x][0])
		 	dfs(x,0,components+1);
		 if(y ==0 && a[x][y] == a[x][n-1])
		 	dfs(x,n-1,components+1);
		 if(x-1>=0 && a[x-1][y] == a[x][y])
		 	dfs(x-1,y,components+1);
		 if(y-1>=0 && a[x][y-1] == a[x][y])
		 	dfs(x,y-1,components+1);
	}
}
int main()
{
	while(scanf("%d %d",&m,&n)==2)
	{
	for(int ii=0;ii<m;ii++)
	{
		for(int jj=0;jj<n;jj++)
		{
			cin >> a[ii][jj];
			visited[ii][jj] = 0;
		}
	}
	int x,y;
	cin >> x >> y;
	cnt = 0;
	dfs(x,y,0);




	ans = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(true)
			{
				cnt = 0;
				if(a[i][j] == a[x][y])
				dfs(i,j,1);
				if(cnt > ans) ans = cnt;
			}
		}
	}
	cout << ans << endl;
	}



	return 0;
}