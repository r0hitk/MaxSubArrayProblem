#include<stdio.h>
#include<conio.h>
int main()
{
	int a[]={1,-12,3,4,12,8,-2,1,-2,-5};
	
	int low=0,mid,high=9,sum,sum_left,low_sum,i,j,max_left,sum_right,high_sum,max_right;
	
	mid=(low+high)/2;
	
	low_sum=-123456789;
	sum_left=0;
	
	for(i=mid;i>=low;i--)
	{
		sum_left=sum_left + a[i];
	
		if(sum_left>low_sum)
		{	
			low_sum=sum_left;
			max_left=i;
		}
	}
	
	i=0;
	high_sum=-123456789;
	sum_right=0;
	
	for(i=mid+1;i<=high;i++)
	{	
		sum_right=sum_right + a[i];
		
		if(sum_right>high_sum)
		{
			high_sum=sum_right;
			max_right=i;
		}
	}
	
	//Just to show the max subarray without returning to any 
	//other calling function as we'll need to return a tuple containing 
	//max_left index,max_right index and the high_sum + low_sum
	
	sum=low_sum+high_sum;
	
	int size=max_right-max_left+1;
	
	int b[size],index=max_left;
	
	for(j=0;j<size && index<=max_right;j++)
	{
		b[j]=a[index];
		index++;
	}
	
	j=0;
	
	printf("The max Subarray is:\n ");
	
	for(j=0;j<size;j++)
	printf("%d ",b[j]);
	
	printf("\nThe sum of the subarray is: %d",sum);
}
