
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Task
{
    int id;
    char name[50];
    char description[100];
    char date[20];
    int status;
};

struct Task tasks[MAX];
int count = 0;

// Function to read string
void readLine(char str[], int size)
{
    fgets(str, size, stdin);
    str[strcspn(str, "\n")] = '\0';
}

// Find task using ID
int findTask(int id)
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(tasks[i].id == id)
            return i;
    }

    return -1;
}

// Add new task
void addTask()
{
    int i, newId = 1;

    if(count >= MAX)
    {
        printf("\nTask Limit Reached!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        if(tasks[i].id >= newId)
            newId = tasks[i].id + 1;
    }

    tasks[count].id = newId;

    printf("\nEnter Task Name: ");
    readLine(tasks[count].name, 50);

    printf("Enter Description: ");
    readLine(tasks[count].description, 100);

    printf("Enter Due Date (DD-MM-YYYY): ");
    readLine(tasks[count].date, 20);

    tasks[count].status = 0;

    count++;

    saveTasks();

    printf("\nTask Added Successfully!\n");
}

// Display all tasks
void viewTasks()
{
    int i;

    if(count == 0)
    {
        printf("\nNo Tasks Available!\n");
        return;
    }

    printf("\n========== ALL TASKS ==========\n");

    for(i = 0; i < count; i++)
    {
        printf("\nTask ID: %d", tasks[i].id);
        printf("\nTask Name: %s", tasks[i].name);
        printf("\nDescription: %s", tasks[i].description);
        printf("\nDue Date: %s", tasks[i].date);

        if(tasks[i].status == 0)
            printf("\nStatus: Pending\n");
        else
            printf("\nStatus: Completed\n");

        printf("-----------------------------\n");
    }
}

// Search task
void searchTask()
{
    int id, pos;

    printf("\nEnter Task ID: ");
    scanf("%d", &id);
    getchar();

    pos = findTask(id);

    if(pos == -1)
    {
        printf("\nTask Not Found!\n");
    }
    else
    {
        printf("\nTask Found!\n");

        printf("\nTask ID: %d", tasks[pos].id);
        printf("\nTask Name: %s", tasks[pos].name);
        printf("\nDescription: %s", tasks[pos].description);
        printf("\nDue Date: %s", tasks[pos].date);

        if(tasks[pos].status == 0)
            printf("\nStatus: Pending\n");
        else
            printf("\nStatus: Completed\n");
    }
}
