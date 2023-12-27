
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prints out a 5x5 "card" or "pattern" */
/* Use for debugging! */
void print_card(int list[5][5]) {
    printf("\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++)
            printf("%s ", &list[i][j]);
            printf("\n");
    }
}

// DEFINE YOUR PROCEDURES HERE!!!
 
int is_it_crazy (int list[5][5]) {
    printf("\n");
    int crazyCounter = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (list[i][j] == 4) {
                crazyCounter += 1;
            }
        }
    }

    if (crazyCounter > 0) {
        return 1;
    } else {
        return 0;
    }
}

void marker (int list1[5][5], int list2[75], int list3[5][5], int count, int list4[5][5]) {

    print_card(list1);
    printf("\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", list2[i]);
    }
    printf("\n");
    print_card(list3);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (list3[j][k] == list2[i]) {                  /*ERROR HERE*/
                    if (is_it_crazy(list1) == 1) {
                        list4[j][k] = 4;
                    } else {
                        list4[j][k] = 1;
                    }
                }
            }
        }
    }
    
    if (is_it_crazy(list1) == 1) {
        list4[2][2] = 4;
    } else {
        list4[2][2] = 1;
    }
    
    print_card(list4);
}



int main() {    
    char* bingoPattern[5][5];
    char numStr[225]; /* the longest line of called numbers is 225 chars */
    char *calledStrNums[75];
    char *oneStrNum;
    int calledCt = 0;
    char* playerCard[5][5];
    char* playerMarkedCard[5][5];

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            fscanf(stdin,"%s", &bingoPattern[i][j]);
        }
    }
    
    fgets(numStr,225,stdin);
    fgets(numStr,225,stdin);
    fgets(numStr,225,stdin);
	
    // Adding a 0 or end indicator for array
    // FK deleted: char temp;
    // FK deleted: append(numStr, temp); 

    numStr[strlen(numStr)] = 0;  // Adding a 0 or end indicator for array

    oneStrNum = strtok(numStr," ");
	
    /* tokenize the string of space-separated numbers */
    while (oneStrNum != NULL ) {
	   calledStrNums[calledCt] = oneStrNum;
        calledCt++;
        oneStrNum = strtok(NULL," ");
    }    
    /* At this point, calledStrNums is a list of strings (the called numbers) */

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            fscanf(stdin, "%s", &playerCard[i][j]);
        }
    }

    int integerBingoPattern[5][5];
    int holding = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            holding = (int)(bingoPattern[i][j]);
            integerBingoPattern[i][j] = holding;
        }
    }

    int integerCalledStrNums[75];
    int holding1 = 0;
    int holding2 = 0;
    for (int i = 0; i < 75; i++) {
        integerCalledStrNums[i] = holding1;
    }
    for (int i = 0; i < calledCt; i++) {
        holding2 = atoi(calledStrNums[i]);
        integerCalledStrNums[i] = holding2;
    }

    int integerPlayerCard[5][5];
    int holding3 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            holding3 = (int)(playerCard[i][j]);
            integerPlayerCard[i][j] = holding3;
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            playerMarkedCard[i][j] = '0';
        }
    }
    int integerPlayerMarkedCard[5][5];
    int holding4 = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            holding4 = (int)(playerMarkedCard[i][j]);
            integerPlayerMarkedCard[i][j] = holding4;
        }
    }

    /* The following four lines are not for the */
    /* final project. They only print out the list */
    /* of called numbers with "->" between them to prove */
    /* to you that they are in the array as strings. */ 
    printf("\n");
    printf("calledCt: %d\n", calledCt);
    for(int i=0;i<calledCt;i++)
         printf("%s-> ",calledStrNums[i]);
    

   // PUT ALL CALLS TO OTHER PROCEDURES HERE!!! 
    printf("\n");
    printf("This line shows that 'calledStrNums' does have the correct String input: ");
    for (int i = 0; i < calledCt; i++) {
        printf("%s", calledStrNums[i]);
    }
    //print_card(bingoPattern);
    printf("\n");
    //print_card(playerCard);
    printf("\n");
    printf("The following lines of code represent the bingo pattern with the numbers stored as integers: \n");
    print_card(integerBingoPattern);
    printf("\n");
    printf("This line of code represents the called numbers as integers stored in an integer array: ");
    for (int i = 0; i < calledCt; i++) {
        printf("%d ", integerCalledStrNums[i]);
    }
    printf("\n");
    printf("\n");
    printf("The following lines of code represent the player's card with the numbers stored as integers: \n");
    print_card(integerPlayerCard);
    printf("\n");
    printf("The following lines of code represent the marked card with the numbers stored as integers.\nAt this point in the code, the function marker() has not been called so all of the indices hold 0s: \n");
    print_card(integerPlayerMarkedCard);
    printf("\n");

    printf("The following number represents whether or not the bingo pattern is crazy (1 for crazy, 0 for standard).\nI know the function uses string comparison, but for some reason it works properly so I have left it as is for now: \n");
    printf("%d\n", is_it_crazy(integerBingoPattern));
    
    printf("\n");
    printf("The following lines of code represent four arrays in this order -- the bingo pattern, the called numbers, the player card, and the marked card.\nThis shows that there is a problem with the called numbers array: \n");
    marker(integerBingoPattern, integerCalledStrNums, integerPlayerCard, calledCt, integerPlayerMarkedCard);
    //printf("\n");

    return 0;
}