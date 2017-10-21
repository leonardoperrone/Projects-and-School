//Leonardo Perrone
//f285y428
//CS540 Fall 2016
// Program1


#include <stdio.h> /* for printing the sequence */
#include <unistd.h>/* brings in the fork() command */
#include <sys/wait.h>/* for wait */
#include <stdlib.h>/* for the atoi library call */




int main(int argc, char **argv)
{
    int n, counter; //declaring variables
    counter = 1; //setting counter to 1
    pid_t pid;
    if (argc != 2) /* Just the executable and the input integer */
    {
        fprintf(stderr, "Usage: %s <integer value>\n", argv[0]);
        return 1;
    }
    
    n = atoi(argv[1]); //converting string input to integer
    
    if (n > 0 && n < 500000) //checking if input is positive and less than maximum set
    {
        
        pid = fork(); //call fork method assigning child pid to pid variable
        
        if (pid == 0 ) //if pid=0 then it is child
        {
        
            while (n != 1) //execute until n = 1, end of sequence
            {
                
                if(n%2==0) //if reminder is 0, then even number
                {
                    n=n/2;
                    if (n == 1)
                    {
                        printf("%i ",n); //if number is 1 then avoid placing comma after it
                    }
                    else
                    {
                        if (counter%10 == 0) //checking how many numbers are per line, 10 per line max
                        {
                            printf("%i, \n",n);
                        }
                        else
                        {
                            printf("%i, ",n);
                        }
                    }

                }
                else // else is odd
                {
                    n=(3*n)+ 1;
                   
                    if (n == 1)
                    {
                    printf("%i ",n);
                    }
                    else
                    {
                        if (counter%10 == 0)
                        {
                            printf("%i, \n",n);
                        }
                        else
                        {
                            printf("%i, ",n);
                        }

                    }
                }
                counter+=1;
            }
        }
        else if (pid>0) //parent
        {
            wait(&pid);  //wait until child process finishes

        }
        else //if not child
        {
            return 0;
            
        }
        printf("\n");
            
    }
    else // if number is negative or greater than 500,000
    {
        printf("Please enter a positive integer less than 500,000.\n");
    }
    
    
    return 0;
    
}
