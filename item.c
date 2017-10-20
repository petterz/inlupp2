#include <stdlib.h>
#include <stdio.h>
#include "item.h"
#include "shelfs.h"
#include "list.h"
#include "common.h"
#include "tree.h"
#include "string.h"

#define BUFFERSIZE 100;



/* Skapar en item med givna egenskaper
 * */
item_t *new_item(char *name, char *desc, int price, list_t *shelf_list) {
    item_t *item = (item_t *)malloc(sizeof(item_t));
    item -> name = name;
    item -> description = desc;
    item -> price = price;
    item -> shelf_list = shelf_list;
    return item;
}

/* Tar bort varan och dess eggenskaper
 * */
void delete_item(item_t *item) {
    bool delete =false;
    free(item->name);
    if (item->shelf_list->free!=NULL)
      delete = true;
    list_delete(item -> shelf_list, delete);
    free(item);
}
/* Returnerar en kopia av varan.
 * */
item_t *copy_item(item_t *item) {
    return new_item(item -> name, item -> description, item -> price, item -> shelf_list);
}


/* Returnerar en pekare till namnet 
 * */
char *get_name(item_t *item) {
    return item -> name;
}
/* returns the string, for the description
 * */
char *get_description(item_t *item) {
    return item -> description;
}
/* returnerar priset
 * */
int get_price(item_t *item) {
    return item -> price;
}


/*
 * */
void set_name(item_t *item, char *name) {
    free(item -> name);
    item -> name = name; 
}
/* Skapar en ny beskrivning
 */
void set_description(item_t *item, char *desc) {
    free(item -> description);
    item -> description = desc;
}
/* Bestämmer nytt pris
 * */
void set_price(item_t *item, int price) {
    item -> price = price;
}
bool shelf_exist(item_t *item, char *name) {
  elem_t shelf_name = {.p = name};
 int retur = list_contains(item -> shelf_list, shelf_name);
 if (retur==-1)
   return false;
 else
   return true;
}

list_t *get_shelfs_item(item_t *item)
{
  int len = list_length(item->shelf_list);
  list_t **shelf = calloc(len, sizeof(shelf_t));
  for(int i = 0; i<len; ++i)
    {
      elem_t *temp=NULL;
      list_get(item->shelf_list, i, temp);
     shelf[i]=(list_t*)temp->p;
    }
  return *shelf;
}


/* Adds shelf to list
 * */
void add_shelf_item(item_t *item, shelf_t *shelf) {
  elem_t newshelf= {.p =shelf};
  list_append(item -> shelf_list, newshelf);
}
/* Deletes item at index
 * */
void delete_shelf_item(item_t *item, int index) {
  bool delete=false;
  if (item->shelf_list->free!=NULL)
    delete=true;
  list_remove(item -> shelf_list, index, delete);
}
/* Skriver ut varan
* */
void print_item(item_t *item) {
  printf("\nNamn: %s\nDesc: %s\nPris: %i\n", (char*)get_name(item),get_description(item), get_price(item));
  printf("Hyllor:\n");
  for (int i=0; i<list_length(item->shelf_list); i++) {
     elem_t *result=NULL;
    list_get(item->shelf_list, i ,result);
    puts(result->p);
      }
}
