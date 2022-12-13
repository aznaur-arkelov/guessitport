#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define Z 11

float rgen(){
    return (float)(rand()%1000) / 1000.0;
}

void debugPrint(int j[], int n){
    for(int i = 0;i<n;i++)
        printf(" %d ", j[i]);
    printf("\n");
}

void clrinstrm(){
    while(getchar() != '\n');
}


void randA(float* A, float* H, int U[], int N[]){
    s1170: ;
    *A = (*H+1)*rgen()+*H+1;
    for(int j = 0;j<Z-1;j++){
        if(N[(int)*A] == U[j])
            goto s1170;
    }
}

void numRand(int *N)
{
    int R;
    float W;
    for (int i = 0; i < Z; i++) {N[i] = i;}
    for (int i = 0; i < Z; i++){
        R = rgen() * ((Z + 1) - i) + i;
        W = N[R%Z];
        N[R%Z] = N[i];
        N[i] = W;
    }
}

void printInstructions(float H)
{
    printf("\n%s\n", "THE OBJECT OF THIS GAME IS TO GUESS AN UNKNOWN NUMBER");
    printf("%s %d %s %d\n", "NUMBERS 1 TO", Z, ".  YOU WILL BE GIVEN A HAND OF ", (int)H);
    printf("%s\n", "CALLED THE 'DOWN NUMBER'.  THE GAME IS PLAYED WITH THE");
    printf("%s %d %s\n", "RANDOMLY SELECTED NUMBERS BETWEEN 1 AND", Z, ". THE ");
    printf("%s\n", "COMPUTER WILL HAVE A SIMILAR HAND.  THE DOWN NUMBER WILL ");
    printf("%s\n\n","ALWAYS BE THE NUMBER NOT IN EITHER PLAYER HANDS.");

    printf("%s\n", "YOU ALTERNATE MOVES WITH THE COMPUTER. ON ANY MOVE THERE");
    printf("%s\n", "ARE TWO OPTIONS- GUESS THE DOWN NUMBER OR ASK ABOUT SOME ");
    printf("%s\n\n", "NUMBER.");

    printf("%s\n", "WHEN A PLAYER GUESSES THE DOWN NUMBER THE GAME STOPS.");
    printf("%s\n", "IF THE GUESS IS CORRECT THAT PLAYER WINS.");
    printf("%s\n", "IF THE GUESS IS NOT CORRECT THAT PLAYER LOSES.");

    printf("%s\n", "ALL QUESTIONS ABOUT NUMBERS IN THE OTHER PLAYERS HAND");
    printf("%s\n", "MUST BE ANSWERED TRUTHFULLY.  A PLAYER MAY'BLUFF' BY");
    printf("%s\n", "ASKING ABOUT A NUMBER IN HIS OWN HAND.  THE COMPUTER");
    printf("%s\n", "WILL SOMETIMES DO THIS.");
    printf("%s\n\n", "A NUMBER MAY BE ASKED ABOUT ONLY ONCE.");

    printf("%s\n", "GOOD LUCK");
}

int getanswer(char qes[])
{
    char ans[4];
    for(int i = 0;i<100;i++){
        printf("%s\n? ", qes);
        fgets(ans, 3, stdin);
        clrinstrm();
        if (!strcmp(ans, "YE")){return 1;}
        if (!strcmp(ans, "NO")){return 0;}
    }
    return 0;
}


