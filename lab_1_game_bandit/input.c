#include <stdio.h>

#include "input.h"
#include "print_answer.h"

int get_integer (){
    char answer[50];
    int n;
    scanf("%s", answer);
    while (sscanf(answer, "%d", &n) != 1) {
        printf("Incorrect input. Try again: ");
        scanf("%s", answer);
    }
    return n;
}

int enter_bet(int budget){
    int n;
    while(1){
        printf("\nPlease, enter bet: ");
        n = get_integer();
        if(n > budget || n<=0)
           print_incorrect_bet();
        else return n;   
    }
    return n;
}

int enter_budget(){
    int n;
    while(1){
        printf("\nPlease, enter budget: ");
        n = get_integer();
        if(n<=0)
           print_incorrect_bet();
        else return n;   
    }
    return n;
}

int choose_continue() {
    int input;
    input = get_integer();
    if(input == 1) return 1;
    else return 0;   
}


