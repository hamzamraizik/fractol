#include <stdio.h>
#include <ctype.h>

double atof(const char *str)
{
    double result = 0.0;
    int sign = 1;
    int decimal = 0;
    int power = 1;

    // Skip leading whitespace
    while (isspace(*str)) {
        str++;
    }

    // Handle optional sign
    if (*str == '+' || *str == '-') {
        sign = (*str++ == '-') ? -1 : 1;
    }

    // Process digits before decimal point
    while (isdigit(*str)) {
        result = result * 10 + (*str++ - '0');
    }

    // Process digits after decimal point
    if (*str == '.') {
        str++;
        while (isdigit(*str)) {
            result = result * 10 + (*str++ - '0');
            power *= 10;
        }
        decimal = 1;
    }

    // Adjust result based on sign and decimal point
    result *= sign;
    if (decimal) {
        result /= power;
    }

    return result;
}