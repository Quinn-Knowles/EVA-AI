#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//This will be somewhat similar to a game of hangman. It will be a part of early testing for my AI self project.
//AVA-AI will play this game. 
//unlike real hangman, there is no loss condition, and letters must be guessed in order.
int main() {
    int playing = 1;
    char* words[5] = {"Cocoa","Lemon", "Itsuki", "Ranma", "Filia"};
    char guess[80]="";
    srand(time(NULL));
while(playing==1){
        printf("you're playing HANGMAN!!! \n");
        char* word = words[(rand()%5)];
        int x;
        int numberOfGuesses=0;
        for(x=0; x< (strlen(word)); x++){
            strncat(guess, "_ ", 2);
        }
        printf("%s", guess);
        printf("\n number of characters listed above, please provide input 1 letter at a time \n");
        char input;    
        x = 0;
        while(x<strlen(word)){
            fflush(stdin);
            scanf("%c",&input);
            fflush(stdin); 
            if(word[x] == input) {
                printf("correct\n");
                guess[(x*2)]=word[x];
                x++;
                	
            }
            else{
                printf("wrong\n");
            }
            printf("You're still playing HANGMAN.\n Here is where we are at: \n %s \n", guess);
            numberOfGuesses++;
        }
        printf("Game complete. You took %d guesses\n", numberOfGuesses);
        printf("continue? (y/n)\n");
        scanf("%c", &input);
        if('n'== input){
            playing =0;
        }
    }
    printf("successful exit");
    return 0;
}