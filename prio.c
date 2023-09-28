#include <stdio.h> 
typedef struct 
{ 
 int id, at, bt, ct, tat, wt, rt, priority; 
} process; 
int main() 
{ 
 int n, currentTime = 0; 
 float avgTAT, avgWT; 
 printf("Enter the number of processes: "); 
 scanf("%d", &n); 
 process a[n]; 
 printf("Enter the id, arrival time and burst time of n processes: \n"); 
 for (int i = 0; i < n; i++) 
 { 
 scanf("%d", &a[i].id); 
 scanf("%d", &a[i].at); 
 scanf("%d", &a[i].bt); 
 scanf("%d", &a[i].priority); 
 a[i].rt = a[i].bt; 
 } 
 int completed = 0; 
 int totalWT = 0; 
 int totalTAT = 0; 
 while (completed < n) 
 { 
 int sJob = -1; 
 int sPriority = 99999; 
 for (int i = 0; i < n; i++) 
 { 
 if (a[i].at <= currentTime && a[i].priority < sPriority && a[i].rt > 
0) 
 { 
 sJob = i; 
 sPriority = a[i].priority; 
 } 
 } 
 if (sJob == -1) 
 { 
 currentTime++; 
 } 
 else 
 { 
 a[sJob].rt--; 
 currentTime++; 
 if (a[sJob].rt == 0) 
 { 
 completed++; 
 a[sJob].ct = currentTime; 
 a[sJob].tat = currentTime - a[sJob].at; 
 a[sJob].wt = a[sJob].tat - a[sJob].bt; 
 totalTAT += a[sJob].tat; 
 totalWT += a[sJob].wt; 
 } 
 } 
 } 
 avgTAT = (float)totalTAT / n; 
 avgWT = (float)totalWT / n; 
 printf("\nID\tAT\tBT\tPrio\tCT\tTAT\tWT"); 
 for (int i = 0; i < n; i++) 
 { 
 printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d", a[i].id, a[i].at, a[i].bt, 
a[i].priority, a[i].ct, a[i].tat, a[i].wt); 
 } 
 printf("\nAverage Waiting Time = %f", avgWT); 
 printf("\nAverage Turn Around Time = %f\n", avgTAT); 
} 
Output (Priority)
Enter the number of processes: 5 
Enter the id, arrival time and burst time of n processes: 
1 0 5 6 
2 1 2 4 
3 2 4 3 
4 3 1 1 
5 4 7 2 
ID AT BT Prio CT TAT WT 
P1 0 5 6 19 19 14 
P2 1 2 4 15 14 12 
P3 2 4 3 14 12 8 
P4 3 1 1 4 1 0 
P5 4 7 2 11 7 0 
Average Waiting Time = 6.800000 
Average Turn Around Time = 10.600000 
