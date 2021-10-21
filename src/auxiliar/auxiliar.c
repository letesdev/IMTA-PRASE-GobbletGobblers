#include <stdio.h>

int check_input(int min, int max, char *question){
    int input = 0;
    while (input < min || input > max)
    {
        printf("%s", question);
        scanf("%d", &input);
    }
    return input;
}
