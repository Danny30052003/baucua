#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

char name[30];
int MAX = 100;
int balance;
int bau, cua, ca, cop, ga, tom;

//MODULE
void firstJoin();
void menu();
void instruction();
void betInstruction();
void diceInstruction();
void play();
void bet();
void betbau();
void betcua();
void betca();
void betcop();
void betga();
void bettom();
void dice();
void capital(char name[30]);
void withdrawExtraBlank(char name[30]);
void quit();


int main() {
    // system("clear"); //macos
    system("cls"); //window
    firstJoin();
    menu();
}

void firstJoin() {
    fflush(stdin);
    printf("Welcome to Bau Cua\n\nEnter your name to start: ");
    balance = 500;
    gets(name);
    capital(name);
    withdrawExtraBlank(name);
}
//----------------------------------------------------------------------
//MENU SECTION
void menu() {
    int option;
    printf("\n\n------------- BAU CUA -------------\n");
    printf("Welcome %s, Your balance is $%d\n\n", name, balance);
    printf("1 - Play\n");
    printf("2 - Instruction\n");
    printf("3 - Quit\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    
    switch(option) {
        case 1:
            play();
            break;
        case 2:
            instruction();
        case 3:
            quit();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            menu();
            break;
    }
}

void play() {
    int option;
    printf("\n------------- PLAY -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - Bet\n");
    printf("2 - Rolling dices\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            if(balance == 0 && bau == 0 && cua == 0 && ca == 0 && cop == 0 && ga == 0 && tom == 0) {
                printf("\nSorry but you have no money to bet!\n");
                play();
            }
            bet();
            break;
        case 2:
            if(bau == 0 && cua == 0 && ca == 0 && cop == 0 && ga == 0 && tom == 0) {
                printf("\nYou have to bet first to rolling dices!\n");
                play();
            } else {
                dice();
            }
            break;
        case 3:
            menu();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            play();
            break;
    }
}
//----------------------------------------------------------------------
//TEXT TRANSFORM SECTION
void capital(char name[30]) { 
        int len = strlen(name);
        char tmp[MAX]; 
        strcpy(tmp,name);
        for(int i=0; i<=len-1;i++) { 
            tmp[i]=toupper(tmp[i]);
        }
        strcpy(name, tmp); 
}

void withdrawExtraBlank(char name[30]) {
    char tmp[30];
    int len = strlen(name);
    strcpy(tmp, name);
    for(int i = 0; i <= len; i++) {
        if(tmp[0] == ' ') {
            for(int j = 0; j <= len; j++) {
                tmp[j] = tmp[j+1];
            }
        }
        if(tmp[i] == ' ' && tmp[i+1] == ' ') {
            for(int a = i + 1; a <= len; a++) {
                tmp[a] = tmp[a+1];
            }
        }
    }
    strcpy(name, tmp);
}
//----------------------------------------------------------------------
//INSTRUCTION SECTION
void instruction() {
    int option;
    printf("\n------------- INSTRUCTION -------------\n");
    printf("1 - How to bet?\n");
    printf("2 - How to roll dices?\n");
    printf("3 - Return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betInstruction();
            break;
        case 2:
            diceInstruction();
            break;
        case 3:
            break;
        default:
            printf("%d is not an option!\n\n", option);
    }
}

void betInstruction() {
    printf("\n------------- INSTRUCTION -------------\n");
    printf("              How to bet?\n");
    printf("1/ Select '1 - Bet' in Play\n");
    printf("2/ Select which animal that you want to bet for\n");
    printf("3/ Select deposit and enter the amount that you want to bet and money will\n");
    printf("be transfer from your balance to the game\n");
    printf("4/ Here is the place for you to bet & system pay you money if you win\n");
    printf("5/ If you won, you can select withdraw and take the money out\n");
    printf("------------------------------------\n");
    printf("press enter to return...");
    printf("\n\n");
    getchar(); getchar();
    menu();
}

