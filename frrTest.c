//
// Created by mana on 1/17/17.
//
#include "types.h"
#include "stat.h"
#include "user.h"

#define N 10

void childWait(void){
    for (int i = 0; i < 1000 ; i++) {
        
    }
    exit();
}

void frrTest(void){
    int pidTemp;
    pidTemp = fork();
    if(pidTemp == 0){
        childWait();
    }
}