#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
int binSearch(int*a, int x,int l,int h)
{
	if(l<h)
	{
		int mid = l+((h-l)/2);
		if(x == a[mid])
		{
			while(a[mid] == x)
				mid--;
			return mid+2;
		}
		else if(x<a[mid])
			return binSearch(a,x,l,mid);
		else  return binSearch(a,x,mid+1,h);  
	}
	return 0;
}
int main() {
	int n,q;
	cin >> n >> q;
	int caseNum = 0;
	while(!(n==0 && q==0))
	{
		caseNum ++;
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		sort(a,a+n);
		cout << "CASE# "<<caseNum<<":\n";
		while(q--)
		{
			int x;
			cin >> x;
			int res = binSearch(a,x,0,n);
			if(res == 0)
			{
				cout << x<<" not found" << endl;
			}
			else
			{
				cout << x<<" found at " << res << endl;
			}
		}
		cin >> n >> q;
	}
	return 0;
}
