  
#include<omp.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

#define ARR_SIZE 10000000
int a[ARR_SIZE];


int main()
{
int i,sum=0;
double t1,t2;

																																																																																																																										
for(i=0;i<ARR_SIZE;i++)
	a[i]=1;
	
t1=omp_get_wtime();
int ck=75;
cout<<"size: "<<ARR_SIZE<<endl;
cout<<"chunk size: "<<ck<<endl;
#pragma omp parallel for schedule (static,ck)
for(i=0;i<ARR_SIZE;i++)
	a[i]+=5;
	
t2=omp_get_wtime();

//printf("sum of array= %d, time = %g\n",sum,t2-t1);
cout<<"sum= "<<sum<<" time taken= "<<fixed<<setprecision(6)<<t2-t1<<endl;
return 0;
}
