// contains all the helper functions, ie,
//funcn that the main and other func use to simplify itself.

#include<stdio.h>
#include<ctype.h>
#include<stdint.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<math.h>

#include"helpers.h"

//get_int func to get int and filter non valid input
int get_int(void) {
    int value, rc;
    int c;  // note: int is required to properly catch EOF
    do {
        printf("Please enter an integer: ");
        rc = scanf("%d", &value);
        if (rc != 1) {
            // remove invalid characters until end of line
            do {
                c = getchar();
            } while (c != '\n' && c != EOF);
            printf("Invalid input. Try again.\n");
        }
    } while (rc != 1);
    return value;
}

//TEST same func as get_int but for double data type.
double get_dbl(void){
    char input[100];
    char *endptr;
    double value;

    while (true)
    {
        if(fgets(input, sizeof(input), stdin) != NULL)
        {
            //newline gets removed
            input[strcspn(input, "\n")] = '\0';
            //convert to dbl
            value = strtod(input, &endptr);
            if(endptr != input && *endptr == '\0'){
                return value;
            }
            else{
                printf("Invalid input. Try again.\n");
            }
        }
    }
    
}

// func to get bool for y/n questions regarding known values.
bool get_bool(void)
{
    char input[10];
    while(true)
    {
        printf("Answer with (y/n).\n--> ");
        if (fgets(input, sizeof(input), stdin) != NULL)
        {
            input[strcspn(input, "\n")] = '\0';
            char c = tolower(input[0]);
            if (c == 'y'){
                return true;
            }
            else if (c == 'n'){
                return false;
            }
        }
        printf("Invalid input. ");
    }
}

//function to quit from anywhere in the program when called
void quit(void){
    printf("\nquitting.....");
    exit(0);
}

//function to handle insufficient or incorrect data
void no_data(void){
    printf("\n-->Insufficient/Incorrect data :(");
    printf("\n-->going back to main menu.....\n\n");
}





