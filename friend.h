#pragma once
#include<assert.h>

int FindRoot(int *a,int child)    //寻找祖先结点
{
	while(a[child] >= 0)
	{
		child = a[child];
	}

	return child;
}

void Combine(int *a,int root1,int root2)   //合并两个集合
{
	a[root1] += a[root2];
	a[root2] = root1;
}

 int Friend(int n,int m,int r[][2])
{
	assert(r);
	int *arr = new int[n+1];
	for(int i = 0;i < n+1;++i)
	{
		arr[i] = -1;
	}
	
	for(int i = 0;i < m;++i)
	{
		int first = r[i][0];
		int second = r[i][1];

		int root1 = FindRoot(arr,first);
		int root2 = FindRoot(arr,second);

		Combine(arr,root1,root2);
	}

	int count = -1;
	for(int i = 0;i < n+1;++i)
	{
		if(arr[i] < 0)
			++count;
	}
	return count;
}