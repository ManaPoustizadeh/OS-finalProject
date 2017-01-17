//
// Created by mana on 1/17/17.
//
#include "types.h"
#include "stat.h"
#include "user.h"

#define N  30
void sanity(void){
    int pid[N];
    int rTime[N],wTime[N];
    int rTimeTemp, wTimeTemp;
    for (int cid = 0; cid < 30; cid++) {
        pid[cid] = fork();
        if(cid%3 == 0){
            nice();
        }
        else{
            if(cid%3 == 1){
                nice();
                nice();
            }
        }
        for (int i = 0; i < 500; i++) {
            printf(2, "%d %d\n", pid, cid);
        }
        wait2(&wTimeTemp,&rTimeTemp);
        rTime[cid] = rTimeTemp;
        wTime[cid] = wTimeTemp;
    }
    if(pid > 0){
        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        int WTsum1 = 0;
        int RTsum1 = 0;
        int WTsum2 = 0;
        int RTsum2 = 0;
        int WTsum3 = 0;
        int RTsum3 = 0;
        int WTsum = 0;
        int RTsum = 0;
        for (int cid = 0; cid < 30; cid++) {
            printf(1, "child %d: wait time = %d, running time = %d, turnaround time = %d\n",pid[cid], wTime[cid], rTime[cid], wTime[cid]+rTime[cid]);
            if(cid%3 == 0){
                WTsum1 = wTime[cid]+WTsum1;
                RTsum1 = rTime[cid]+RTsum1;
                n1++;
            }
            if(cid%3 ==1){
                WTsum2 = wTime[cid]+WTsum2;
                RTsum2 = rTime[cid]+RTsum2;
                n2++;
            }
            if(cid%3 == 2){
                WTsum3 = wTime[cid]+WTsum3;
                RTsum3 = rTime[cid]+RTsum3;
                n3++;
            }
        }
        WTsum = WTsum1 + WTsum2 + WTsum3;
        WTsum = WTsum/30;
        WTsum1 = WTsum1/n1;
        WTsum2 = WTsum2/n2;
        WTsum3 = WTsum3/n3;
        printf(1, "average waiting: %d       average turnaround: %d", WTsum, WTsum + RTsum);
        printf(1, "average waiting in first queue: %d          average turnaround int first queue: %d", WTsum1, WTsum1 + RTsum1);
        printf(1, "average waiting in second queue: %d          average turnaround int second queue: %d", WTsum2, WTsum2 + RTsum2);
        printf(1, "average waiting in first queue: %d          average turnaround int first queue: %d", WTsum3, WTsum3 + RTsum3);
    }
}