int main()
{
    printf("%60s\n","GUESS-IT");
    printf("%66s\n", "CREATIVE COMPUTING");
    printf("%68s\n","MORRISTOWN, NEW JERSEY");
    printf("\n\n\n");
    int G1 = 0, C1 = 0,  A1 = rgen(),  K = 0;
    int D, n, E, T, answer;
    int C, B, G, N[Z];
    float M, L, A, Y;
    float H = 5;
    float P[10][10];
    int U[Z];
    char As[4];

    for (int k = 0; k < H-1; k++)
    {
        P[k][0] = 1;
        P[0][k] = 1 / (k + 1);
    }
    for (int i = 0; i < H-1; i++)
        for (int j = 0; j < H-1; j++)
        {
            P[i][j] = (1 + j * P[j][i - 1] * (1 - P[j - 1][i])) / (1 + (j + 2) * P[j][i - 1]);
            P[j][i] = (1 + i * P[i][j - 1] * (1 - P[i - 1][j])) / (1 + (i + 1) * P[i][j - 1]);
        }

s210:;
    answer = getanswer("DO YOU WANT INSTRUCTIONS-TYPE YES OR NO");
    if(answer == 1){printInstructions(H);};

s250:;
    printf("\n");
    G1 += 1;
    for (int j = 2; j < Z; j++){U[j] = 0;}
    E = 0; T = 0; C = 0; B = 0;
    G = 0; L = 0; A = 0; Y = 0;

    numRand(N); // 1630
   ;// N(1) TO N(H)= COMP HAND N(H+1)=TO N(Z)= OTHER HAND
    D = Z;
    printf("%s\n", "YOUR HAND IS");
    for (int i = H + 1; i < Z; i++){ printf("%d ", N[i]); }
    printf("\n\n");

s390:;
    answer = getanswer("DO YOU WANT TO GO FIRST");
    if (answer == 1) {goto s470;}
    K = 1;
    goto s480;

s470:;
    K = 0;

s480:;
    K += 1;
    M = H - C;
    N[0] = H - P[0][0];
    printf("\n");
    if (K == (K / 2) * 2){goto s860;}

s530:;
    answer = getanswer("DO YOU WANT TO GUESS THE DOWN NUMBER");
    if (answer == 1) {goto s1250;}

s580:;
    printf("\n");
    printf("%s? ", "WHAT NUMBER DO YOU WANT TO ASK ABOUT");
    scanf("%d", &E);
    fflush(stdin);
    for (int i = 0; i < Z - 1; i++)
        if (E == U[i]) {goto s650;}
    
    goto s670;

s650:;
    printf("%d %s\n", E, " WAS ASKED BEFORE TRY AGAIN");
    goto s580;

s670:;
    for (int i = 0; i < H - 1; i++)
        if (N[i] == E) {goto s800;}

    printf("\n");
    printf("%d %s\n", E, "IS NOT IN MY HAND");
    if((int)M == 0) {goto s1460;}
    if(N[0] == 0) {goto s1440;}

    Y = ((M+1)*P[(int)M][(int)N[0]-1]-M*P[(int)(M-1)][(int)N[0]])/(1+(M+1)*P[(int)M][(int)N[0]-1]);
    if(rgen() < Y) {goto s1380;}
    L += 1;
    U[(int)L] = E;
    if(H - P[0][0] == 1) {goto s1460;}
    P[0][0] += 1;
    goto s480;

s800:;
    printf("\n");
    printf("%d %s\n", E, "IS IN MY HAND");//hz
    C += 1;
    L += 1;
    U[(int)L] = E;
    goto s480;

s860:;
    if(T != 0) {goto s1410;}
    if(H-C != 0) {goto s890;}
    goto s1460;

s890:;
    if(H - P[0][0] != 0) {goto s910;}
    goto s1460;

s910:;
    if(((2 * H - 2) - (P[0][0] + C)) != 0) {goto s930;}
    goto s1460;

s930:;
    if(rgen()>1/(1+(N[0]+1)*(P[(int)N[0]][(int)(M-1)]))) {goto s1060;}
    printf("\n");

s960:;
    A = (float)((H * rgen()) + 1);

    for(int j = 0; j < Z - 1; j++)
        if(N[(int)A] == U[j]) {goto s960;}

    printf("%s %d\n? ", "DO YOU HAVE", N[(int)A]);
    C += 1;
    fgets(As, 3, stdin);
    clrinstrm();

s1060:;
    E = N[(int)A];
    L += 1;
    U[(int)L] = E;
    goto s480;
    randA(&A, &H, U, N);
    printf("%s %d\n? ", "DO YOU HAVE", N[(int)A]);
    fgets(As, 4, stdin);
    clrinstrm();
    if(!strcmp(As, "YES")) {goto s1130;}
    T = 1;
    goto s480;

s1130:;
    E = N[(int)A];
    P[0][0] += 1;
    L += 1;
    U[(int)L] = E;
    goto s480;
    
s1250:;
    printf("\n");
    printf("WHAT DO YOU THINK THE DOWN NUMBER IS ");
    scanf("%d", &B);

    printf("\n");
    printf("%s %d\n", "THE DOWN NUMBER IS ", N[Z-1]);
    if (B == N[Z-1]) {goto s1360;}

    printf("\n");
    printf("%s %d %s\n", "YOUR  GUESS OF ", B, "IS NOT CORRECT-YOU LOSE");
    C1 += 1;
    goto s1520;
    printf("\n");

s1360:;
    printf("%s %d %s\n", "YOUR  GUESS OF ", B, "IS CORRECT-YOU WIN");
    goto s1520;

s1380:;
    printf("%s %d\n", "I THINK YOU WERE  NOT BLUFFING WHEN YOU ASKED ABOUT ", E);
    G = E;
    goto s1480;

s1410:;
    printf("%s\n", " WAS NOT A BLUFF");
    G = N[(int)A];
    goto s1480;

s1440:;
    G = N[Z-1];
    goto s1480;

s1460:;
    randA(&A, &H, U, N);
    G = N[(int)A];

s1480:;
    printf("I GUESS THE DOWN NUMBER IS\n");
    if (G == N[Z-1]) {goto s1590;}

s1590:;
    printf("\n");
    printf("%s %d %s\n", "THE DOWN NUMBER IS ", N[Z-1], " I WAS WRONG... YOU WIN");

s1520:;
    answer = getanswer("DO YOU WANT TO PLAY AGAIN");
    if (answer == 1) {goto s250;}
    printf("\n");
    printf("%s %d %s %d %s %d\n", "YOU PLAYED ", G1, "GAMES.  YOU LOST ", C1, " YOU WON ", G1 - C1);
    goto stop;
    
stop:;
    return 0;
}