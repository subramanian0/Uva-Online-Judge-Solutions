#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
vector<int> piles;
vector<int> back(0);
vector<int> res;
vector<int> buff;
int k;
int binarySearch(int l, int h, int key)
{
	while(l<=h)
	{
		int m = l + (h-l)/2;
		if(piles[m] == key) return m;
		else if(piles[m] < key)
			l = m+1;
		else
			h = m -1;
	}
	return l;
}
int main()
{
	int x;
	while( cin>> x)
	{
		a.push_back(x);
	}
	piles.push_back(a.at(0));
	k = 1;
	back.push_back(-1);
	int lastIndex = -1;
	buff.push_back(a.at(0));
	for(int i=1;i<a.size();i++)
	{
		if(a.at(i) < piles.at(0))
		{
			piles.at(0) = a.at(i);
			back.push_back(-1);
		}
		else if(a.at(i) > piles.at(piles.size()-1))
		{
			piles.push_back(a[i]);
			int elem =  piles.at(piles.size()-2);
			auto lastOccurence = find(buff.rbegin(),buff.rend(),piles.at(piles.size()-2));
			back.push_back(buff.rend() - lastOccurence - 1 );
		} 
		else
		{
			int pos = binarySearch(0,piles.size(),a[i]);
			int elem =  piles.at(pos-1);
		    auto lastOccurence = find(buff.rbegin(),buff.rend(),elem);
			back.push_back((buff.rend() - lastOccurence - 1) );
			piles.at(pos) = a.at(i);
		}
				buff.push_back(a.at(i));
	}		
	
    

   if(piles.size()>1)
   {
   	   cout << piles.size() << endl;
     cout << "-" << endl;
   	int six = piles.size();
   	for(int i = a.size()-1;i>=0;i--)
   	{
   		if(a.at(i) == piles.at(piles.size()-1)) { lastIndex = i; break; }
   	}
 	   while(lastIndex>=0 && six > 0)
	   {
	 	 res.push_back(a.at(lastIndex));
	   	 lastIndex = back.at(lastIndex);
	   	 six--;
	   }
      for(int i=res.size()-1;i>=0;i--)
     	cout << res.at(i) << endl;
   }
   else cout << "0\n-\n";
	
	return 0;
}
