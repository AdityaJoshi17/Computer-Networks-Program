#include<iostream>
#include<math.h>
#define Max 999
using namespace std;


int main(){

	int n;

	cout<<"Enter the no of bits"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter each bit "<<endl;
	for (int i =0 ; i<n; i++)
	{
		cin>>arr[i];
	}
	int r = 0;
	for(int i = 0 ; i<Max;i++)
	{
		if(n+i+1 <= pow(2,i))
		{
			r = i;
			break;
		}
	}
	cout<<r<<endl;
	int m = n+r;
	cout<<m<<endl;
	int hamming[m];
	int j = 0;
	int k = n-1;
	for (int i = 1; i <=m;i++)
	{
		if(i == pow(2,j))
		{
			hamming[i] = -1;
			j++;
		}
		else{
			hamming[i] = arr[k];
			k--;
		}
	}
	for (int i = 1; i <=m; i++)
	{
		cout<<hamming[i];
	}
	cout<<endl;
	k = 0;
	int parity =0;
	for (int i = 1; i <= m; i = pow(2,k))
	{
		parity = 0;
		k++;
		int x = i;
		j = i;
		int min =1;
		int max = i;
		while(j <=m)
		{
			for(x= j; max>=min && x<=m; min++,x++)
			{
				if(hamming[x] == 1)
				{
					parity++;

				}
			}
				j = x+i;
				min =1;
		}
			if(parity %2 ==0)
			{
				hamming[i] = 0;
			}
			else
			{
				hamming[i] =1;
			}
		}

	for (int i = m; i >=1; i--)
	{
		cout<<hamming[i];
	}

}
