// test version of mechbook
#include<stdio.h>
#include<math.h>

#include"helpers.h"
#include"motion.h"

void title();

int main()
{
    title();
    printf("---------------SUVAT MODULE---------------");
    _2d_motion();
    return 0;
}

void title()
{
    printf("\n\n------------------------>     \033[1mTHE Mech'BOOK\033[0m     <------------------------\n");
    printf("---------------] A handy tool for mechanical engineers [-----------------\n\n\n\n");
}