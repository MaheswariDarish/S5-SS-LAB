#include <stdio.h>

struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].processId = i + 1;
        printf("Enter arrival time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    // Calculate completion time for each process
    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = currentTime + processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }

    // Calculate turnaround time and waiting time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }

    // Calculate average turnaround time and average waiting time
    double avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        avgTurnaroundTime += processes[i].turnaroundTime;
        avgWaitingTime += processes[i].waitingTime;
    }
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    // Display the schedule and results
    printf("\nFCFS Scheduling:\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].processId,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].completionTime,
               processes[i].turnaroundTime,
               processes[i].waitingTime);
    }
    printf("\nAverage Turnaround Time: %.2lf\n", avgTurnaroundTime);
    printf("Average Waiting Time: %.2lf\n", avgWaitingTime);

    return 0;
}
