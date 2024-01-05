#include <stdio.h>
#include <string.h>

//This will be somewhat similar to a game of hangman. It will be a part of early testing for my AI self project.
//AVA-AI will play this game. 
//unlike real hangman, there is no loss condition, and letters must be guessed in order.
int main() {
    int playing = 1;
   char* word1 = "Cocoa";
   char* word2 = "Lemon";
   char* word3 = "Taro";
   char* guess;
while(playing==1){
        printf("you're playing HANGMAN!!! \n");
        int x;
        for(x=0; x< (strlen(word1)); x++){
            printf("_ ");
        }
        printf("\n number of characters listed above, please provide input 1 letter at a time \n");
        char input;    
        x = 0;
        while(x<strlen(word1)){
            scanf("%c",&input);
            if(word1[x] == input) {
                printf("correct\n");
                x++;	
            }	
        }

        printf("continue? (y/n)\n");
        scanf("%c", &input);
        if('n'== input){
            playing =0;
        }
    }
    printf("successful exit");
    return 0;
}