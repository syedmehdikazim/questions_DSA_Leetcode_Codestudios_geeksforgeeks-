#include<iostream>
using namespace std;
int powerof(int num,int k, int ans)
{
	if(k==0)
	{
		return ans;
	}
	ans=2*powerof(num,k-1,ans);
}
int factorial(int num,int ans)
{
	if(num==0)
	{
		return ans;
	}
	ans=num*factorial(num-1,ans);
}
void printcounting(int num)
{
	if(num==0)
	{
		return;
	}
	cout<<num<<" ";
	printcounting(num-1);
	
}
int fib(int num,int ans)
{
	if(num==0)
	{
		return 0;
	}
	if(num==1 || num==2)
	{
		return 1;
	}
	return fib(num-1,ans)+fib(num-2,ans);
		
}
int reachingthestairs(int num)
{
	if(num==0)
	{
		return 0;
	}
	if(num==1)
	{
		return 1;
	}
	if(num==2)
	{
		return 2;
	}
	return reachingthestairs(num-1)+reachingthestairs(num-2);
}
void saydigit(int num)
{
	string str[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	if(num==0)
	{
		return;
	}
	int digit=num%10;
	
	num=num/10;
	saydigit(num);
	cout<<str[digit]<<" ";	
}
bool issorted(int arr[],int len,int i)
{
	if(i==len-1)
	{
		return true;
	}
	else if(arr[i+1]>arr[i])
	{
		issorted(arr,len,i+1);
	}
	else
		return false;
}
bool isssorted(int *arr,int len)
{
	if(len==0)
	{
		return true;
	}
	else if(arr[1]>arr[0])
	{
		isssorted(arr+1,len--);
	}
	else
		return false;
}
int linearsearch(int arr[], int len, int i,int num)
{
	if(i==len-1)
	{
		return false;
	}
	if(arr[i] == num)
	{
		return true;
	}
	linearsearch(arr,len,i+1,num);
	
}
int main()
{
  //write your code here to use the above function
  //these are pretty easy and standard question for practising recursion
}
