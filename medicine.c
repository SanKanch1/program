#include <stdio.h>
#include <string.h>

struct Medicine
{
    char name[50];
    char time[20];
};

int main()
{
    int n, i;

    printf("Enter number of medicines: ");
    scanf("%d", &n);

    struct Medicine medicine[n];

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Medicine %d\n", i + 1);

        printf("Medicine Name: ");
        scanf(" %[^\n]", medicine[i].name);

        printf("Time to take medicine (e.g. 8:00 AM): ");
        scanf(" %[^\n]", medicine[i].time);
    }

    printf("\n===== MEDICINE SCHEDULE =====\n");

    for (i = 0; i < n; i++)
    {
        printf("\nMedicine : %s", medicine[i].name);
        printf("\nTake at : %s\n", medicine[i].time);
    }

    return 0;
}

