#include<stdio.h>
#include<string.h>
main(){
char pname[][100],t[100];
float at[100], bt[100],,temp;
int n;
printf("enter the no of entries ");
scanf('%d',&n);
for (int i = 0;i < n ; i++)
{
printf("enter the process name , arrival time ,burst time :");
scanf("%s%f%f",&pname[],&at[],&bt[]);
}
for (int i=0 ;i<n ;i++){
	for (int j=0;j<n;j++){
		if (at[i]<at[j]){
		temp= at[i];
		at[i]=at[j];
		at[j]=temp;
		
		temp= bt[i];
		bt[i]=bt[j];
		bt[j]=temp;
		
		strcpy(t,pname[i]);
		strcpy(pname[i],pname[j]);
		strcpy(pname[j],t);
		}
	}
}
printf("PN\t AT\t BT");
for (int i=0;i<n, i++){
printf("%s\t%f\t%f",&pname[i],&at[i],&bt[i]);

}
}

