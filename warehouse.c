#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_TEXT 50

typedef struct {
    char itemNumber[MAX_TEXT];
    char name[MAX_TEXT];
    int quantity;
} Item;

int itemNumberExists(Item items[], int count, const char itemNumber[]) {
    //TODO: loop through items
    //TODO: compare itemNumber with each existing item number
    //TODO: return 1 if found
    //TODO: return 0 if not found
    
    //for (const char item : items)
  //  {
        //compware itemNumber with existing itemNumber
    //    if (strcmp(items[count].itemNumber, itemNumber))
    //    {
           //item found
   //         return 1;
  //      } else
  //      {
            //item not found
  //          return 0;
 //       }
  ///  }
  //loop trough items and compare existing items (refactored)
        for (int i = 0; i < count; i++) {
            if (strcmp(items[i].itemNumber, itemNumber) == 0) {
                return 1;
            }
        }
        return 0;
}

int addItem(Item items[], int *count, const char itemNumber[], const char name[], int quantity)
{
    // TODO: check if warehouse is full

    // TODO: check if item number already exists

    // TODO: copy itemNumber and name into the array

    // TODO: set quantity

    // TODO: increase count

    // TODO: return success
    
    if (*count >= 100)
    {
        printf("WAREHOUSE_FULL");
        return -1;
    }
    
    //check if 
    if (*count < 100)
    {
        if (itemNumberExists(items, *count, itemNumber))
        {
            printf("ITEM NUMBER EXISTS.");
            return 0;   
        } else
        {
            // copy itemNumber
            strcpy(items[*count].itemNumber, itemNumber);

            // copy name 
            strcpy(items[*count].name, name);
                
            // set quantity (doesn't work with copy)
            //strcpy(items[*count].quantity, quantity);
            //set quantity
            items[*count].quantity = quantity;
                
            //increase count
            (*count)++;
            
            //success
            return 0;
        }
    }
}


void printItems(Item items[], int count) {
    // TODO: print all items
    for (int i = 0; i < count; i++)
    {
        printf("%s %s %d\n", items[i].itemNumber, items[i].name, items[i].quantity);
    }
}

int main() {
    Item warehouse[MAX_ITEMS];
    int count = 0;

    addItem(warehouse, &count, "A100", "Hammer", 20);
    addItem(warehouse, &count, "B200", "Nails", 500);

    if (addItem(warehouse, &count, "A100", "Screwdriver", 15) == 0) {
        printf("INVALID_ITEMNUMBER\n");
    }

    printItems(warehouse, count);

    return 0;
}
        