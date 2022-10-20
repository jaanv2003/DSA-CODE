* To add and subtract two sparse matrices.
Give two matrices in its simple form. */

#include<stdio.h>
#include<iostream.h>
#include<conio.h>

int main()
{
   clrscr();
   int sparse1[10][3],sparse2[10][3],sum[10][3],diff[10][3];
   int m,n,p,q,t1,t2,s,d,element;
   int i,j;
   cout<<"Enter the number of rows and columns : ";
   cin>>m>>n;
   t1=t2=0;

   cout<<"
Enter the first matrix("<<m<<"*"<<n<<"):
";
   for(i=1;i<=m;i++)
   {
      for(j=1;j<=n;j++)
      {
	 cin>>element;
	 if(element!=0)
	 {
	    t1=t1+1;
	    sparse1[t1][1]=i;
	    sparse1[t1][2]=j;
	    sparse1[t1][3]=element;
	 }
      }
   }
   sparse1[0][1]=m;
   sparse1[0][2]=n;
   sparse1[0][3]=t1;
   cout<<"
Enter the second matrix("<<m<<"*"<<n<<"):
";
   for(i=1;i<=m;i++)
   {
      for(j=1;j<=n;j++)
      {
	 cin>>element;
	 if(element!=0)
	 {
	    t2=t2+1;
	    sparse2[t2][1]=i;
	    sparse2[t2][2]=j;
	    sparse2[t2][3]=element;
	 }
      }
   }
   sparse2[0][1]=m;
   sparse2[0][2]=n;
   sparse2[0][3]=t2;

   // displaying the first sparse matrix
   cout<<"

The first sparse matrix is :

Row	Column	Element";
   cout<<"
-----------------------
";
   for(i=0;i<=t1;i++)
   {
      
cout<<sparse1[i][1]<<"	"<<sparse1[i][2]<<"	"<<sparse1[i][3]<<"
";
   }
    // displaying the second sparse matrix
   cout<<"

The second sparse matrix is :

Row	Column	Element";
   cout<<"
-----------------------
";
   for(i=0;i<=t2;i++)
   {
      
cout<<sparse2[i][1]<<"	"<<sparse2[i][2]<<"	"<<sparse2[i][3]<<"
";
   }

   // Addition and subtraction
   i=j=s=d=1;
   while((i<=t1)&&(j<=t2))
   {
      if(sparse1[i][1]==sparse2[j][1])    // if rows are equal
      {
	 if(sparse1[i][2]==sparse2[j][2]) // if columns are equal
	 {
	    sum[s][1]=diff[d][1]=sparse1[i][1];
	    sum[s][2]=diff[d][2]=sparse1[i][2];
	    sum[s][3]=sparse1[i][3]+sparse2[j][3];
	    diff[d][3]=sparse1[i][3]-sparse2[j][3];
	    i++;
	    j++;
	    if(sum[s][3]!=0)
	       s++;
	    if(diff[d][3]!=0)
	       d++;
	 }
	 else   // if columns are not equal
	 {
	    if(sparse1[i][2]<sparse2[j][2])
	    {
	       sum[s][1]=diff[d][1]=sparse1[i][1];
	       sum[s][2]=diff[d][2]=sparse1[i][2];
	       sum[s][3]=diff[d][3]=sparse1[i][3];
	       i++;
	       s++;
	       d++;
	    }
	    else
	    {
	       sum[s][1]=diff[d][1]=sparse2[j][1];
	       sum[s][2]=diff[d][2]=sparse2[j][2];
	       sum[s][3]=sparse2[j][3];
	       diff[d][3]=0-sparse2[j][3];
	       j++;
	       d++;
	       s++;
	    }
	 }
      }
      else   //   if rows are not equal
      {
	 if(sparse1[i][1]<sparse2[j][1])
	 {
	    sum[s][1]=diff[d][1]=sparse1[i][1];
	    sum[s][2]=diff[d][2]=sparse1[i][2];
	    sum[s][3]=diff[d][3]=sparse1[i][3];
	    i++;
	    d++;
	    s++;
	 }
	 else
	 {
	    sum[s][1]=diff[d][1]=sparse2[j][1];
	    sum[s][2]=diff[d][2]=sparse2[j][2];
	    sum[s][3]=sparse2[j][3];
	    diff[d][3]=0-sparse2[j][3];
	    j++;
	    s++;
	    d++;
	 }
      }
   }  // end of while
   if(i<=t1)
   {
      for(p=i;p<=t1;p++)
      {
	 sum[s][1]=diff[d][1]=sparse1[p][1];
	 sum[s][2]=diff[d][2]=sparse1[p][2];
	 sum[s][3]=diff[d][3]=sparse1[p][3];
	 s++;
	 d++;
      }
   }
   else if(j<=t2)
   {
      for(p=j;p<=t2;p++)
      {
	 sum[s][1]=diff[d][1]=sparse2[p][1];
	 sum[s][2]=diff[d][2]=sparse2[p][2];
	 sum[s][3]=sparse2[p][3];
	 diff[d][3]=0-sparse2[j][3];
	 s++;
	 d++;
      }
   }
  // end of addition and subtraction
  sum[0][1]=diff[0][1]=m;
  sum[0][2]=diff[0][2]=n;
  sum[0][3]=s-1;
  diff[0][3]=d-1;

  // displaying the sum matrix
   cout<<"

The sum is :

Row	Column	Element";
   cout<<"
-----------------------
";
   for(i=0;i<s;i++)
   {
      cout<<sum[i][1]<<"	"<<sum[i][2]<<"	"<<sum[i][3]<<"
";
   }
    // displaying the difference matrix
   cout<<"

The difference is :

Row	Column	Element";
   cout<<"
-----------------------
";
   for(i=0;i<d;i++)
   {
      cout<<diff[i][1]<<"	"<<diff[i][2]<<"	"<<diff[i][3]<<"
";
   }
   getch();
   return 0;
}
