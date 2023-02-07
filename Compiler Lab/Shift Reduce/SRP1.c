

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char productions[10][20], input[20], stack[20];
int input_ptr, stack_top, no_of_productions;

void main()
{
    input_ptr = 0;
    stack_top = -1;

    printf("Enter no. of productions: ");
    scanf("%d", &no_of_productions);
    printf("Enter the productions:\n");
    for (int i = 0; i < no_of_productions; i++)
        scanf("%s", productions[i]);
    printf("Enter the input string: ");
    scanf("%s", input);
    printf("%-20s%-20s%-20s\n", "Stack", "Input", "Action");
    int shift, reduce;
    do
    {
        shift = 0;
        reduce = 1;
        if (stack[0] == productions[0][0] && input[strlen(input) - 1] == ' ')
        {
            printf("String accepted.\n");
            exit(0);
        }

        int i;
        for (i = 0; i < no_of_productions; i++)
        {
            reduce = 1;
            for (int j = stack_top, k = strlen(productions[i]) - 1; j >= 0, k >= 2; j--, k--)
            {
                if (stack[j] != productions[i][k])
                    reduce = 0;
            }

            if (reduce == 1)
                break;
        }

        if (reduce == 1)
        {
            int j, k;
            for (j = stack_top, k = strlen(productions[i]) - 1; j >= 0, k >= 2; j--, k--)
                ;
            stack[j + 1] = productions[i][0];
            stack[j + 2] = '\0';
            stack_top -= strlen(productions[i]) - 2 - 1;

            printf("%-20s%-20sReduce to %s\n", stack, input, productions[i]);
        }
        else
        {
            if (input[input_ptr] != '\0')
            {
                shift = 1;
                stack_top++;
                stack[stack_top] = input[input_ptr];
                stack[stack_top + 1] = '\0';
                input[input_ptr] = ' ';
                input_ptr++;
                printf("%-20s%-20s%-20s\n", stack, input, "Shift");
            }
        }
    } while (shift == 1 || reduce == 1);

    printf("String rejected.\n");
}
