/*#include<stdlib.h>
int main(){
    int A[100][4];
    int temp,i,j,n,t=0; float avgw,avgt;
    printf("Enter number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("\nEnter burst time for P%d",i+1);
        A[i][0]=i+1;
        scanf("%d",&A[i][1]);
    }
    for(i=0;i<n;i++){
        int index=i;
        for(j=i+1;j<n;j++){
            if (A[j][1]<A[j+1][1]){
            index=j;
            }
            temp=A[i][1];
            A[i][1]=A[index][1];
            A[index][1]=temp;
            temp=A[i][0];
            A[i][0]=A[index][0];
            A[index][0]=temp;
        }
    }
    A[0][2]=0;
    for(i=1;i<n;i++){
        A[i][2]=0;
        for(j=0;j<i;j++){
            A[i][2]+=A[j][i];
        }
        t+=A[i][2];
    }
    avgw=(float)t/n;
    t=0;
    printf("/nPID\tBT\tWT\tTT\n");
    for(i=0;i<n;i++){
        A[i][3]=A[i][1]+A[i][2];
        t+=A[i][3];
        printf("P%d\t%d\t%d\t%d\n",A[i][0],A[i][1],A[i][2],A[i][3]);

    }
    avgt=(float)t/n;
    printf("avgwt:\t%f\navgtt:\t%f",avgw,avgt);
}*/
/*#include <stdio.h>
int main() {
    int n, i, j, temp;
    int A[100][4]; 
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    float avgWaitingTime, avgTurnaroundTime;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the burst time for P%d: ", i + 1);
        A[i][0] = i + 1;
        scanf("%d", &A[i][1]);
    }
    for (i = 0; i < n - 1; i++) {
        int shortestJobIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j][1] < A[shortestJobIndex][1]) {
                shortestJobIndex = j;
            }
        }
        temp = A[i][1];
        A[i][1] = A[shortestJobIndex][1];
        A[shortestJobIndex][1] = temp;

        temp = A[i][0];
        A[i][0] = A[shortestJobIndex][0];
        A[shortestJobIndex][0] = temp;
    }

    A[0][2] = 0; 
    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++) {
            A[i][2] += A[j][1];
        }
        totalWaitingTime += A[i][2];
    }
    for (i = 0; i < n; i++) {
        A[i][3] = A[i][1] + A[i][2];
        totalTurnaroundTime += A[i][3];
    }

    avgWaitingTime = (float)totalWaitingTime / n;
    avgTurnaroundTime = (float)totalTurnaroundTime / n;

    printf("\nPID\tBT\tWT\tTT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", A[i][0], A[i][1], A[i][2], A[i][3]);
    }

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
}*/
#include<stdio.h>
 int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
  
    printf("nEnter Burst Time:n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
  
   //sorting of burst times
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
   
    wt[0]=0;            
  
   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
  
    avg_wt=(float)total/n;      
    total=0;
  
    printf("nProcesst    Burst Time    tWaiting TimetTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("np%dtt  %dtt    %dttt%d",p[i],bt[i],wt[i],tat[i]);
    }
  
    avg_tat=(float)total/n;    
    printf("nnAverage Waiting Time=%f",avg_wt);
    printf("nAverage Turnaround Time=%fn",avg_tat);
}
