#include<stdio.h>
#include<conio.h>
#include"../table/8051.c"
#define TRUE 1 
#define FALSE 0 
#define bool u_int8


int dec(char *);                /* function convert hex digit to integer */
void sort(int *,int );          /* Sorting Function */


int dec(char *name)
{
    int counter = 0;

}

/* Sorting Function */
void sort(int *p,int number)
{
    int count = 0,temp;
    register int i,j;

    for (i=0; i<number; i++)
    {
        for (j=count; j<number; j++)
        {
            if (*(p+count) > *(p+j+1))
            {
                // swap variables 
                temp            = *(p+count);
                *(p+count)      = *(p+j+1);
                *(p+j+1)        = temp;
            }
        }
    }
}