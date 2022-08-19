#include <iostream>

bool match_Left(char x)
{
    std::string dict = "-.@0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < dict.length(); i++)
    {
        if (x == dict[i])
            return true;
    }
    return false;
}

bool match_Right(char x)
{
    std::string dict = "-.!#$%&'*+-/=?^_`{|}~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < dict.length(); i++)
    {
        if (x == dict[i])
            return true;
    }
    return false;
}

bool match_Dot(std::string x)
{
    for (int i = 0; i < x.length(); i++)
    {
        if (x[0] == '.')
        {
            std::cout << "Symbol '.' must not to be First!!!\n";
            return false;
        }
        else if (i > 0)
        {
            if (x[i] == '.' && x[i - 1] == '.')
                return false;
        }
        else if (x[x.length() - 1] == '.')
        {
            std::cout << "Symbol '.' must not to be Last!!!\n";
            return false;
        }
    }
    return true;
}


int main()
{
    std::string email, left, right;
    bool match = true;

    std::cout << "Input E-mail address:\n";
    std::cin >> email;
    std::cout << "-------------------------------------\n";

    if (!match_Dot(email))
    {
        std::cout << "Dot ERROR\n";
        match = false;
    }
    else
    {
        int count = 0;
        for (; count < email.length(); count++)
        {
            if (email[count] == '@')
            {
                left += email[count];
                count++;
                break;
            }
        }
        for (; count < email.length(); count++)
        {
            if (email[count] != '@')
                right += email[count];
            else
            {
                std::cout << "@ ERROR\n";
                match = false;
                break;
            }
        }
        if (match)
        {
            for (int i = 0; i < left.length(); i++)
            {
                if (!match_Left(left[i]))
                {
                    std::cout << "Account Part Symbol ERROR\n";
                    match = false;
                    break;
                }
            }
            if (match)
            {
                for (int j = 0; j < right.length(); j++)
                {
                    if (!match_Right(right[j]))
                    {
                        std::cout << "Domain Part Symbol ERROR\n";
                        match = false;
                        break;
                    }
                }
            }
        }
    }

    if (match)
        std::cout << "Yes.\n";
    else
        std::cout << "No.\n";
}