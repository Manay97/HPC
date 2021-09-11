#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
int tid;
int i,j;
int rows,cols;

/*printf("Enter Number of Rows of matrices\n");
scanf("%d",&rows);
printf("Enter Number of Columns of matrices\n");
scanf("%d",&cols);*/
rows=60;
cols=40;

int a[rows][cols];
int b[rows][cols];
int c[rows][cols];

int *d,*e,*f;

printf("Enter %d elements of first matrix\n",rows*cols);
for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       a[i][j]=1;
    }

printf("Enter %d elements of second matrix\n",rows*cols);
for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
	b[i][j]=2;
    }

//write
double t1 = omp_get_wtime();
#pragma omp parallel for schedule(static,10)

	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}

#pragma omp barrier
double t2 = omp_get_wtime();
printf("Values of Resultant Matrix C are as follows:\n");

/*for(i=0;i<rows;i++)
  for(j=0;j<cols;j++)
    {
       printf("Value of C[%d][%d]=%d\n",i,j,c[i][j]);
    }*/
    
    cout<< fixed << setprecision(10) <<"time taken: "<<t2-t1<<endl;
    return 0;

}
