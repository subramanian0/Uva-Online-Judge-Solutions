#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	int n;
	while (cin >> n)
	{
	int a[n],k;
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a,a+n);
	cin >> k;
	int first=0, last=0;
	bool firstElem = true;
	for(int i=0;i<n;i++)
	{
		auto iter = binary_search(a,a+n,k-a[i]);
		if(iter && (firstElem || abs(last-first) > abs(a[i]-(k-a[i]))))
		{
			first = a[i];
			last = k-a[i];
			firstElem = false;
		}
	}
	cout << "Peter should buy books whose prices are " << min(first,last) << " and " << max(first,last) << "." << endl << endl;
	}
	return 0;
}
