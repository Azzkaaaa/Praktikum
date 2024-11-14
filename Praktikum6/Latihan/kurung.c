#include <stdio.h>
#include "boolean.h"
#include "stack.h"

int main()
{
    int N, i;
    char ch;
    char temp;
    // Stack declaration here...
    Stack stack;
    CreateEmpty(&stack);

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf(" %c", &ch);
        if (i == 0 && (ch == ']' || ch == '}' || ch == ')')){
            printf("Invalid\n");
            return 0;
        }
        if (ch == '[' || ch == '{' || ch == '('){
            Push(&stack, ch);
        }else {
            if (IsEmpty(stack)){
                printf("Invalid\n");
                return 0;
            }
            if (ch == ']' && InfoTop(stack) == '['){
                Pop(&stack, &temp);
            }else if (ch == '}' && InfoTop(stack) == '{'){
                Pop(&stack, &temp);
            }else if (ch == ')' && InfoTop(stack) == '('){
                Pop(&stack, &temp);
            }else {
                printf("Invalid\n");
                return 0;
            }
        }
    }
    if (IsEmpty(stack)){
        printf("Valid\n");
    }else {
        printf("Invalid\n");
    }
    return 0;
}