#include <stdio.h>
struct gameData{
   int randomNumber;
   char input;
   int correct;
   char guess[80];
   int numberOfGuesses;
   int characterNumber;
   int playing; 
};
char* letters[52] = { "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

void Game(struct gameData *gameState){
   char* words[5] = {"Cocoa","Lemon", "Itsuki", "Ranma", "Filia"};   
   char* word = words[gameState->randomNumber];
   if(gameState->guess==" "){
      int x =0;
      for(x=0; x< (strlen(word)); x++){
         strncat(gameState->guess, "_ ", 2);
         }
   }
   if(word[gameState->characterNumber] == gameState->input) {
      gameState->guess[(gameState->characterNumber*2)]=word[gameState->characterNumber];
      gameState->characterNumber= gameState->characterNumber+1;
      gameState->correct=1;    	
      }
   else{
      gameState->correct=0;
   }
   gameState->numberOfGuesses++;
   if( gameState->characterNumber >= strlen(word)){
      gameState->playing = 0;
   }
   return;
}

int writeGradient(int gradient[], struct gameData *gameState){

   char* dir = "./Gradients/";
   
   char *fileName ="Cont.txt";
   FILE *fp = fopen("./Gradients/cont.txt", "w");
   int x;
   for(x=0;x<52;x++){
      fprintf(fp, letters[x]);
      fprintf(fp, " = %d\n", gradient[x]);
   }

   fclose(fp);
   return 0;
}

int main() {
   srand(time(NULL));
   struct gameData* gameState = (struct gameData*) malloc(sizeof(struct gameData));
   gameState->randomNumber = rand()%5;
   gameState->input =  "";
   gameState->guess[0] = " ";
   gameState->numberOfGuesses = 0;
   gameState->playing=1;
   int gradient[52];
   int total = 10000;
   int x;
   for(x=51; x>=0;x--){
      total = total - 192;
      gradient[x] = total;
   }
   gradient[0]=0;
   printf("main");
   writeGradient(gradient, gameState);

   return 0;
}