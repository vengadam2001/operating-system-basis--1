#include<stdio.h>
#include<string.h>
int main(){
char pname[100][10],t[10];
float at[10], bt[10],temp,tat[10],ct[10],wt[10];
int n,i,j;
printf("enter the no of entries ");
scanf("%d",&n);
for (i=0;i<n;i++)
{
printf("enter the process name , arrival time ,burst time :");
scanf("%s%f%f",&pname[i],&at[i],&bt[i]);
}
for (i=0;i<n;i++){
printf("%s\t%f\t%f\n",pname[i],at[i],bt[i]);
}
for ( i=0 ;i<n ;i++){
	for (j=0;j<n;j++){
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
for (i=0;i<n;i++){
	if (i == 0){
		ct[i] = at[i] + bt[i];
		printf("checking1%f %f %f\n",ct[i],at[i],bt[i]);
	}
	else{
		if (at[i] > ct[i- 1])
		{
			ct[i] = at[i] + bt[i];
			printf("checking2 %f %f %f\n",ct[i],at[i],bt[i]);
		}
		else{
			printf("checking %f %f %f\n",ct[i],at[i],bt[i]);
			ct[i] = ct[i - 1] + bt[i];
		}
	}
	tat[i] = ct[i] - at[i];
	wt[i] = tat[i] - bt[i];
}

printf("PN\t AT\t\t BT\t\tCT\t\tTAT\t\tWT\n");
for (i=0;i<n;i++){
printf("%s\t%f\t%f\t%f\t%f\t%f\n",pname[i],at[i],bt[i]),ct[i],tat[i],wt[i];
}
return 0;
}

