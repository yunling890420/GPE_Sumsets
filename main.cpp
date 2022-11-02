#include<iostream>
using namespace std;
int Partition(int *array,int p,int r)
{
	int pivot = array[r];
	int i = p-1;
	for(int j=p;j<r;j++)
	{
		if(array[j] < pivot)
		{
			i = i+1;
			swap(array[i],array[j]);
		}
	}
	swap(array[i+1],array[r]);
	return i+1;
}
void QuickSort(int *array,int p,int r)
{
	if(p<r)
	{
		int q = Partition(array,p,r);
		QuickSort(array,p,q-1);
		QuickSort(array,q+1,r);
	}

}
int main()
{
	int S;
	while(1)
	{
		cin>>S;
		if(S == 0)
			break;
		int array[S];
	
		for(int i=0;i<S;i++)
			cin>>array[i];	
			
		QuickSort(array,0,S-1); //sort the array 
		bool flag= false; // find the answer
		
		for(int max = S-1 ; max >=0;max --) //brute force (has negative number)
		{
			int d = array[max];
			for(int first = 0;first <S;first++)
			{
				int a = array[first];
				for(int second = first + 1;second < S;second++)
				{
					int b = array[second];
					for(int third = second + 1;third < S;third ++ )
					{
						int c = array[third];
						if(a+b+c == d && first != max && second != max && third != max)
						{
							flag = true;
							break;
						}
					}
					if(flag == true)
						break;
				}
				if(flag == true)
							break;
			}
			if(flag == true)
			{
				cout<<d<<endl;
				break;
			}
		}
		if(flag == false)
			cout<<"no solution"<<endl;
	}
	
}
