int cmpStr(char str1[50], char str2[50])
{
    int i = 0, isEqual = 1;
    while (str2[i] != '\0' && str1[i] != '\n' && isEqual == 1)
    {
        if (str1[i] != str2[i])
        {
            isEqual = 0;
        }
        i++;
    }
    return isEqual;
}