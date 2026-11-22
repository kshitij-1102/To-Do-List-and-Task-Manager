
#include <stdio.h>
#include <stdlib.h>
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

// Load tasks from file
void loadTasks()
{
    FILE *fp;
    char temp[100];

    fp = fopen("tasks.txt", "r");

    if(fp == NULL)
        return;

    while(count < MAX)
    {
        if(fgets(temp, sizeof(temp), fp) == NULL)
            break;

        tasks[count].id = atoi(temp);

        if(fgets(tasks[count].name, 50, fp) == NULL)
            break;

        if(fgets(tasks[count].description, 100, fp) == NULL)
            break;

        if(fgets(tasks[count].date, 20, fp) == NULL)
            break;

        if(fgets(temp, sizeof(temp), fp) == NULL)
            break;

        tasks[count].name[strcspn(tasks[count].name, "\n")] = '\0';
        tasks[count].description[strcspn(tasks[count].description, "\n")] = '\0';
        tasks[count].date[strcspn(tasks[count].date, "\n")] = '\0';

        tasks[count].status = atoi(temp);

        count++;
    }

    fclose(fp);
}

// Save tasks into file
void saveTasks()
{
    FILE *fp;
    int i;

    fp = fopen("tasks.txt", "w");

    if(fp == NULL)
    {
        printf("\nUnable to Open File!\n");
        return;
    }

    for(i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n", tasks[i].id);
        fprintf(fp, "%s\n", tasks[i].name);
        fprintf(fp, "%s\n", tasks[i].description);
        fprintf(fp, "%s\n", tasks[i].date);
        fprintf(fp, "%d\n", tasks[i].status);
    }

    fclose(fp);
}

// Display pending tasks
void pendingTasks()
{
    int i, found = 0;

    printf("\n======= PENDING TASKS =======\n");

    for(i = 0; i < count; i++)
    {
        if(tasks[i].status == 0)
        {
            printf("\nTask ID: %d", tasks[i].id);
            printf("\nTask Name: %s", tasks[i].name);
            printf("\nDue Date: %s\n", tasks[i].date);

            found = 1;
        }
    }

    if(found == 0)
        printf("\nNo Pending Tasks!\n");
}
