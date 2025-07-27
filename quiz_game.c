#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char question[4][100] = {"1. What is the jersey number of Virat Kohli?",
                          "2. Who is highest rated chess player ever existed?",
                          "3. Who decodes the Enigma machine?",
                          "4. Which team won the highest number of ODI World Cup?"};  // Questions

    char option[4][100] = {"a.17  b.05  c.18  d.07",
                        "a.Magnus Carlsen  b.Bobby Fischer  c.Mikhail Tal  d.Vishwanathan Anand",
                        "a.Nikola Tesla  b.Alan Turing  c.James Lestrad  d.Augustus Graham",
                        "a.England  b.Australia  c.India  d.West Indies"};  //Options

    char answer[] = {'c','a','b','b'};  //Answers
    char guess;

    int score = 0;


    for(int i=0;i<sizeof(question)/sizeof(question[0]);i++)  //Loop to print the questions
    {
        printf("%s\n",question[i]);
        
        for(int j=i;j<i+1;j++)              //Loop to print the answers
        {
            printf("%s\n",option[j]);
            
        }

        printf("ANSWER: ");                 //Taking input from user
        scanf("\n%c",&guess);
        guess = tolower(guess);

        if(guess=='a'||guess=='b'||guess=='c'||guess=='d')      //To check valid or invalid input
        {
            if(guess==answer[i])                    //Answer checking
            {
                score++;
                printf("\nRight Answer!!!");
            }
            else
            {
                printf("\nWrong Answer!!!");
            }
        }
        else                    //For invalid input giving chance to retry
        {
            printf("\n Invalid Input.\n Try Again!!!");
            i--;
        }

        printf("\n\n");
    }

    printf("\nYour Score: %d/4",score);         // Score print

    return 0;
}