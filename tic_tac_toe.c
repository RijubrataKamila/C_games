#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>


char  board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetboard(); //To reset the board
void print();  //To print the board
char winner_check();
int freespace();  //to check the free space
void player_move();  //for player's move
void comp_move();  //for computer's move

int main()
{
    char winner = ' ';
    char choice;

    
    do
    {
        winner = ' ';
        resetboard();
        srand(time(NULL));

        while (freespace()!=0 && winner ==' ')
        {
            print();

            player_move();
            comp_move();
            winner = winner_check();


        }
        
        print();

        if(winner==' ')
        {
            printf("\nOOPS! It was a draw.");
        }
        else if(winner == PLAYER)
        {
            printf("\nOUR WINNER IS PLAYER");
        }
        else
        {
            printf("\nOUR WINNER IS COMPUTER");
        }


        printf("\nDo You Want To Play Again?(Y/N)");
        scanf("\n%c",&choice);
        choice = toupper(choice);
    } while (choice!='N');
    

    return 0;
}

void resetboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}

void print()
{
    printf(" %c | %c | %c \n",board[0][0],board[0][1],board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[1][0],board[1][1],board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    
}

int freespace()
{
    int space=9;
    int i,j;

    for(i=0; i<3 ; i++)
    {
        for(j=0; j<3; j++)
        {
            if(board[i][j]!=' ')
            {
                space--;
            }
        }
    }

    return space;
}

void player_move()
{
    int row , col;

    do
    {
        printf("\nEnter the row num: ");
        scanf("%d",&row);
        printf("\nEnter the column num: ");
        scanf("%d",&col);
        row--;
        col--;

        if(board[row][col]==' ')
        {
            board[row][col] = PLAYER;
            break;
        }
        else
        {
            printf("\nThis place is occupied. Try Again!!!");
        }
    } while (freespace()!=0);
    
}

void comp_move()
{
    int row , col;

    do
    {
        

        row = rand() % 3;
        col = rand() % 3;

        if(board[row][col]==' ')
        {
            board[row][col] = COMPUTER;
            break;
        }

    } while (freespace()!=0);
    
    
}


char winner_check()
{
    int i;

    // row chceking
    for ( i = 0; i < 3; i++)
    {
        if(board[i][0]==board[i][1]&&board[i][0]==board[i][2]&&board[i][0]!=' ')
        {
            return board[i][0];
        }
    }

    // column checking
    for ( i = 0; i < 3; i++)
    {
        if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]&&board[0][i]!=' ')
        {
            return board[0][i];
        }
    }
    

    // diagonal checking
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]&&board[0][0]!=' ')
    {
        return board[0][0];
    }

    if (board[0][2]==board[1][1]&&board[0][2]==board[2][0]&&board[0][2]!=' ')
    {
        return board[0][2];
    }
    

    return ' ';
    
}