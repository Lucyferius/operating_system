#include <stdio.h>

void print_win(int number) {
    printf("You win x%d!\n\n", number);
}
void print_return_bet() {
    printf("Return your bet\n\n");
}
void print_continue() {
    printf("Continue playing?\n1 -> Yes\n0 -> No\nYour answer: ");
}
void print_lose() {
    printf("You lose\n\n");
}
void print_current_budget(int budget) {
    printf("Your current budget: %d\n\n", budget);
}
void print_game_over() {
    printf("Game Over!\n\n");
}

void print_incorrect_bet(){
    printf("Incorrect bet count: bet>0 and bet<=budget");
}

void print_incorrect_budget(){
    printf("Incorrect budget count: budget>0");
}
