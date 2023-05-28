#include<iostream>
using namespace std;

void bubblesort(int arr[],int len)
{
//base case
	if(len==1)
	{
		return;
	}
	for(int i=0;i<len-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			swap(arr[i],arr[i+1]);
		}
	}
	len--;
	bubblesort(arr+1,len);
}
int main
  {
  int arr[9]={3,5,4,2,0,1,100,5,0};
      bubblesort(arr,9);
	    for(int i=0;i<9;i++)
	    {
		    cout<<arr[i]<<" ";
	    }
  }
