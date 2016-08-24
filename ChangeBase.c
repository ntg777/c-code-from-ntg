//
// Created by owner on 8/15/2016.
// link to the way i chage the bases
//link http://mathbits.com/MathBits/CompSci/Introduction/tobase10.htm
// link2 http://mathbits.com/MathBits/CompSci/Introduction/frombase10.htm
/**
 * @file ChangeBase.c
 * @author  Natai Ella<natai7797@gmail.com>
 * @version 1.0
 * @date 16 aug 2016
 *
 * @brief programe to chage the base of a number
 *
 * @section LICENSE
 * This program is a free software;
 *
 * @section DESCRIPTION
 * programe to chage the base of a number.
 * Input  : start base, end base and the nuber.
 * Process: chage to base 10 then chage to wanted base
 * Output : imidtly.
 */

#include <stdio.h>
/**
 * @def first 1
 * @brief A macro that represetn the first diget from the number.
 */
#define FIRST 1
/**
 * @def empty 0
 * @brief A macro that sets integer as empty.
 */
#define EMPTY 0
/**
 * @def firstdigit 10
 * @brief A macro that gets the first digit of the number.
 */
#define FIRSTDIGIT 10
/**
 * @def error -1
 * @brief A macro says there is a error with the contenet.
 */
#define ERROR -1
/**
 * @def default 2
 * @brief A macro that sets the bases to 2 incase there was no inpot.
 */
#define DEFUALT 2
/**
 * @def default 1
 * @brief A macro that sets the bases to 2 incase there was no inpot.
 */
#define DEFUALT2 1
/**
 * @brief chage the nuber to base 10.
 * @param number the number to chage
 * @param base the base the number is in
 * @return the number in base 10
 */
long chagetobase10(unsigned int number,unsigned int base)
{
    long finalnumber = EMPTY;
    int digetnumber = FIRST;
    unsigned int singledigit = EMPTY;
    while (number != EMPTY)
    {
        singledigit = number % FIRSTDIGIT; // get the first digit
        if (singledigit >= base)
        {
            return ERROR;
        }
        number /= FIRSTDIGIT; // remove the digit we just took
        finalnumber += singledigit * digetnumber; //change the digit to base 10 and add it
        digetnumber *= base; // next digit
    }
    return finalnumber;
}
/**
 * @def bignumber 99999999999
 * @brief A macro that repraset a namber close to the long long limit.
 */
#define  BIGNUMBER 99999999999
/**
 * @def nextdigit 10
 * @brief A macro that tells us to move 1 digit left.
 */
#define NEXTDIGIT 10
/**
 * @brief chage the number to base to the requsted base. than print it
 * @param number the number to chage
 * @param base the base you want to chage to
 */
void chagefrombase10(int number, unsigned int base)
{
    int tempnumberofzero = EMPTY;
    int numberofzero = EMPTY;
    unsigned long long leftfinalnumber = EMPTY;
    long long digitbase = FIRST;
    unsigned long long rightfinalnumber = EMPTY;// used only when its the number is over 99,999,999
    for (int temp = EMPTY; number != EMPTY; number /= base)
    {
        temp = number % base;
        if (temp != EMPTY)
        {
            leftfinalnumber += temp * digitbase;
            tempnumberofzero = EMPTY;
        }
        else
        {
            tempnumberofzero++;
        }

        digitbase *= NEXTDIGIT;

        if (digitbase > BIGNUMBER)
        {
            rightfinalnumber = leftfinalnumber;
            leftfinalnumber = EMPTY;
            digitbase = FIRST;
            numberofzero = tempnumberofzero;

        }
    }
    if (rightfinalnumber == EMPTY)
    {
        printf("%lld", leftfinalnumber);
    }
    else
    {
        printf("%lld", leftfinalnumber);
        while (numberofzero > EMPTY)
        {   // this is to tell how many '0' are between leftfinalnumber and rightfinalnumber
            printf("0");
            numberofzero--;
        }
        printf("%lld\n", rightfinalnumber);
    }
}
/**
 * @brief gets the requsted numbers to chage than
 * runs the other fanction in order, than print the result
 */
void startChangeBase()
{

    //char sting[100];
    //scanf("%s",sting);
    int startbase = DEFUALT;
    int endbase = DEFUALT;
    int number = DEFUALT2;
    scanf("%d^%d^%d^", &startbase, &endbase, &number);
    //scanf("%d^%d^%d^",startbase,endbase,number);
    number = chagetobase10(number, startbase);
    if (number == ERROR)
    {
        printf("invalid!!\n");
    }
    else
    {
         chagefrombase10(number, endbase);
    }
}
/**
 * @brief The main function. start the chagebase function.
 * @return 0, to tell the system the execution ended without errors.
 */
int main()//int argc, char *argv[])
{
    startChangeBase();
    return 0;
}
