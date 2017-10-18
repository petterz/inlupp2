#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "item.h"
#include "shelfs.h"
#include "list.h"

#define BUFFERSIZE 100

struct ware {
    char *name; /*!< Name of the ware*/
    char *description; /*!< The description of the ware*/
    int price; /*< The price of the ware*/
    list_t *shelf_list;/* <A list of shelfs, using the list.c and shelf.c*/
};

/* Skapar en ware med givna egenskaper
 * */
ware_t *new_ware(char *name, char *desc, int price, list_t *shelf_list) {
    ware_t *item = (ware_t *)malloc(sizeof(ware_t));
    item -> name = strdup(name);
    item -> description = strdup(desc);
    item -> price = price;
    if (shelf_list == NULL) {
        item -> shelf_list = new_list((copy_l)copy_shelf, (iter_l)print_shelf, (iter_l)delete_shelf, (cmp_l)cmp_shelf);
    } else {
        item -> shelf_list = shelf_list;
    }
    return item;
}
/* Tar bort varan och dess eggenskaper
 * */
void delete_ware(ware_t *ware) {
    free(ware -> name);
    free(ware -> description);
    delete_list(ware -> shelf_list);
    free(ware);
}
/* Returnerar en kopia av varan.
 * */
ware_t *copy_ware(ware_t *ware) {
    return new_ware(ware -> name, ware -> description, ware -> price, copy_list(ware -> shelf_list));
}


/* Returnerar en pekare till namnet 
 * */
char *get_name(ware_t *item) {
    return item -> name;
}
/* returns the string, for the description
 * */
char *get_description(ware_t *item) {
    return item -> description;
}
/* returnerar priset
 * */
int get_price(ware_t *item) {
    return item -> price;
}


/*
 * */
void set_name(ware_t *item, char *name) {
    free(item -> name);
    item -> name = strdup(name); 
}
/* Skapar en ny beskrivning
 */
void set_description(ware_t *item, char *desc) {
    free(item -> description);
    item -> description = strdup(desc);
}
/* Bestämmer nytt pris
 * */
void set_price(ware_t *item, int price) {
    item -> price = price;
}


/* Adds shelf to list
 * */
void add_shelf_ware(ware_t *ware, shelf_t *shelf) {
    append_list(ware -> shelf_list, shelf);
}
/* Deletes ware at index
 * */
bool delete_shelf_ware(ware_t *ware, int index) {
    return delete_link_index(ware -> shelf_list, index);
}


/* Compares two wares by name
 * */
int cmp_ware(const void *w1, const void *w2) {
    ware_t *r1 = *(ware_t **)w1;    
    ware_t *r2 = *(ware_t **)w2;    
    return strcmp((r1 -> name), (r2 -> name));
}
/* Compares a wares and a given name 
 * */
int cmp_ware_name_int(ware_t *w1, char *name) {
    return strcmp(w1 -> name, name);
}
/* Compares a wares and a given name 
 * */
bool cmp_ware_name(ware_t *w1, char *name) {
    return (strcmp(w1 -> name, name) == 0);
}
/* Checks if a specific shelf exist in shelf_list
 * */
bool shelf_exist(ware_t *w1, char *s1) {
    return exist_list(w1 -> shelf_list, (cmp_l)cmp_shelf_name, s1 );
}
/*  Returns shelf at given index
 * */
shelf_t *shelf_list_get(ware_t *w1, int index) {
    return get(w1 -> shelf_list, index);
}
/* Returns size of shelf list
 * */
int shelf_list_size(ware_t *w1) {
    return size_list(w1 -> shelf_list);
}
/* Returns true if shelflist == empty
 * */
bool shelf_list_empty(ware_t *w1) {
    if (size_list(w1 -> shelf_list) == 0) {
        return true; 
    }
    else {
        return false;
    }
}

/* Skriver ut varan
* */
void print_ware(ware_t *item) {
  printf("\nNamn: %s\nDesc: %s\nPris: %i\n", get_name(item),get_description(item), get_price(item));
  printf("Hyllor:\n");
  print_list(item -> shelf_list);
}
