// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
        printf("Your password is valid!\n");
    else
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
}

// Function determines if the password is valid
bool valid(string password)
{
    bool upper = false;
    bool lower = false;
    bool number = false;
    bool symbol = false;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isalnum(password[i]))
        {
            if (islower(password[i]))
                lower = true;
            else if (isupper(password[i]))
                upper = true;
            else
                number = true;
        }
        else if (ispunct(password[i]))
            symbol = true;
    }
    if (lower && upper && number && symbol)
        return true;
    return false;
}
