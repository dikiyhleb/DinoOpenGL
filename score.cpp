#include "score.h"

void Score::show()
{
    unsigned int hundred, dozens, units;
    Num1 num1;
    Num2 num2;
    Num3 num3;

    int digit1 = result / 100;        
    int digit2 = (result / 10) % 10;
    int digit3 = result % 10;

    switch (digit1)
    {
    case(0):
        hundred = number0;
        break;
    case(1):
        hundred = number1;
        break;
    case(2):
        hundred = number2;
        break;
    case(3):
        hundred = number3;
        break;
    case(4):
        hundred = number4;
        break;
    case(5):
        hundred = number5;
        break;
    case(6):
        hundred = number6;
        break;
    case(7):
        hundred = number7;
        break;
    case(8):
        hundred = number8;
        break;
    case(9):
        hundred = number9;
        break;
    default:
        break;
    }
    switch (digit2)
    {
    case(0):
        dozens = number0;
        break;
    case(1):
        dozens = number1;
        break;
    case(2):
        dozens = number2;
        break;
    case(3):
        dozens = number3;
        break;
    case(4):
        dozens = number4;
        break;
    case(5):
        dozens = number5;
        break;
    case(6):
        dozens = number6;
        break;
    case(7):
        dozens = number7;
        break;
    case(8):
        dozens = number8;
        break;
    case(9):
        dozens = number9;
        break;
    default:
        break;
    }
    switch (digit3)
    {
    case(0):
        units = number0;
        break;
    case(1):
        units = number1;
        break;
    case(2):
        units = number2;
        break;
    case(3):
        units = number3;
        break;
    case(4):
        units = number4;
        break;
    case(5):
        units = number5;
        break;
    case(6):
        units = number6;
        break;
    case(7):
        units = number7;
        break;
    case(8):
        units = number8;
        break;
    case(9):
        units = number9;
        break;
    default:
        break;
    }

    num3.show(hundred);
    num2.show(dozens);
    num1.show(units);
}