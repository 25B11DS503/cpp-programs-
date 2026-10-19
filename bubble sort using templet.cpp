#include<iostream>
using namespace std;
template<typename T>
void bubblesort(T arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				T temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]= temp;
			}
		}
	}
}
int main()
{
	int arr[]={8,5,4,3,1};
	int n=5;
	bubblesort(arr,n);
	cout<<"sorted elements are:"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<""<<endl;
	}
	return 0;	
}
