#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Z 11

void numRand(int *N){
    int R;
    int W;
    for(int i = 1;i<Z;i++){
        N[i-1] = i;
    }
    for(int i = 1;i<Z;i++){
        R = rand()*((Z+1)-i)+i;
        W = N[R];
        N[R] = N[i];
        N[i] = W;
    }
}

void printInstructions(int H){
    printf("THE OBJECT OF THIS GAME IS TO GUESS AN UNKNOWN NUMBER\n");
    printf("%c %d %c %d","NUMBERS 1 TO", Z ,".  YOU WILL BE GIVEN A HAND OF ", H);
    printf("CALLED THE 'DOWN NUMBER'.  THE GAME IS PLAYED WITH THE\n");
    printf("%c %d %c","RANDOMLY SELECTED NUMBERS BETWEEN 1 AND", Z,". THE \n");
    printf("COMPUTER WILL HAVE A SIMILAR HAND.  THE DOWN NUMBER WILL \n");
    printf("ALWAYS BE THE NUMBER NOT IN EITHER PLAYER HANDS.\n\n");
    
    printf("YOU ALTERNATE MOVES WITH THE COMPUTER. ON ANY MOVE THERE\n");
    printf("ARE TWO OPTIONS- GUESS THE DOWN NUMBER OR ASK ABOUT SOME \n");
    printf("NUMBER.\n\n");
   
    printf("WHEN A PLAYER GUESSES THE DOWN NUMBER THE GAME STOPS.\n");
    printf("IF THE GUESS IS CORRECT THAT PLAYER WINS.\n");
    printf("IF THE GUESS IS NOT CORRECT THAT PLAYER LOSES.\n");
    
    printf("ALL QUESTIONS ABOUT NUMBERS IN THE OTHER PLAYERS HAND\n");
    printf("MUST BE ANSWERED TRUTHFULLY.  A PLAYER MAY'BLUFF' BY\n");
    printf("ASKING ABOUT A NUMBER IN HIS OWN HAND.  THE COMPUTER\n");
    printf("WILL SOMETIMES DO THIS.\n");
    printf("A NUMBER MAY BE ASKED ABOUT ONLY ONCE.\n\n");
    
    printf("GOOD LUCK\n");
}

int getAnswer(char qes[]){
    char ans[4];
    printf("%s", qes);
    fgets(ans, 4, stdin);
    if(!strcmp(ans, "YES")){
        return 1;
    }
    else{
        if(!strcmp(ans, "NO")){
            return 0;
        }
    }
}

int main(){
    printf("GUESS-IT\n");
    printf("CREATIVE COMPUTING\n");
    printf("MORRISTOWN, NEW JERSEY\n");
    printf("\n\n\n");
    int G1 = 0;
    int C1 = 0;
    int A1 = rand();//hz
    int H = 5;
    int D;
    int K;
    int M;
    int n;

    int P[10][10];
    for(int k = 0;k < H; k++){
        P[k][0] = 1;
        P[0][k] = 1/(k+1);
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < H; j++){
            P[i][j] = (1+j*P[j][i-1]*(1 - P[j-1][i]))/(1+(j+2)*P[j][i-1]);
            P[j][i] = (1 + i*P[i][j-1]*(1-P[i-1][j]))/(1+(i+1)*P[i][j-1]);
        }
    }

    int U[Z];
    int N[Z];
    char answer[50];

    s210: ;
    printf("DO YOU WANT INSTRUCTIONS-TYPE YES OR NO");
    fgets(answer, 4, stdin);
    if(!strcmp(answer, "YES")){
        printInstructions(11, H);
    }
    else{
        if (strcmp(answer, "NO")){
            goto s210;
        }
    }
    G1 += 1;
    for(int j = 2;j<Z;j++){
        U[j] = 0;
    }
    int E = 0;
    int T = 0;
    int C=0;
    int P=0;
    int L=0;
    
    numRand(N);//1630
    //N(1) TO N(H)= COMP HAND N(H+1)=TO N(Z)= OTHER HAND
    D = Z;
    printf("YOUR HAND IS\n");
    for(int i = H+1;i<Z-1;i++){
        printf("%d ", N[i]);
    }
    printf("\n\n");
    s390: ;
    if(getAnswer("DO YOU WANT TO GO FIRST\n")){
        goto s470;
    }
    else{
        goto s390;
    }
    K = 1;
    goto s480;
    s470: ;
    s480: ;
    K+=1;
    M = H - C;
    N[0] = H - P[0][0];
    printf("\n");
    if(K==(K/2)*2){
        goto s860;
    }
    s530: ;
    printf("\n");
    if(getAnswer("DO YOU WANT TO GUESS THE DOWN NUMBER\n")){
        goto s1250;
    }
    else{
        goto s530;
    }

    printf("\n");
    
    return 0;
}