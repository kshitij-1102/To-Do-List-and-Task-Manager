
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

extern struct Task tasks[MAX];
extern int count;

int findTask(int id);
void saveTasks();
void readLine(char str[], int size);

// Mark task as completed
void completeTask()
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
        tasks[pos].status = 1;

        saveTasks();

        printf("\nTask Completed Successfully!\n");
    }
}

// Delete task
void deleteTask()
{
    int id, pos, i;

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
        for(i = pos; i < count - 1; i++)
        {
            tasks[i] = tasks[i + 1];
        }

        count--;

        saveTasks();

        printf("\nTask Deleted Successfully!\n");
    }
}

// Update task
void updateTask()
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
        printf("\nEnter New Task Name: ");
        readLine(tasks[pos].name, 50);

        printf("Enter New Description: ");
        readLine(tasks[pos].description, 100);

        printf("Enter New Due Date: ");
        readLine(tasks[pos].date, 20);

        saveTasks();

        printf("\nTask Updated Successfully!\n");
    }
}
