#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

int main(int argc, char *argv[])
{
    if (argc<2)
    {
        printf("forgot number after ./main or ./a.out");
	exit(1);
    }
    Item *item_list = (Item *)malloc(5 * sizeof(Item));
    add_item(item_list, 5.000000, "19282", "breakfast", "reese's cereal", 0);
    add_item(item_list, 3.950000, "79862", "dairy", "milk", 1);
    add_item(item_list, 1.500000, "73458", "fruit", "banana", 2);
    add_item(item_list, 2.990000, "23476", "meat", "steak", 3);
    add_item(item_list, 6.700000, "09249", "frozen", "ice cream", 4);
    print_items(item_list,5);
    printf("average price of items = %f\n", average_price(item_list, 5));
    int ct = 0;
    char *sku = argv[1];//,sku for the while loop doesnt exist withou it 
    while (ct<5&&strcmp(item_list[ct].sku,sku)!=0)//the other versoion in the assignment would give me a not enough arguments error
    {
	ct++;
        if (ct == 5)
        {
            printf("\n !!!item not found!!!\n");
        }
    }
    if(ct < 5)//without it, it tries to print your item even if sku doesnt exist and crashes my cygwin terminal
    {
        printf("\n !!!Your item!!!\n");
        printf("#######################\n");
	printf("item name = %s\n", item_list[ct].name);
	printf("item sku = %s\n", item_list[ct].sku);
	printf("item category = %s\n", item_list[ct].category);
	printf("item price = %f\n", item_list[ct].price);
    }
    free_items(item_list, 5);
    return 0;
    
}

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].price = price;
    item_list[index].sku = (char *)malloc(strlen(sku) + 1);
    strcpy(item_list[index].sku, sku);
    item_list[index].name = (char *)malloc(strlen(name) + 1);
    strcpy(item_list[index].name, name);
    item_list[index].category = (char *)malloc(strlen(category) + 1);
    strcpy(item_list[index].category, category);
}

void free_items(Item *item_list, int size)
{
    for (int i = 0; i < size; i++)
    {
        free(item_list[i].sku);
	free(item_list[i].name);
	free(item_list[i].category);
    }
    free(item_list);
}

double average_price(Item *item_list, int size)
{
    double average = 0;
    for (int i = 0; i < size; i++)
    {
        average += item_list[i].price;
    }
    average = average / size;
    return average;

}

void print_items(Item *item_list, int size)
{
    for(int i=0;i<size;i++)
    {
        printf("#######################\n");
	printf("item name = %s\n", item_list[i].name);
	printf("item sku = %s\n", item_list[i].sku);
	printf("item category = %s\n", item_list[i].category);
	printf("item price = %f\n", item_list[i].price);
    }
}