void diceInstruction() {
    printf("\n------------- INSTRUCTION -------------\n");
    printf("          How to roll dices?\n");
    printf("1/ Select '2 - Rolling dices' in Play (You must aldready bet)\n");
    printf("2/ system will roll 3 dices\n");
    printf("3/ for each dice you won, you get the money that you bet for\n");
    printf("For example: you bet Ga $1\n1 dice in Ga, you get back your $1 and $1 more\n2 dices in Ga, you get $1 back and $2\n3 dices in Ga you get $1 back and win $3\n");
    printf("4/ If the animal that you bet lost, you will lose the money that you bet for that animal\n");
    printf("Note: The money that you win will be in the bet section of the animal you win\n");
    printf("If you win ga, go to bet and select ga, you will se the money + prizes there\n");
    printf("------------------------------------\n");
    printf("press enter to return...");
    printf("\n\n");
    getchar(); getchar();
    menu();
}
//----------------------------------------------------------------------
//BET MONEY SECTION
void bet() {
     int option;
    printf("\n------------- BET -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - Ga ($%d)\n", ga);
    printf("2 - Bau ($%d)\n", bau);
    printf("3 - Cop ($%d)\n", cop);
    printf("4 - Tom ($%d)\n", tom);
    printf("5 - Cua ($%d)\n", cua);
    printf("6 - Ca ($%d)\n", ca);
    printf("7 - Withdraw all\n");
    printf("8 - Return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betga();
            break;
        case 2:
            betbau();
            break;
        case 3:
            betcop();
            break;
        case 4:
            bettom();
            break;
        case 5:
            betcua();
            break;
        case 6:
            betca();
            break;
        case 7:
            if(bau == 0 && cua == 0 && ca == 0 && cop == 0 && ga == 0 && tom == 0) {
                printf("\nThere is nothing to withdraw!\n");
                bet();
            }
            else {
                balance = bau + cua + ca + cop + ga + tom + balance;
                bau = 0; cua = 0; ca = 0; cop = 0; tom = 0; ga = 0;
                printf("\nWithdraw succesfully!\n");
                bet();
            }
            break;
        case 8:
            play();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            bet();
            break;
    }
}

void betbau() {
    int option, betMoney = bau, withdrawBetMoney = 0;
    printf("\n\n------------- BAU -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - Deposit Money\n");
    printf("2 - Withdraw money\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betAsk:printf("How many $ you want to bet for Bau? ");
            scanf("%d", &betMoney);
            if(betMoney > balance) {
                printf("\nYou can not bet $%d, because your balance is $%d\n\n", betMoney, balance);
                goto betAsk;
            }
            balance = balance - betMoney;
            betMoney = bau + betMoney;
            bau = betMoney;
            printf("\nYou have betted total $%d in Bau! Your current Balace is $%d", betMoney, balance);
            betbau();
            break;
        case 2:
            if(betMoney == 0) {
                printf("You haven't bet any money for Bau to withdraw!\n");
                betbau();
            } else {
                printf("You have $%d in Bau, how many do you want to withdraw? ", bau);
                scanf("%d", &withdrawBetMoney);
                if(withdrawBetMoney > betMoney) {
                    printf("\nYou can't withdraw $%d\n", withdrawBetMoney);
                } else {
                    balance = withdrawBetMoney + balance;
                    betMoney = betMoney - withdrawBetMoney;
                    bau = betMoney;
                    printf("\nYou have withdrawd $%d from Bau! Your current Balace is %d\n\n", withdrawBetMoney, balance);
                }
            }
            betbau();
            break;
        case 3:
            bet();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            betbau();
            break;
    }
}

void betcua() {
    int option, betMoney = cua, withdrawBetMoney = 0;
    printf("\n\n------------- CUA -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - deposit Money\n");
    printf("2 - withdraw money\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betAsk:printf("How many $ you want to bet for Cua? ");
            scanf("%d", &betMoney);
            if(betMoney > balance) {
                printf("\nYou can not bet $%d, because your balance is $%d\n\n", betMoney, balance);
                goto betAsk;
            }
            balance = balance - betMoney;
            betMoney = cua + betMoney;
            cua = betMoney;
            printf("\nYou have betted total $%d in Cua! Your current Balace is $%d", betMoney, balance);
            betcua();
            break;
        case 2:
            if(betMoney == 0) {
                printf("You haven't bet any money for Cua to withdraw!\n");
                betcua();
            } else {
                printf("You have $%d in Cua, how many do you want to withdraw? ", cua);
                scanf("%d", &withdrawBetMoney);
                if(withdrawBetMoney > betMoney) {
                    printf("\nYou can't withdraw $%d\n", withdrawBetMoney);
                } else {
                    balance = withdrawBetMoney + balance;
                    betMoney = betMoney - withdrawBetMoney;
                    cua = betMoney;
                    printf("\nYou have withdrawd $%d from Cua! Your current Balace is %d\n\n", withdrawBetMoney, balance);
                }
            }
            betcua();
            break;
        case 3:
            bet();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            betcua();
            break;
    }
}

