
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;


/* Function to push an element onto the stack */

void push()
{
    int item;

    if (top == MAX - 1)
    {
        printf(
            "\nStack Overflow! Cannot push more elements.\n"
        );

        return;
    }

    printf(
        "Enter the element to push: "
    );

    scanf(
        "%d",
        &item
    );

    top++;
    stack[top] = item;

    printf(
        "%d pushed onto the stack.\n",
        item
    );
}


/* Function to pop an element from the stack */

void pop()
{
    if (top == -1)
    {
        printf(
            "\nStack Underflow! Stack is empty.\n"
        );

        return;
    }

    printf(
        "Popped element: %d\n",
        stack[top]
    );

    top--;
}


/* Function to check palindrome using stack */

void palindrome()
{
    int num, temp, digit;
    int pstack[MAX];
    int ptop = -1;
    int reverse = 0;

    printf(
        
        "Enter a number to check for palindrome: "
        
    );

    scanf(
        "%d",
        &num
    );

    if (num < 0)
    {
        printf(
            "%d is not a palindrome.\n",
            num
        );

        return;
    }

    temp = num;

    
    /* Push each digit onto the temporary stack */
    

    while (temp != 0)
    {
        digit = temp % 10;

        if (ptop == MAX - 1)
        {
            printf(
                
                "Number has more than %d digits.\n"
                ,
                MAX
            );

            return;
        }

        pstack[++ptop] = digit;

        temp = temp / 10;
    }

    
    /* Pop digits and construct reverse number */
    

    while (ptop != -1)
    {
        digit = pstack[ptop--];

        reverse = reverse * 10 + digit;
    }

    if (num == reverse)
    {
        printf(
            "%d is a palindrome.\n",
            num
        );
    }
    
    else
    {
        printf(
            "%d is not a palindrome.\n",
            num
        );
    }
}


/* Function to demonstrate Overflow and Underflow */

void demonstrate()
{
    int i;

    printf(
        
        "\n--- Demonstrating Underflow ---\n"
        
    );

    /* Make the stack empty */

    top = -1;

    printf(
        
        "Trying to pop from an empty stack...\n"
        
    );

    pop();


    printf(
        
        "\n--- Demonstrating Overflow ---\n"
        
    );

    /* Fill the stack */

    for (i = 0; i < MAX; i++)
    {
        stack[++top] = i + 1;
    }

    printf(
        
        "Stack filled with %d elements.\n"
        ,
        MAX
    );

    printf(
        
        "Trying to push one more element...\n"
        
    );

    push();
}


/* Function to display the stack */

void display()
{
    int i;

    if (top == -1)
    {
        printf(
            "\nStack is empty.\n"
        );

        return;
    }

    printf(
        "\nStack elements are:\n"
    );

    for (i = top; i >= 0; i--)
    {
printf(
            "| %d |\n",
            stack[i]
        );
    }

    printf(
        "-----\n"
    );
}


/* Main function */

int main()
{
    int choice;

    while (1)
    {
        printf(
            
            "\n========== STACK MENU ==========\n"
            
        );

        printf(
            "1. Push an Element\n"
        );

        printf(
            "2. Pop an Element\n"
        );

        printf(
            
            "3. Check Palindrome using Stack\n"
            
        );

        printf(
            
            "4. Demonstrate Overflow and Underflow\n"
            
        );

        printf(
            
            "5. Display Stack Status\n"
            
        );

        printf(
            "6. Exit\n"
        );

        printf(
            
            "================================\n"
            
        );

        printf(
            "Enter your choice: "
        );

        scanf(
            "%d",
            &choice
        );


        switch (choice)
        {
            case 1:

                push();

                break;
                
                 case 2:

                pop();

                break;


            case 3:

                palindrome();

                break;


            case 4:

                demonstrate();

                break;


            case 5:

                display();

                break;


            case 6:

                printf(
                    
                    "\nExiting program...\n"
                    
                );

                exit(0);


            default:

                printf(
                    
                    "\nInvalid choice! Please try again.\n"
                    
                );
        }
    }

    return 0;
}

  

