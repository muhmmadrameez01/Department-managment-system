#include <stdio.h>
#include <string.h>
int main()
{
    int k, p, ch;
    printf("Enter no of shelves: ");
    scanf("%d", &k);
    printf("Enter no of positions on each shelf: ");
    scanf("%d", &p);
    char items[k][p][100];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < p; j++)
        {
            strcpy(items[i][j], "0");
        }
    }
    while (1)
    {
        printf("n****MENU****n");
        printf("Press 1 for inserting an itemn");
        printf("Press 2 for Displaying all itemsn");
        printf("Press 3 to remove item from particular position in a given shelfn");
        printf("Press 4 to Remove all the item from a given shelfn");
        printf("Press 5 to display the total number of the items in the specified shelfn");
        printf("Press 6 to display the total number of items in all the shelvesn");
        printf("Press 7 to find item in the store and display the shelf number and its position if it existsn");
        printf("Press 8 to Update the item at given positionn");
        printf("Press 9 to Check if the shelf is emptyn");
        printf("Press 10 to Check if the shelf is fulln");
        printf("Press -1 to exitn");
        scanf("%d", &ch);
        if (ch == 1)
        {
            int no, pos;
            char item[100];
            printf("Enter the shelf number to insert the item: ");
            scanf("%d", &no);
            printf("Enter the position on the shelf %d to insert the item: ", no);
            scanf("%d", &pos);
            printf("Enter the item:");
            scanf("%s", item);
            if(strcmp(items[no - 1][pos - 1],"0")==0){
            strcpy(items[no - 1][pos - 1], item);
            printf("Successfully inserted");
            }
            else printf("Insertion unsuccessfull. The position is already filled");
        }
        else if (ch == 2)
        {
            int no;
            printf("Enter the shelf number to see the items: ");
            scanf("%d", &no);
            for (int j = 0; j < p; j++)
            {
                if (items[no - 1][j] != "0")
                    printf("%sn", items[no - 1][j]);
            }
        }
        else if (ch == 3)
        {
            int no, pos;
            printf("Enter the shelf number to remove the item: ");
            scanf("%d", &no);
            printf("Enter the position on the shelf %d  to remove particular item", no);
            scanf("%d", &pos);
            strcpy(items[no - 1][pos - 1], "0");
            printf("Removed successfully");
        }
        else if (ch == 4)
        {
            int no;
            printf("Enter the shelf number to remove all the items in the given shelf: ");
            scanf("%d", &no);
            for (int j = 0; j < p; j++)
                strcpy(items[no - 1][j], "0");
            printf("Removed successfully");
        }
        else if (ch == 5)
        {
            int no, count = 0;
            printf("Enter the shelf number to count the item: ");
            scanf("%d", &no);
            for (int j = 0; j < p; j++)
            {
                if (strcmp(items[no - 1][j], "0") != 0)
                    count++;
            }
            printf("Number of items in the shelf%d = %d", no, count);
        }
        else if (ch == 6)
        {
            int count = 0;
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    if (strcmp(items[i][j], "0") != 0)
                        count++;
                }
            }
            printf("Total number of items in all the shelves = %dn", count);
        }
        else if (ch == 7)
        {
            char item[100];
            int shelf_no = -1, pos = -1;
            printf("Enter item to find the shelf number and it's position: ");
            scanf("%s", item);
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < p; j++)
                {
                    if (strcmp(items[i][j], item) == 0)
                    {
                        shelf_no = i + 1;
                        pos = j + 1;
                        break;
                    }
                }
            }
            if (shelf_no == -1 && pos == -1)
            {
                printf("Item not exists");
            }
            else
            {
                printf("%s present on shelf%d at position %d", item, shelf_no, pos);
            }
        }
        else if (ch == 8)
        {
            int no, pos;
            char item[100];
            printf("Enter the shelf number to update the item: ");
            scanf("%d", &no);
            printf("Enter the position on the shelf %d  to update particular item:", no);
            scanf("%d", &pos);
            printf("Enter the item to update:");
            scanf("%s", item);
            strcpy(items[no - 1][pos - 1], item);
            printf("Updated successfully");
        }
        else if (ch == 9)
        {
            int no, flag = 0;
            printf("Enter the shelf number to check if the shelf is empty: ");
            scanf("%d", &no);
            for (int j = 0; j < p; j++)
            {
              if (strcmp(items[no - 1][j],"0")!= 0) 
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
            {
                printf("shelf %d is not empty", no);
            }
            else
            {
                printf("shelf %d is empty", no);
            }
        }
        else if (ch == 10)
        {
            int no;
            int count=0;
            printf("Enter the shelf number to check if the shelf is full: ");
            scanf("%d", &no);
            for (int j = 0; j < p; j++)
            {
                if (strcmp(items[no - 1][j],"0")!=0)
                    count++;
            }
            if (count==p)
            {
                printf("shelf %d is full", no);
            }
            else
            {
                printf("shelf %d is not full", no);
            }
        }
        else if (ch == -1)
        {
            break;
        }
        printf("n------------------------------n");
    }
}
