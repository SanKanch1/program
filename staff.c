#include <stdio.h>

struct Staff
{
	int id;
	char name[50];
	char department[50];
	char designation[50];
	float salary;
	int cl;    // Casual Leave
};
 
 int main()
 {
 	int n, i;
 	printf("Enter number of staff members:");
 	scanf("%d", &n);
 	
 	struct Staff staff[n];
 	 
 	 /* Enter staff details */
 	 
 	 for (i=0; i< n; i++)
 	 {
 	 	printf("\n Enter details of staff %d\n",i +1);
 	 	
 	 	printf("Staff ID:");
 	 	scanf("%d", &staff[i].id);
 	 	
 	 	printf("Name: ");
        scanf(" %[^\n]", staff[i].name);

        printf("Department: ");
        scanf(" %[^\n]", staff[i].department);

        printf("Designation: ");
        scanf(" %[^\n]", staff[i] .designation);

        printf("Salary: ");
        scanf("%f", &staff[i].salary);

        printf("Number of Casual Leaves (CL): ");
        scanf("%d", &staff[i].cl);
    }

    /* Display staff details */
    printf("\n\n===== SCHOOL STAFF DETAILS =====\n");

    for (i = 0; i < n; i++)
    {
        printf("\nStaff %d\n", i + 1);
        printf("Staff ID       : %d\n", staff[i].id);
        printf("Name           : %s\n", staff[i].name);
        printf("Department     : %s\n", staff[i].department);
        printf("Designation    : %s\n", staff[i].designation);
        printf("Salary         : %.2f\n", staff[i].salary);
        printf("Casual Leave   : %d days\n", staff[i].cl);
    }

    return 0;

	  
 }
