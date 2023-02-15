#include <stdio.h>
#include <stdlib.h>

int smallLetters(char *pass) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] > 96 && pass[i] < 123)    //searching for small letters using their number in the ascii table
        {
            return 1;
        }
    }
    return 0;
}

int capitalLetters(char *pass) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] > 64 && pass[i] < 91)     //searching for capital letters using their number in the ascii table
        {
            return 1;
        }
    }
    return 0;
}

int digits(char *pass) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if (pass[i] > 47 && pass[i] < 58)     //searching for digits using their number in the ascii table
        {
            return 1;
        }
    }
    return 0;
}

int specialSymbols(char *pass) {
    for (int i = 0; pass[i] != '\0'; i++) {
        if ((pass[i] > 31 && pass[i] < 48) ||
            (pass[i] > 57 && pass[i] < 65) ||
            (pass[i] > 90 && pass[i] < 97) ||
            (pass[i] > 122 && pass[i] < 127))   //searching for special characters using their number in the ascii table
        {
            return 1;
        }
    }
    return 0;
}

int firstCheck(char *pass) {
    if (capitalLetters(pass) + smallLetters(pass) == 2)   //comparing
    {
        return 1;
    }
    return 0;
}

int secondCheck(char *pass) {
    if (capitalLetters(pass) + smallLetters(pass) +
        digits(pass) + specialSymbols(pass) == 4)    //comparing
    {
        return 1;
    }
    return 0;
}

int thirdCheck(char *pass, int PARAM) {
    int count = 1;

    for (int i = 0; pass[i] != '\0'; i++)      //searching if password does not contain the same sequence of characters
    {
        if (pass[i - 1] == pass[i]) {
            count++;
        }
    }
    if (count >= PARAM) {
        return 0;
    }

    return 1;
}

int fourthCheck(char *pass, int PARAM) {
    char subArr[PARAM + 1];
    char tempSubArr[PARAM + 1];
    int size = 0;
    int length = 0;
    int count = 0;

    while (pass[size] != '\0') {
        size++;
    }

    for (int i = 0; i < size - PARAM; i++)      //getting substrings
    {
        int subLength = length;

        for (int j = subLength; j < PARAM + subLength; j++) {
            subArr[j - subLength] = pass[j];
        }

        for (int q = 0; q <= size - PARAM; q++)    //getting other substrings
        {
            if (q == length) {
                q++;
            }
            for (int u = q; u < PARAM + q; u++) {
                tempSubArr[u - q] = pass[u];
            }
            for (int b = 0; b < PARAM; b++)     //checking if password does not contain two identical substrings
            {
                if (subArr[b] == tempSubArr[b]) {
                    count++;
                    if (count == PARAM) {
                        return 0;
                    }
                    continue;
                } else {
                    break;
                }
            }
        }
        length++;
    }

    return 1;
}

void securityLevel(char *pass, int PARAM, int LEVEL) {
    int level[4] = {firstCheck(pass), secondCheck(pass), thirdCheck(pass, PARAM),
                    fourthCheck(pass, PARAM)};  //creating an array with values of four security levels

    for (int i = 0; i < LEVEL; i++)       //creating a loop to check values
    {
        if (level[i])        //if the function returns a value of 1 then success, if 0 fail
        {
            printf("\nSecurity level %d: success", i + 1);
        } else {
            printf("\nSecurity level %d: fail", i + 1);
        }
    }
}

int statistic(char *pass, int argc, char **argv, int *uniqueCounter, int *minLength,
              float *averageLength, int *division, int *lenght) {
    (void) argc;

    char stat[] = "--stats";
    int statCounter = 0;

    for (int i = 0; argv[3][i] != '\0'; i++)     //third argument check
    {
        if (argv[3][i] == stat[i]) {
            statCounter++;
        }
    }
    if (statCounter == 7) {
        int tempLenght = 0;
        float subLenght = 0;

        printf("\n\nStatistic: ");

        for (int i = 0; pass[i] != '\0'; i++)    //checking an array with passwords for a unique characters
        {
            int matchFound = 0;
            for (int j = 0; pass[j] != '\0'; j++) {
                if (pass[i] == pass[j] && i != j) {
                    matchFound = 1;
                }
            }
            if (matchFound == 0) {
                (*uniqueCounter)++;
            }
        }
        printf("\nUnique characters: %d", (*uniqueCounter) - 1);

        for (int i = 0; pass[i] != '\0'; i++)       //counting password length
        {
            tempLenght++;
        }
        if (tempLenght < *minLength)         //checking which password has the shortest length
        {
            *minLength = tempLenght;
        }
        printf("\nMinimum length: %d", (*minLength) - 1);

        for (int i = 0; pass[i] != '\0'; i++)        //calculating the average password length
        {
            (*lenght)++;
        }
        (*division)++;
        subLenght = *lenght;
        *averageLength = subLenght / *division;
        printf("\nAverage length: %.1f", (*averageLength) - 1);

        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char **argv) {
    int LEVEL = 0;
    int PARAM = 0;

    char *a = argv[1];
    LEVEL = atoi(a);
    char *b = argv[2];
    PARAM = atoi(b);

    if (LEVEL < 1 || LEVEL > 4 || PARAM < 1)  //first and second argument check
    {
        return 0;
    }

    char pass[1024];

    int uniqueCounter = 0;      //variable for finding unique characters

    int minLength = 2048;      //variable for finding the minimum length

    float averageLength = 0;      //variables for finding the average length
    int division = 0;
    int lenght = 0;

    while (1) {
        printf("\n");

        fgets(pass, sizeof pass, stdin);    //checking for input from the command prompt or file
        if (!feof(stdin)) {
            printf("\n%s", pass);

            securityLevel(pass, PARAM, LEVEL);

            statistic(pass, argc, argv, &uniqueCounter, &minLength,
                      &averageLength, &division, &lenght);
        } else {
            return 0;
        }
    }
}
