#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
long long int mat[1000][1000];
int x, resArea = 0, resSum = 0;
void kadane(long long int *arr,int l, int r)
{
	int UP = 0;
	int DOWN = 0;
    long long int maxSum = 0;
    long long int maxArea = 0;
    long long int sum = 0;
	while(UP < x && DOWN < x)
	{
		if(sum + arr[DOWN] <=k)
		{
			sum+=arr[DOWN];
			DOWN++;
			int area = (DOWN- UP) * ( r - l + 1);
			if(area > maxArea)
			{
				maxSum = sum;
				maxArea = area;
			}
			if(area == maxArea && sum < maxSum) maxSum = sum;
		}
		else if(sum!=0)
		{
			int area = (DOWN-1 - UP + 1) * ( r - l + 1);
			if(area > maxArea && sum != 0)
			{
				maxSum = sum;
				maxArea = area;
			}
			if(area == maxArea && sum < maxSum) maxSum = sum;
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
	
    if(resArea < maxArea)
    {
    	resArea = maxArea;
    	resSum = maxSum;
    }
    if(resArea == maxArea && resSum > maxSum)
    	resSum = maxSum;
}
int main() {
	int t;
	cin >> t;
	int CASE = 1;
	while(t--)
	{
		long long int buff[1000];
		int y,k;
		resArea = 0;
		resSum = 0;
	    cin >> x >> y >> k;
	    for(int i=0;i<x;i++)
	    {
	        for(int j=0;j<y;j++)
	        {
	            cin >> mat[i][j];
	        }
	    }
	    long long int sol = INT_MAX;
	    long long int area = 0;
	    for(int left=0;left<y;left++)
	    {
	        for(int i=0;i<x;i++) buff[i] = 0;
	        for(int right=left;right<y;right++)
	        {
	            for(int i=0;i<x;i++)
	            {
	                buff[i]+=mat[i][right];
	            }
	            up=0; down=0;
	             kadane(buff,left+1,right+1);

	        }
	    }
	    cout << "Case #"<<CASE <<": " << resArea << " " << resSum << endl;
	    CASE++;
	}
	return 0;
}