void betca() {
    int option, betMoney = ca, withdrawBetMoney = 0;
    printf("\n\n------------- CA -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - deposit Money\n");
    printf("2 - withdraw money\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betAsk:printf("How many $ you want to bet for Ca? ");
            scanf("%d", &betMoney);
            if(betMoney > balance) {
                printf("\nYou can not bet $%d, because your balance is $%d\n\n", betMoney, balance);
                goto betAsk;
            }
            balance = balance - betMoney;
            betMoney = ca + betMoney;
            ca = betMoney;
            printf("\nYou have betted total $%d in Ca! Your current Balace is $%d", betMoney, balance);
            betca();
            break;
        case 2:
            if(betMoney == 0) {
                printf("You haven't bet any money for Ca to withdraw!\n");
                betca();
            } else {
                printf("You have $%d in Ca, how many do you want to withdraw? ", ca);
                scanf("%d", &withdrawBetMoney);
                if(withdrawBetMoney > betMoney) {
                    printf("\nYou can't withdraw $%d\n", withdrawBetMoney);
                } else {
                    balance = withdrawBetMoney + balance;
                    betMoney = betMoney - withdrawBetMoney;
                    ca = betMoney;
                    printf("\nYou have withdrawd $%d from Ca! Your current Balace is %d\n\n", withdrawBetMoney, balance);
                }
            }
            betca();
            break;
        case 3:
            bet();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            betca();
            break;
    }
}

void betcop() {
    int option, betMoney = cop, withdrawBetMoney = 0;
    printf("\n\n------------- COP -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - deposit Money\n");
    printf("2 - withdraw money\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betAsk:printf("How many $ you want to bet for Cop? ");
            scanf("%d", &betMoney);
            if(betMoney > balance) {
                printf("\nYou can not bet $%d, because your balance is $%d\n\n", betMoney, balance);
                goto betAsk;
            }
            balance = balance - betMoney;
            betMoney = cop + betMoney;
            cop = betMoney;
            printf("\nYou have betted total $%d in Cop! Your current Balace is $%d", betMoney, balance);
            betcop();
            break;
        case 2:
            if(betMoney == 0) {
                printf("You haven't bet any money for Cop to withdraw!\n");
                betcop();
            } else {
                printf("You have $%d in Cop, how many do you want to withdraw? ", cop);
                scanf("%d", &withdrawBetMoney);
                if(withdrawBetMoney > betMoney) {
                    printf("\nYou can't withdraw $%d\n", withdrawBetMoney);
                } else {
                    balance = withdrawBetMoney + balance;
                    betMoney = betMoney - withdrawBetMoney;
                    cop = betMoney;
                    printf("\nYou have withdrawd $%d from Cop! Your current Balace is %d\n\n", withdrawBetMoney, balance);
                }
            }
            betcop();
            break;
        case 3:
            bet();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            betcop();
            break;
    }
}

void betga() {
    int option, betMoney = ga, withdrawBetMoney = 0;
    printf("\n\n------------- GA -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - deposit Money\n");
    printf("2 - withdraw money\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betAsk:printf("How many $ you want to bet for Ga? ");
            scanf("%d", &betMoney);
            if(betMoney > balance) {
                printf("\nYou can not bet $%d, because your balance is $%d\n\n", betMoney, balance);
                goto betAsk;
            }
            balance = balance - betMoney;
            betMoney = ga + betMoney;
            ga = betMoney;
            printf("\nYou have betted total $%d in Ga! Your current Balace is $%d", betMoney, balance);
            betga();
            break;
        case 2:
            if(betMoney == 0) {
                printf("You haven't bet any money for Ga to withdraw!\n");
                betga();
            } else {
                printf("You have $%d in Ga, how many do you want to withdraw? ", ga);
                scanf("%d", &withdrawBetMoney);
                if(withdrawBetMoney > betMoney) {
                    printf("\nYou can't withdraw $%d\n", withdrawBetMoney);
                } else {
                    balance = withdrawBetMoney + balance;
                    betMoney = betMoney - withdrawBetMoney;
                    ga = betMoney;
                    printf("\nYou have withdrawd $%d from Ga! Your current Balace is %d\n\n", withdrawBetMoney, balance);
                }
            }
            betga();
            break;
        case 3:
            bet();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            betga();
            break;
    }
}

