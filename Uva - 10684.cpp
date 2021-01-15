#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n!=0)
	{
		 int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		int j=0;
		 int sum = 0;
		 int maxSum = 0;
		for(int i=0;i<n;i++)
		{
			j=i;
			while(sum+a[j]>=0 && j<n)
			{
				sum+=a[j];
				if(sum>maxSum) maxSum = sum;
				j++;i++;
			}
			sum=0;
		}
		if(maxSum == 0)
			cout << "Losing streak."<<endl;
		else cout << "The maximum winning streak is "<<maxSum<<"."<<endl;
		cin >> n;
	}
		return 0;
}
