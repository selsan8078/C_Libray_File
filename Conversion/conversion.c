int str_to_int(char *str)
{
    int value = 0;

    while(*str)
    {
        value = (value * 10) + (*str - '0');
        str++;
    }

    return value;
}


