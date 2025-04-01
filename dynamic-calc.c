#include <stdlib.h>
#include <stdio.h>

int main() {
    //malloc
    int *pNumbers = (int *) malloc(sizeof(int));
    char *pOp = (char *) malloc(sizeof(char));
    int count = 0;
    float result;
    
    if (pNumbers == NULL || pOp == NULL) {
        printf("Memory allocation failed bruh\n");
        return 1;
    }

    printf("Enter an operator: \n");
    scanf("%c", pOp);
    while(getchar() != '\n');
    printf("Enter number of numbers: \n");
    scanf("%d", &count);
    while(getchar() != '\n'); // removes newline char

    pNumbers = (int * ) realloc(pNumbers, count * sizeof(int));

    for (int i = 0; i < count; i++) {
        printf("Enter number %d: \n", i + 1);
        scanf("%d", &pNumbers[i]);
        while(getchar() != '\n');
    }

    result = (float) pNumbers[0];

    switch (*pOp)
    {
    case '/':
        for (int i = 1; i < count; i++) {
            result = (float) result / (float) pNumbers[i];
        }
        printf("Result: %f", result);
        break;
    
    case '*':
        for (int i = 1; i < count; i++) {
            result = (float) result * (float) pNumbers[i];
        }
        printf("Result: %f", result);
        break;

    case '+':
        for (int i = 1; i < count; i++) {
            result = (float) result + (float) pNumbers[i];
        }
        printf("Result: %f", result);
        break;

    case '-':
        for (int i = 1; i < count; i++) {
            result = (float) result - (float) pNumbers[i];
        }
        printf("Result: %f", result);
        break;

    default:
        printf("Invalid operator\n");
        break;
    }
    printf("\n");

    // free
    free(pNumbers);
    free(pOp);
    
    return 0;
}