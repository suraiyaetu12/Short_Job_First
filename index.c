#include <stdio.h>

void findwt(int ps[], int n, int bt[], int wt[])
 {
    wt[0] = 0;

    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i - 1] + wt[i - 1];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (bt[j] > bt[j + 1]) {
                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                temp = ps[j];
                ps[j] = ps[j + 1];
                ps[j + 1] = temp;
            }
        }
    }
}

void findtat(int ps[], int n, int bt[], int wt[], int tat[]) {

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(int ps[], int n, int bt[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;


    findwt(ps, n, bt, wt);
    findtat(ps, n, bt, wt, tat);

    printf("Processes   Burst time   Waiting time  Turnaround time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("    %d ", ps[i]);
        printf("          %d ", bt[i]);
        printf("          %d", wt[i]);
        printf("          %d\n", tat[i]);
    }

    float avg_wt = (float)total_wt / (float)n;
    float avg_tat = (float)total_tat / (float)n;
    printf("Average waiting time = %.2f\n", avg_wt);
    printf("Average turnaround time = %.2f\n", avg_tat);
}

int main() {
    int pid[15], bt[15], n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process ids of all the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }

    printf("Enter burst time of all the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    findavgTime(pid, n, bt);

    return 0;
}



