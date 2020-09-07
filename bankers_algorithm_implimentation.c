#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
int *alloc,*max,*need,*avail,*safeq;
int j=0,i=0,r=0,c=0,p=0;
void getallocmatrix();
void getmaxmatrix();
void calcneed();
void getavail();
void calcsafe();
void main()
{
    getallocmatrix();
    getmaxmatrix();
    calcneed();
    getavail();
    calcsafe();
}


void getallocmatrix(){
    printf("enter the no of processes:");
    scanf("%d",&r);
    printf("enter the no of unique resources:");
    scanf("%d",&c);
    alloc = (int*)calloc(r*c, sizeof(int));
    if (alloc != NULL){
        for (i=0;i<r;i++){
            printf("enter the Allocated resources(quantity as integer) for process %d :",i);
            for (j=0;j<c;j++){
                scanf("%d",&alloc[((i*c)+j)]);
            }
        }
    }
    else{
        printf("memory not enough\n");
    }
}

void getmaxmatrix(){
    max = (int*)calloc(r*c, sizeof(int));
    if (max != NULL){
        for (i=0;i<r;i++){
            printf("enter the Maximum resources(quantity as integer) for process %d :",i);
            for (j=0;j<c;j++){
                scanf("%d",&max[((i*c)+j)]);
            }
        }
    }
    else{
        printf("memory not enough\n");
    }
}   

void calcneed(){
    need = (int*)calloc(r*c, sizeof(int));
    if (need != NULL){
        for (i=0;i<r;i++){
            for (j=0;j<c;j++){
                need[((i*c)+j)]=(max[((i*c)+j)] - alloc[((i*c)+j)]);
            }
        }
        printf("Need matrix is:\n");
        for (i=0;i<r;i++){
            for (j=0;j<c;j++){
                printf("%d ",need[((i*c)+j)]);
            }
            printf("\n");
        }
        printf("\n");
    }
    else{
        printf("memory not enough");
    }
}

void getavail(){
    avail = (int*)calloc(c, sizeof(int));
    if (avail!=NULL){
        printf("enter the available resources:");
        for(i=0;i<c;i++){
            scanf("%d",&avail[i]);
        }    
    }
    else{
        printf("memory not enough\n");
    } 
}

void calcsafe(){
    int p=0;
    safeq = (int*)calloc(r, sizeof(int));
    bool a=true,b=true;
    if (safeq != NULL)
    {
        
            while(true)
            {            
                for (i=0;i<r;i++)
                {
                    j=0;
                    while(j<r)
                    {
                        if ( i+1 == safeq[j] )
                        a=false;
                        j++;
                    }
                    if (a){
                        for (j=0;j<c;j++)
                        {
                            if ( avail[j] < need[(i*c)+j])
                            {
                                a=false;
                                break;
                            }
                        }
                        if (a)
                        {
                            b=false;
                            safeq[p++]=i+1;
                            printf("\np%d addded to safe sequence",i);
                            printf("\nNew Available: ");
                            for(j=0;j<c;j++)
                            {
                                avail[j] += alloc[(i*c)+j];
                                printf("%d ",avail[j]);
                            }
                            printf("\n");
                        }
                    }
                    a=true;
                }
                if(p == r)
                {
                    printf("\n The Safe Sequence s: ");
                    for(j=0;j<r;j++){
                        printf("%d ",safeq[j]);
                    }
                    printf("\n");
                    break;
                }
                if(b){
                    printf("Deadloop!!!");
                    break;
                }
                b=true;
            } 
            printf("p=%d -- r=%d -- c=%d",p,r,c);
    }
    else{
        printf("memory not enough\n");
    }
}
