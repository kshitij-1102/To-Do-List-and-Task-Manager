
#include <stdio.h>

// Function declarations
void addTask();
void viewTasks();
void searchTask();
void completeTask();
void deleteTask();
void updateTask();
void pendingTasks();
void loadTasks();

int main()
{
    int choice;

    loadTasks();

    printf("\n================================");
    printf("\n     TO-DO LIST TASK MANAGER");
    printf("\n================================\n");

    do
    {
        printf("\n1. Add New Task");
        printf("\n2. View All Tasks");
        printf("\n3. Search Task");
        printf("\n4. Mark Task as Completed");
        printf("\n5. Delete Task");
        printf("\n6. Update Task");
        printf("\n7. View Pending Tasks");
        printf("\n8. Exit");

        printf("\n\nEnter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                viewTasks();
                break;

            case 3:
                searchTask();
                break;

            case 4:
                completeTask();
                break;

            case 5:
                deleteTask();
                break;

            case 6:
                updateTask();
                break;

            case 7:
                pendingTasks();
                break;

            case 8:
                printf("\nThank You for Using Task Manager!\n");
                break;

            default:
                printf("\nInvalid Choice! Try Again.\n");
        }

    } while(choice != 8);

    return 0;
}