void bettom() {
    int option, betMoney = tom, withdrawBetMoney = 0;
    printf("\n\n------------- TOM -------------\n");
    printf("User: %s | Balance: $%d\n", name, balance);
    printf("1 - deposit Money\n");
    printf("2 - withdraw money\n");
    printf("3 - return\n");
    printf("------------------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            betAsk:printf("How many $ you want to bet for Tom? ");
            scanf("%d", &betMoney);
            if(betMoney > balance) {
                printf("\nYou can not bet $%d, because your balance is $%d\n\n", betMoney, balance);
                goto betAsk;
            }
            balance = balance - betMoney;
            betMoney = tom + betMoney;
            tom = betMoney;
            printf("\nYou have betted total $%d in Tom! Your current Balace is $%d\n\n", betMoney, balance);
            bettom();
            break;
        case 2:
            if(betMoney == 0) {
                printf("You haven't bet any money for Tom to withdraw!\n");
                bettom();
            } else {
                printf("You have $%d in Tom, how many do you want to withdraw? ", tom);
                scanf("%d", &withdrawBetMoney);
                if(withdrawBetMoney > betMoney) {
                    printf("\nYou can't withdraw $%d\n", withdrawBetMoney);
                } else {
                    balance = withdrawBetMoney + balance;
                    betMoney = betMoney - withdrawBetMoney;
                    tom = betMoney;
                    printf("\nYou have withdrawd $%d from Tom! Your current Balace is %d\n\n", withdrawBetMoney, balance);
                }
            }
            bettom();
            break;
        case 3:
            bet();
            break;
        default:
            printf("%d is not an option!\n\n", option);
            bettom();
            break;
    }
}
//----------------------------------------------------------------------
//ROLLING DICE SECTION
void dice() {
    int dice1, dice2, dice3, option;
    int baudice = bau, 
        cuadice = cua, 
        cadice  = ca, 
        copdice = cop, 
        gadice  = ga, 
        tomdice = tom;
    //ROLL
    //RANDOM BY CURRENT TIME
    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    dice3 = rand() % 6 + 1;

    //PRINT
    printf("\n----------------------------");
    switch (dice1) {
    case 1:
        printf("\nDice 1: Bau\n");
        bau = bau + baudice;
        break;
    case 2:
        printf("\nDice 1: Cua\n");
        cua = cua + cuadice;
        break;
    case 3:
        printf("\nDice 1: Ca\n");
        ca = ca + cadice;
        break;
    case 4:
        printf("\nDice 1: Cop\n");
        cop = cop + copdice;
        break;
    case 5:
        printf("\nDice 1: Ga\n");
        ga = ga + gadice;
        break;
    case 6:
        printf("\nDice 1: Tom\n");
        tom = tom + tomdice;
        break;
    default:
        break;
    }
    switch (dice2) {
    case 1:
        printf("Dice 2: Bau\n");
        bau = bau + baudice;
        break;
    case 2:
        printf("Dice 2: Cua\n");
        cua = cua + cuadice;
        break;
    case 3:
        printf("Dice 2: Ca\n");
        ca = ca + cadice;
        break;
    case 4:
        printf("Dice 2: Cop\n");
        cop = cop + copdice;
        break;
    case 5:
        printf("Dice 2: Ga\n");
        ga = ga + gadice;
        break;
    case 6:
        printf("Dice 2: Tom\n");
        tom = tom + tomdice;
        break;
    default:
        break;
    }
    switch (dice3) {
    case 1:
        printf("Dice 3: Bau\n");
        bau = bau + baudice;
        break;
    case 2:
        printf("Dice 3: Cua\n");
        cua = cua + cuadice;
        break;
    case 3:
        printf("Dice 3: Ca\n");
        ca = ca + cadice;
        break;
    case 4:
        printf("Dice 3: Cop\n");
        cop = cop + copdice;
        break;
    case 5:
        printf("Dice 3: Ga\n");
        ga = ga + gadice;
        break;
    case 6:
        printf("Dice 3: Tom\n");
        tom = tom + tomdice;
        break;
    default:
        break;
    }
    //IF NOT APPEAR IN ANY DICE, LOSE MONEY
    if(dice1 != 1 && dice2 != 1 && dice3 != 1) bau = 0;
    if(dice1 != 2 && dice2 != 2 && dice3 != 2) cua = 0;
    if(dice1 != 3 && dice2 != 3 && dice3 != 3) ca = 0;
    if(dice1 != 4 && dice2 != 4 && dice3 != 4) cop = 0;
    if(dice1 != 5 && dice2 != 5 && dice3 != 5) ga = 0;
    if(dice1 != 6 && dice2 != 6 && dice3 != 6) tom = 0;
    printf("\n1 - Bet\n");
    printf("2 - Return\n");
    printf("----------------------------\n");
    scanf("%d", &option);
    switch(option) {
        case 1:
            if(balance > 0 || ga > 0 || bau > 0 || cua > 0 || ca > 0 || cop > 0 || tom > 0) {
                bet();
            }
            else {
                printf("\nUh Oh, you don't have any money to play!");
                menu();
            }
            break;
        default:
            play();
            break;
    }
}
//--------------------------
//  QUIT
void quit() {
    fflush(stdin);
    char confirm[4];
    printf("Confirm quitting (Yes/No): ");
    gets(confirm);
    for(int i = 0; i < 4; i++) {
        confirm[i] = toupper(confirm[i]);
    }
    if(strcmp(confirm, "YES") == 0) {
        goto out;
    } 
    if(strcmp(confirm, "NO") == 0) {
        printf("\n\nCancelled!\n");
        menu();
    }
    else {
        printf("\n\nUndefined command, please try again!\n\n");
        quit();
    }
    out:printf("\n\nQuitted!\n\n");
}
