#include <iostream>
#include <cstring>
using namespace std;
int mat[1000][1000];
int buff[1000];
int x,y;
int left,right,up, down;
int kadane(int *arr)
{
	
	int UP = 0;
	int DOWN = 0;
    long long int maxSum = 0;
    long long int maxArea = 0;
    long long int sum = 0;
	while(UP < x && DOWN < x)
	{
		if(sum + arr[DOWN] >=0 && DOWN - UP + 1 <= x/2)
		{
			sum+=arr[DOWN];
			DOWN++;
			if(sum > maxSum)
			{
				maxSum = sum;
			}
		}
		else if(sum!=0)
		{
			if(sum > maxSum && sum != 0)
			{
				maxSum = sum;
			}
			UP++;
			DOWN=UP;
			sum = 0;
		}
		else 
		{
			UP++;
			DOWN=UP;
		}
	}
	return maxSum;
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    cin >> x;
	    y =x;
	    for(int i=0;i<x;i++)
	    {
	        for(int j=0;j<y;j++)
	        {
	          cin >> mat[i][j];
	          mat[i+x][j] = mat[i][j];
	          mat[i][j+y] = mat[i][j];
	          mat[i+x][j+y] = mat[i][j];
	        }
	    }
	    
	    x*=2;
	    y*=2;
	    
	    int ans = 0, sol = 0;
	    for(int left=0;left<y;left++)
	    {
	        for(int i=0;i<x;i++) buff[i] = 0;
	        for(int right=left;right<y;right++)
	        {
	            for(int i=0;i<x;i++)
	            {
	                buff[i]+=mat[i][right];
	            }
	           if(right - left +1 <= x/2) 
	           sol =  kadane(buff);
	           if(sol > ans) ans = sol;
	        }
	    }
	    cout << ans << endl;
	}
	return 0;
}
