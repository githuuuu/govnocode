#include <stdio.h>
#include <string.h>

#define FILENAME "test.txt"
#define NEWFILE "result.txt"
#define MAX 256
/*char* removeLeadingSpaces(char *source, char *target)    //removes leading spaces//
{
    int count = 0, j, k;
    while (source[count] == ' ') {
        count++;
    }

    for (j = count, k = 0; source[j] != '\0'; j++, k++){
        target[k] = source[j];
    }
    target[k] = '\0';
    return 0;
}*/

char* removeLeadingSpaces(char* str)    //removes leading spaces//
{
    static char str1[99];
    int count = 0, j, k;
    while (str[count] == ' ') {
        count++;
    }

    for (j = count, k = 0; str[j] != '\0'; j++, k++){
        str1[k] = str[j];
    }
    str1[k] = '\0';
    return str1;
}
  int main()
  {
        FILE *source, *target;          //original file, edited file
        int lineNumber, linectr = 0;    //number of line to be replaced, number of line to be checked for replacement
        char str[MAX];                  //stores line to be rewritten or replaced
        char newLine[MAX];              //stores replacement line
        char* ptr;

        source = fopen(FILENAME, "r");
        target = fopen(NEWFILE, "w");
        if(source==NULL || target == NULL) {
            printf("File \"%s\" does not exist!!!\n",FILENAME);
            return -1;
        }
		printf("\n\n Replace a specific line in a text file with a new text :\n");

        // get the new line from the user
        printf(" Input the content of the new line : ");
        fgets(newLine, MAX, stdin);
        // get the line number to replace the specific line
        printf(" Input the line no you want to replace : ");
        scanf("%d", &lineNumber);
        lineNumber++;                                      //count starts from 0

        while (feof(source)==0)
        {
            strcpy(str, "\0");
            fgets(str, MAX, source);                       //stores line from file
            if (feof(source)==0)
            {
                linectr++;                                 //count starts from 0
                if (linectr != lineNumber)                 //if it isn't a line to be replaced
                    {
                        ptr = removeLeadingSpaces(str);
                        fprintf(target, "%s", ptr);       //rewrites line with the same text
                    }
                    else                                   //if it is a line to be replaced
                    {
                        fprintf(target, "%s", newLine);    //changes text
                    }
            }
        }
        fclose(source);
        fclose(target);
        printf(" Replacement did successfully..!! \n");
        return 0;
  }
