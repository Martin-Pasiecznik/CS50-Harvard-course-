//implement a program in C that determines the winner of a short Scrabble-like game. 
//Your program should prompt for input twice: once for “Player 1” to input their word and once for “Player 2” to input their word. 
//Then, depending on which player scores the most points, your program should either print “Player 1 wins!”, “Player 2 wins!”, or “Tie!”
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int calculate();
int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int total_score_player1 = calculate(player1); //Assigns the return value of the function.
    int total_score_player2 = calculate(player2);
    if(total_score_player2==total_score_player1) printf("Tie!\n");
    else if(total_score_player2<total_score_player1) printf("Player 1 Wins!\n");
    else printf("Player 2 Wins!\n");
}

int calculate(char *word){ // * idicates a pointer. 
    int points[26] ={1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int total_score=0;
    for(int i=0; i<strlen(word);i++){
        char caracter= toupper(word[i]); //transform the letter into a capital one.
        if(caracter>='A' && caracter<='Z'){
            total_score += points[caracter - 'A']; //adds the points to the score, depends on the letter in the word. Each letter corresponds to an index in the arrray points.
        }
    }
    return total_score;
}
