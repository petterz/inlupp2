#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"
#include "shelfs.h"
#include "list.h"
#include "common.h"
#include "tree.h"

#define BUFFERSIZE 100;

typedef struct item {
    elem_t *name; /*!< Name of the ware*/
    char *description; /*!< The description of the item*/
    int price; /*< The price of the item*/
    list_t *shelf_list;/* <A list of shelfs, using the list.c and shelf.c*/
}item_t;

/* Skapar en item med givna egenskaper
 * */
item_t *new_item(elem_t *name, char *desc, int price, list_t *shelf_list) {
    item_t *item = (item_t *)malloc(sizeof(item_t));
    item -> name = name;
    item -> description = strdup(desc);
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
elem_t *get_name(item_t *item) {
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
void set_name(item_t *item, elem_t *name) {
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


/* Adds shelf to list
 * */
void add_shelf_item(item_t *item, shelf_t *shelf) {
  list_append(item -> shelf_list, shelf);
}
/* Deletes item at index
 * */
bool delete_shelf_item(item_t *item, int index) {
    return delete_link_index(item -> shelf_list, index);
}


/* Compares two items by name
 * */
int cmp_item(const void *w1, const void *w2) {
    item_t *r1 = *(item_t **)w1;    
    item_t *r2 = *(item_t **)w2;    
    return strcmp((r1 -> name), (r2 -> name));
}
/* Compares a items and a given name 
 * */
int cmp_item_name_int(item_t *w1, char *name) {
    return strcmp(w1 -> name, name);
}
/* Compares a items and a given name 
 * */
bool cmp_item_name(item_t *w1, char *name) {
    return (strcmp(w1 -> name, name) == 0);
}
/* Checks if a specific shelf exist in shelf_list
 * */
bool shelf_exist(item_t *w1, char *s1) {
    return exist_list(w1 -> shelf_list, (cmp_l)cmp_shelf_name, s1 );
}
/*  Returns shelf at given index
 * */
shelf_t *shelf_list_get(item_t *w1, int index) {
    return get(w1 -> shelf_list, index);
}
/* Returns size of shelf list
 * */
int shelf_list_size(item_t *w1) {
    return size_list(w1 -> shelf_list);
}
/* Returns true if shelflist == empty
 * */
bool shelf_list_empty(item_t *w1) {
    if (size_list(w1 -> shelf_list) == 0) {
        return true; 
    }
    else {
        return false;
    }
}

/* Skriver ut varan
* */
void print_item(item_t *item) {
  printf("\nNamn: %s\nDesc: %s\nPris: %i\n", get_name(item),get_description(item), get_price(item));
  printf("Hyllor:\n");
  print_list(item -> shelf_list);
}
