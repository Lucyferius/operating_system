#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "input.h"
#include "print_answer.h"
#include "logic.h"

int main() {
    srand(time(NULL));
    
    int budget = enter_budget();
    int length = 6;
    int play = 1;
    
    while (play) {
    	
        int bet = enter_bet(budget);
	

        int* array = generate_array(length);
        if(array == NULL) exit(1);
        print_array(array, length);
	
	if(check_return_bet(array, length) 
	|| check_one_thirds_numbers_are_the_same(array, length)){
	    print_return_bet();
	} else if (check_tripple_win(array, length, 7)) {
            print_win(3);
            budget += bet * 3;
        
        } else if (check_all_numbers_equals_double_win(array, length)) {
            print_win(2);
            budget += bet * 2;
        } else {
            print_lose();
            budget -= bet;
        }

        print_current_budget(budget);
	
	if(budget<=0){
	    print_game_over();	    
	}
	
	print_continue();
        int continue_game = choose_continue();
        
        if (continue_game == 0) {
            play = 0;
            free(array);
        } else if (continue_game == 1 && budget <=0 ){
            budget = enter_budget();
        }
      
    }

    return 0;
}
