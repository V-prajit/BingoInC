//Prajit Viswanadha, 1002130106

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillBingoCard(int BingoCard[5][5]);
void PrintBingoCard(int BingoCard[5][5]);
int PickNumber(int PreviouslyPickedNumbers[75], int *numPicked);
void PrintSelectedNumber(int RandomlyPickedNumber);
int CheckIfNumberIsInCard(int BingoCard[5][5], int RandomlyPickedNumber);
int CheckIfColumns(int BingoCard[5][5]);
int CheckIfRows(int BingoCard[5][5]);
int CheckIfDiagonal(int BingoCard[5][5]);
int main(void)
{
    int BingoCard[5][5];
    int PreviouslyPickedNumbers[75] = {0};
    int numPicked = 0;
    int RandomlyPickedNumber = 0;
    int Verify = 0;
    srand(time(NULL));
    FillBingoCard(BingoCard);
    int ColumnFinished = CheckIfColumns(BingoCard);
    int RowFinished = CheckIfRows(BingoCard);
    int DiagonalFinished = CheckIfDiagonal(BingoCard);
    char Response;
    while (!ColumnFinished & !RowFinished & !DiagonalFinished)
    {
        PrintBingoCard(BingoCard);
        RandomlyPickedNumber = PickNumber(PreviouslyPickedNumbers, &numPicked);
        PrintSelectedNumber(RandomlyPickedNumber);
        printf("Do you have it? (Y/N)");
        scanf(" %c", &Response);
        if(Response == 'Y' || Response == 'y'){
            Verify = CheckIfNumberIsInCard(BingoCard, RandomlyPickedNumber);
            if(Verify == 0){
                printf("The value is not on your BINGO card - are you trying to cheat??\n");
            }
        }
        else 
        {
            continue;
        }
        ColumnFinished = CheckIfColumns(BingoCard);
        RowFinished = CheckIfRows(BingoCard);
        DiagonalFinished = CheckIfDiagonal(BingoCard);
    }

    return 0;
}

void FillBingoCard(int BingoCard[5][5])
{
    int row, column, result;
    for (column = 0; column<5; column++)
    {
        int low_num = 1+column*15;
        int hi_num = 15+column*15;

        for (row = 0; row<5; row++)
        {
            int check = 0;
            while (!check){
                check = 1;
                result = (rand()%(hi_num - low_num + 1)) + low_num;
                for (int k =0; k < row; k++)
                {
                    if (BingoCard[k][column] == result)
                    {
                        check = 0;
                        break;
                    }
                }
            }
            BingoCard[row][column] = result;
        }
    }
    BingoCard[2][2] = 0;
}

void PrintBingoCard(int BingoCard[5][5])
{
    printf("     B        I        N        G        O\n");
    printf("----------------------------------------------\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) 
            {   
                if (BingoCard[i][j] == 0){
                    printf("|    X   ");
                }
                else
                {
                    printf("|   %2d   ", BingoCard[i][j]);
                }
            }
        printf("|");
        printf("\n");
        printf("----------------------------------------------\n");
    }
}

int PickNumber(int PreviouslyPickedNumbers[75], int *numPicked){
    int lower_bound = 1, higher_bound = 75;
    int unique = 0;
    int NumberPicked;
    while (!unique){
        unique = 1;
        NumberPicked = rand()%(higher_bound-lower_bound + 1) + lower_bound;
        for (int i = 0; i < *numPicked; i++){
            if (PreviouslyPickedNumbers[i] == NumberPicked){
                unique = 0;
                break;
            }
        }
    }
    PreviouslyPickedNumbers[*numPicked] = NumberPicked;
    (*numPicked)++;
    return NumberPicked;
}

void PrintSelectedNumber(int RandomlyPickedNumber){
    printf("The next number is ");
    if (RandomlyPickedNumber < 16)
    {
        printf("B%d\n", RandomlyPickedNumber);
    }
    if (RandomlyPickedNumber < 31 && RandomlyPickedNumber > 15)
    {
        printf("I%d\n", RandomlyPickedNumber);
    }
    if (RandomlyPickedNumber < 46 && RandomlyPickedNumber > 30)
    {
        printf("N%d\n", RandomlyPickedNumber);
    }
    if (RandomlyPickedNumber < 61 && RandomlyPickedNumber > 45)
    {
        printf("G%d\n", RandomlyPickedNumber);
    }
    if (RandomlyPickedNumber < 76 && RandomlyPickedNumber > 60)
    {
        printf("O%d\n", RandomlyPickedNumber);
    }
}

int CheckIfColumns(int BingoCard[5][5]){
    for (int i = 0; i<5; i++)
    {
        int counter = 0;
        for (int j = 0; j < 5; j++)
        {
            if (BingoCard[j][i] == 0)
            {
                counter += 1;
            }
        }
        if (counter == 5){
            printf("You Finished A Column - BINGO\n");
            return 1;
        }
    }
    return 0;
}

int CheckIfRows(int BingoCard[5][5]){
    for (int i = 0; i<5; i++)
    {
        int counter = 0;
        for (int j = 0; j < 5; j++)
        {
            if (BingoCard[i][j] == 0)
            {
                counter += 1;
            }
        }
        if (counter == 5){
            printf("You Finished A Row - BINGO\n");
            return 1;
        }
    }
    return 0;
}

int CheckIfDiagonal(int BingoCard[5][5]){
    int counter = 0;
    int counter2 = 0;
    for (int i = 0; i<5; i++)
    {
        if (BingoCard[i][i] == 0)
        {
            counter += 1;
        }
        if (BingoCard[i][4-i] == 0)
        {
            counter2 += 1;
        }
    }
    if (counter == 5 || counter2 == 5){
        printf("You Finished A Diagonal - BINGO\n");
        return 1;
    }
    return 0;
}

int CheckIfNumberIsInCard(int BingoCard[5][5], int RandomlyPickedNumber){
    for (int i = 0; i<5; i++){
        for (int j = 0; j<5; j++){
            if (BingoCard[i][j] == RandomlyPickedNumber){
                BingoCard[i][j] = 0;
                return 1;
            }
        }
    }
    return 0;
}