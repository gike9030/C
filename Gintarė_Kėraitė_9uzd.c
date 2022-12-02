//Gintare Keraite, PS

/*9.Ivesti  sveika  skaiciu  A. Ivedineti  sveiku  skaiciu  seka  tol,  kol  vienas
po  kito  ivestu skaiciu skirtumo modulis bus mazesnis uz A.
Isvesti didziausia ir maziausia sekos narius.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    const int size = 100;
    int seka[size], //masyvas sekos skaiciams
        a,          //sveikas skaicius palyginimui
        j = 0,      //indikatorius, skaiciuojantis ivestos sekos skaiciu kieki
        ind,        //saugo pries tai buvusio skaiciaus numeri
        minn,       //maziausias skaicius sekoje
        maxx,       //didziausias skaicius sekoje
        sk = 1;

    while(sk == 1)
    {
        printf("IVESKITE SVEIKA SKAICIU: ");
        if( scanf("%d", &a) && getchar() == '\n')
           --sk ;
        else
        {
            printf("Neteisinga ivestis! Veskite dar karta!\n ");
            while(getchar() != '\n' )
                ;
        }
    }

    for(int i = 1; ; i++)
    {
        printf("Iveskite %d sekos nari: \n", i);

        if(i == 0 && scanf("%d", &seka[i]) && getchar() == '\n')
            ++j;

            else if (scanf("%d", &seka[i]) && getchar() == '\n')
            {
                ind = j;
                ++j;
                if( abs(seka[i] - seka[ind]) < a)
                    break;
            }
        else
        {
            printf("Neteisinga ivestis! Veskite dar karta!\n ");
            while(getchar() != '\n')
                ;
            --i;
        }

        if(size <= i)
        {
           printf("Skaiciu seka daugiausiai gali susidaryti %d nariai!\n ", size);
           break;
        }
    }

    minn = seka[1];
    maxx = seka[1];
    for(int i = 1; i <= j; i++)
    {
        if(seka[i] > maxx)
            maxx = seka[i];

        if(seka[i] < minn)
            minn = seka[i];
    }
    printf("-----------------------------------------------------\n");
    printf("Didziausias sekos narys: %d\n", maxx);
    printf("Maziausias sekos narys: %d\n", minn);

    return 0;
}
