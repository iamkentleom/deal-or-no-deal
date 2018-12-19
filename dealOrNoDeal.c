#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char caseNumbers[][10] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20"};
char prizes[][50] = {"1        ","5        ","10       ","25       ","50       ","75       ","100      ","200      ","500      ","750      ","1,000    ","5,000    ","10,000   ","25,000   ","50,000   ","75,000   ","100,000  ","250,000  ","500,000  ","1,000,000"};
int x[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int casesOpened[20];
int notOver = 1;
int choice;

void welcomeScreen(){
    printf("\n");
    printf("                                   WELCOME TO\n");
    printf(" ____  _____    _    _                    _   _  ___    ____  _____    _    _     \n");
    printf("|  _ \\| ____|  / \\  | |       ___  _ __  | \\ | |/ _ \\  |  _ \\| ____|  / \\  | |    \n");
    printf("| | | |  _|   / _ \\ | |      / _ \\| '__| |  \\| | | | | | | | |  _|   / _ \\ | |    \n");
    printf("| |_| | |___ / ___ \\| |___  | (_) | |    | |\\  | |_| | | |_| | |___ / ___ \\| |___ \n");
    printf("|____/|_____/_/   \\_\\_____|  \\___/|_|    |_| \\_|\\___/  |____/|_____/_/   \\_\\_____|\n");
    printf("\n");
    printf("                      Press 'E' to exit, any key to continue\n");
    char key = getch();
    if(key == 'e' || key == 'E'){
        notOver = 0;
    }

}

void chooseCase(){
    printf("\n        -- NOW CHOOSE YOUR LUCKY BRIEFCASE --\n\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("  : 01 :     : 02 :     : 03 :     : 04 :    : 05 :\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("  : 06 :     : 07 :     : 08 :     : 09 :    : 10 :\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("  : 11 :     : 12 :     : 13 :     : 14 :    : 15 :\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("\n");
    printf("  ------     ------     ------     ------    ------\n");
    printf("  : 16 :     : 17 :     : 18 :     : 19 :    : 20 :\n");
    printf("  ------     ------     ------     ------    ------\n\n");
    do{
        printf("Choice: ");
        scanf("%i", &choice);
        if(choice < 1 || choice > 20){
            printf("Invalid Choice.\n");
        }
    }while(choice < 1 || choice > 20);
    
}

void displayCases(char n[][10], char a[][50]){
    printf("\n\n");
    printf("                ------\n");
    if(choice < 10){
        printf("Your briefcase  : 0%i :\n", choice);
    }else{
        printf("Your briefcase  : %i :\n", choice);
    }
    printf("                ------\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("||           |                                                     |           ||\n");
    printf("||           |  ------     ------     ------     ------    ------  |           ||\n");
    printf("||           |  : %s :     : %s :     : %s :     : %s :    : %s :  |           ||\n", n[0], n[1], n[2], n[3], n[4]);
    printf("|| %s |  ------     ------     ------     ------    ------  | %s ||\n", a[0], a[10] );
    printf("|| %s |                                                     | %s ||\n", a[1], a[11] );
    printf("|| %s |  ------     ------     ------     ------    ------  | %s ||\n", a[2], a[12] );
    printf("|| %s |  : %s :     : %s :     : %s :     : %s :    : %s :  | %s ||\n", a[3], n[5], n[6], n[7], n[8], n[9], a[13] );
    printf("|| %s |  ------     ------     ------     ------    ------  | %s ||\n", a[4], a[14] );
    printf("||           |                                                     |           ||\n");
    printf("|| %s |  ------     ------     ------     ------    ------  | %s ||\n", a[5], a[15] );
    printf("|| %s |  : %s :     : %s :     : %s :     : %s :    : %s :  | %s ||\n", a[6], n[10], n[11], n[12], n[13], n[14], a[16] );
    printf("|| %s |  ------     ------     ------     ------    ------  | %s ||\n", a[7], a[17] );
    printf("|| %s |                                                     | %s ||\n", a[8], a[18] );
    printf("|| %s |  ------     ------     ------     ------    ------  | %s ||\n", a[9], a[19] );
    printf("||           |  : %s :     : %s :     : %s :     : %s :    : %s :  |           ||\n", n[15], n[16], n[17], n[18], n[19]);
    printf("||           |  ------     ------     ------     ------    ------  |           ||\n");
    printf("||           |                                                     |           ||\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("\n");
}

void juggleCases(){
    time_t t;
    srand((unsigned) time(&t));
    int n, m, temp;
    for(int i = 0; i < 100; i++){
        n = rand() % 20;
        m = rand() % 20;
        temp = x[n];
        x[n] = x [m];
        x[m] = temp;
    }
}

void openCase(){
    int currentChoice;
    int inside;
    int cont = 1;
    do{
        printf("Choice: ");
        scanf("%i", &currentChoice);
        if(currentChoice < 1 || currentChoice > 20 || currentChoice == choice){
            printf("Invalid Choice.\n");
        }else{
            cont = 0;
        }
    }while(cont);
    // system("cls");
    currentChoice--;
    inside = x[currentChoice];
    sleep(2);
    printf("    ------------------\n");
    printf("    :    %s   :\n", prizes[inside]);
    printf("    ------------------\n");
    for(int i = 0; i < 2; i++){
        caseNumbers[currentChoice][i] = ' ';
    }
    for(int i = 0; i < 9; i++){
        prizes[inside][i] = 'x';
    }
    sleep(4);
    system("cls");
    displayCases(caseNumbers, prizes);
    
}

void bankerOffer(){

}


int main(){
    // printf("%i", sizeof(x)/sizeof(x[0]));
    welcomeScreen();
    juggleCases();
    if(notOver){
        system("cls");
        chooseCase();
        for(int i = 0; i < 2; i++){
            caseNumbers[choice-1][i] = ' ';
        }
        system("cls");
        displayCases(caseNumbers, prizes);
        for(int i = 5; i > 0; i--){
            printf("%i more case(s) to open\n", i);
            openCase();
        }
    }else{
        system("cls");
        printf("\nThank you for playing :-)\n");
    }
}