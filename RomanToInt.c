int get_char_val(char c, char next)
{
    if (c == 'I' && next == 'V') return 4;
    if (c == 'I' && next == 'X') return 9;
    if (c == 'X' && next == 'L') return 40;
    if (c == 'X' && next == 'C') return 90;
    if (c == 'C' && next == 'D') return 400;
    if (c == 'C' && next == 'M') return 900;

    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;

    return 0;
}

int romanToInt(char* s)
{
    int res = 0;
    int i = 0;

    while (s[i])
    {
        if (s[i + 1] && get_char_val(s[i], s[i + 1]) > get_char_val(s[i], 0))
        {
            res += get_char_val(s[i], s[i + 1]);
            i += 2;
        }
        else
        {
            res += get_char_val(s[i], 0);
            i++;
        }
    }
    return res;
}
