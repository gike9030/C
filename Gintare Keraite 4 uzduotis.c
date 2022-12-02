//Gintare Keraite PS2
//Ávesti sveikà skaièiø N. Ávesti N sveikø skaièiø.
//Tarp ávestø skaièiø rasti ir iðvesti du skaièius artimiausius ávestø skaièiø vidurkiui: vienà maþesná uþ vidurká, o kità - didesná.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define CAPACITY 100
int validatingArray(int *size)
{
    if(*size < 0 || *size > CAPACITY)
    {
        printf("Number is too big/small! Manually change the capacity of an array!\n");
        exit(1);
    }
}
void cleanBuffer(char *Text)
{
    printf("%s", Text);
    while(getchar() != '\n')
        ;
}
int enterSize(int *size, char *wrongInputSize, char *enterSizeText)
{
    while(1)
    {
        printf("%s", enterSizeText);
        if(scanf("%d", size) && getchar() == '\n' && validatingArray(size))
            return 0;
        else
            cleanBuffer(wrongInputSize);
    }

}
int enterArray(int size, int *num, double *sum, char *wrongInputArray, char *enterArrayText)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%s", enterArrayText);
        if(scanf("%d", &num[i]))
           *sum += num[i];
        else
        {
            cleanBuffer(wrongInputArray);
            --i;
        }
    }
}
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int avg_max_min(int *average_min, int *average_max, int size, int *num, double average)
{
    //checking if all numbers are the same
    int t = 0;
    for(int i = 0; i < size; ++i)
        if(average == num[i])
            ++t;
    if (t == size)
        return 0;

    for(int i = 0; i < size; ++i)
    {
        if(average == num[i])  //if there is average between the array
        {
            *average_min = num[i-1];
            *average_max = num[i+1];
            return 1;
        }
        else if(average < num[i])   //if there is no average between the array numbers,
        {                            //and the next array element is bigger than average
            *average_min = num[i-1];
            *average_max = num[i];
            return 1;
        }
    }
}
int main()
{

    char *wrongInputSize = "Wrong input! Number has to be positive and integer! Repeat input!\n";
    char *wrongInputArray = "Wrong input! Repeat input!\n";
    char *enterSizeText = "Enter positive integer number for array size:\n";
    char *enterArrayText = "Enter array number:\n";

    double average, sum = 0;
    int size, numbers[CAPACITY], average_min, average_max, t;

    printf("From entered sequence of integer numbers, program finds two numbers: \n");
    printf("one bigger than average, second smaller than average.\n");

    enterSize(&size, wrongInputSize, enterSizeText);
    enterArray(size, numbers, &sum, wrongInputArray, enterArrayText);
    qsort(numbers, size, sizeof(int), cmpfunc);
    average = sum / size;
    if(avg_max_min( &average_min, &average_max, size, numbers, average))
    {
        printf("Number smaller than average: %d\n", average_min);
        printf("Number bigger than average: %d\n", average_max);
    }
    else
        printf("All numbers are the same, there are no bigger/smaller than average numbers!\n");
    return 0;
}
