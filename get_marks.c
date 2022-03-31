char* removeLeadingSpaces(char* str);//removes leading spaces

char* firstMark(char* str);//gets first word

char* lastMark(char* str);//gets lst word

int main()
{
    // Given string
    char str[] = "        12 if drr5rj then 5";
    char* ptr;

    // Function call
    ptr = removeLeadingSpaces(str);
    printf("\n%s\n", ptr);

    ptr = firstMark(ptr);
    printf("\n%s\n", ptr);

    ptr = lastMark(str);
    printf("\n%s\n", ptr);

    return 0;
}

char* removeLeadingSpaces(char* str)
{
    static char str1[99];
    int count = 0, j, k;

    while (str[count] == ' ') {
        count++;
    }

    for (j = count, k = 0; str[j] != '\0'; j++, k++) {
        str1[k] = str[j];
    }
    str1[k] = '\0';

    return str1;
}

char* firstMark(char* str)
{
    static char str1[99];
    int count = 0, j, k;

    while (str[count] != ' ') {
        count++;
    }

    for (j = 0, k = 0; j<=count; j++, k++) {
        str1[k] = str[j];
    }
    str1[k] = '\0';

    return str1;
}


char* lastMark(char* str)
{
    static char str1[99];
    int count = 0, count2, j, k;
    while (str[count] != '\0') {
        count++;
    }
    count2 = count;

    while (str[count2] != ' ') {
        count2--;
    }

    int n=count2+1;
    for (j = n, k = 0; j<count; j++, k++) {
        str1[k] = str[j];
    }
    str1[k] = '\0';

    return str1;
}
