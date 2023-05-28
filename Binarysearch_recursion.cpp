#include<iostream>
using namespace std;
bool binarysearch(int arr[], int num,int s, int e)
{
	
	int mid=(s+e)/2;
	if(s>e)
	{
		return false;
	}
	if(arr[mid]>num)
	{
		
		e=mid-1;
	}
	else if(arr[mid]<num)
	{
		s=mid+1;	
	}
	else
	{
		return true;
	}
	binarysearch(arr,num,s,e);
}
int main
{
  int s=0;
	int e=4;	
  cin<<num;
	if(binarysearch(arr,num,s,e))
	{
		cout<<"number is present";
	}
	else
	{
		cout<<"number is not present";
	}
}
