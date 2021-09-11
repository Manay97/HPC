#include<iostream>
#include<omp.h>
using namespace std;
void sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
	for (j = 0; j < n-i-1; j++)
	if (arr[j] > arr[j+1])
	{
		int temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
	}
}

void sort_des(int arr[], int n)
{
	int i,j;

	for (i = 0; i < n; ++i)
	{
	  for (j = i + 1; j < n; ++j)
	  {
	     if (arr[i] < arr[j])
	    {
              int a = arr[i];
              arr[i] = arr[j];
              arr[j] = a;
            }
          }
        }
}
int arr1[10000000], arr2[10000000];
int main()
{
        int n=10000000;
	int i;
	for(i = 0; i < n ; i++)
        {
          arr1[i]=i;
        }
        for(i = 0; i < n ; i++)
        {
           arr2[i]=i;
        }
        long long sum = 0;
        float start_time = omp_get_wtime();
        //#pragma omp parallel for reduction(+:sum) 
        for(i = 0; i < n ; i++)
       {
	  sum = sum + (arr1[i] * arr2[i]);
       }
       printf("%lld\n",sum);
       double run_time = omp_get_wtime() - start_time;
       cout<<run_time<<endl;
       return 0;
}
