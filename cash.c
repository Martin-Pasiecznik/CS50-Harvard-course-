///Suppose you work at a store and a customer gives you $1.00 (100 cents) for candy that costs $0.50 (50 cents). You’ll need to pay them their “change,” the amount leftover after paying for the cost of the candy. When making change, odds are you want to minimize the number of coins you’re dispensing for each customer, lest you run out (or annoy the customer!). In a file called cash.c in a folder called cash, implement a program in C that prints the minimum coins needed to make the given amount of change, in cents
#include <cs50.h>
#include <stdio.h>

int main(void){
    int owed;
    do
    {
        owed = get_int("Change owed: ");
    }
    while(owed<0);
    ///
    int total_coins=0;
    while(owed>0){
        if((owed>=25)){
            owed=owed-25;
            total_coins++;
    }
    else if(owed>=10 && owed<25){
        owed=owed-10;
        total_coins++;
    }
    else if(owed>=5 && owed<10){
        owed=owed-5;
        total_coins++;
    }
    else if(owed>0 && owed<5){
        owed=owed-1;
        total_coins++;
    }
}
    printf("Total coins: %d\n", total_coins);
}
