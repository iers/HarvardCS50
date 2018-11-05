/*
Implement, in cash.c at right, a program that first asks the user how much change is owed and then prints the minimum number of coins with which that change can be made.

    Use get_float to get the user’s input and printf to output your answer. Assume that the only coins available are quarters (25¢), dimes (10¢), nickels (5¢), and pennies (1¢).
        We ask that you use get_float so that you can handle dollars and cents, albeit sans dollar sign. In other words, if some customer is owed $9.75 (as in the case where a newspaper costs 25¢ but the customer pays with a $10 bill), assume that your program’s input will be 9.75 and not $9.75 or 975. However, if some customer is owed $9 exactly, assume that your program’s input will be 9.00 or just 9 but, again, not $9 or 900. Of course, by nature of floating-point values, your program will likely work with inputs like 9.0 and 9.000 as well; you need not worry about checking whether the user’s input is “formatted” like money should be.
    You need not try to check whether a user’s input is too large to fit in a float. Using get_float alone will ensure that the user’s input is indeed a floating-point (or integral) value but not that it is non-negative.
    If the user fails to provide a non-negative value, your program should re-prompt the user for a valid amount again and again until the user complies.
    So that we can automate some tests of your code, be sure that your program’s last line of output is only the minimum number of coins possible: an integer followed by \n.
    Beware the inherent imprecision of floating-point values. Recall floats.c from class, wherein, if x is 2, and y is 10, x / y is not precisely two tenths! And so, before making change, you’ll probably want to convert the user’s inputted dollars to cents (i.e., from a float to an int) to avoid tiny errors that might otherwise add up!

    Take care to round your cents to the nearest penny, as with round, which is declared in math.h. For instance, if dollars is a float with the user’s input (e.g., 0.20), then code like

    int coins = round(dollars * 100);

    will safely convert 0.20 (or even 0.200000002980232238769531250) to 20.
*/

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float n;
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennies = 0;

    do
    {
        n = get_float("Amount of change owed: ");
        printf("\n");
    }
    while(n < 0);

    while (n > 0)
    {
        if (n >= 0.25)
        {
            n = n-0.25;
            quarters += 1;
        }
        else if (n >= 0.10)
        {
            n = n-0.10;
            dimes += 1;
        }
        else if (n >= 0.05)
        {
            n = n-0.05;
            nickles += 1;
        }
        else
        {
            n = n-0.01;
            pennies += 1;
        }
    }

    int totalCoins = quarters + dimes + nickles + pennies;
    printf("Total number of coins: %i\n", totalCoins);
    printf("Total number of quarters: %i\n", quarters);
    printf("Total number of dimes: %i\n", dimes);
    printf("Total number of nickles: %i\n", nickles);
    printf("Total number of pennies: %i\n", pennies);

}
