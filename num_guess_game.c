#include<stdio.h>
#include<time.h> // for time function
#include<stdlib.h> // for rand and srand function

int main()
{
    const int MAX=100;  //number range(1-100)
    const int MIN=1;
    int num, guess;
    int attempt=0;

    srand(time(NULL)); //seed of the random number

    num = (rand() % MAX )+ MIN; //random number stores in num

    do
    {
        printf("\nEnter your guess: ");     //Taking input
        scanf("%d",&guess);
        attempt++;
        

        //comparision  

        
        if(guess>num)
        {
            printf("\n Your guess is too high. TRY AGAIN!!!");
        }
        else if(guess<num) 
        {
            printf("\n Your guess is too low. TRY AGAIN!!!");
        }
        else
        {
            break;
        }

    } while (guess!=num);
    
    printf("\n You Got it!!!");
    printf("\n The number is %d",guess);
    printf("\n No. of guesses: %d",attempt);

    return 0;
}