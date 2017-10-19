#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "shelfs.h"
#include "common.h"


// Newxxxxxx
shelf_t *new_shelf(char *name, int num) {
    shelf_t *shelf = (shelf_t *)malloc(sizeof(shelf_t));
    shelf -> shelfName = name;
    shelf -> ammount = num;
    return shelf;
}
// Copy
shelf_t *copy_shelf(shelf_t *shelf) {
    return new_shelf(shelf -> shelfName, shelf -> ammount);
}
// Delete
void delete_shelf(shelf_t *shelf) {
    free(shelf -> shelfName);
    free(shelf);
}
// Print
void print_shelf(shelf_t *shelf) {
  printf("[%s] : %i st\n",(char*) (shelf -> shelfName), shelf -> ammount);
}
// Cmp
int cmp_shelf(const void *s1, const void *s2) {
    shelf_t *r1 = *(shelf_t **)s1;
    shelf_t *r2 = *(shelf_t **)s2;
    int i = strcmp((char*)(r1 -> shelfName), (char*)(r2 -> shelfName));
    return i;
}
// Cmp TF
int cmp_shelf_name(shelf_t *shelf, char *name) {
  int i = strcmp((char*)shelf -> shelfName, (char*)name);
    return i;
}

// GET & SET
// Name
char *get_shelfname(shelf_t *shelf) {
    return shelf -> shelfName;
}
void set_shelfname(shelf_t *shelf, char *newName) {
    shelf -> shelfName = newName;
}

// Ammount
int get_ammount(shelf_t *shelf) {
    return shelf -> ammount;
}
void set_ammount(shelf_t *shelf, int newAmmount) {
    shelf -> ammount = newAmmount;
}
