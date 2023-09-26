/*
author: gabriel bussone
date: 26/09/2023
es. 2
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(){
    
    int a = 5;
    int b;
    int* pi;
    pi = &a;
    b = *pi;
    printf("%d", b);

    return 0;
}

