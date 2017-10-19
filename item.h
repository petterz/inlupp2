#ifndef __ITEM_H__
#define __ITEM_H__

#include "common.h"
#include "list.h"
#include "shelfs.h"
#include "tree.h"


/*!
 * \brief A struct representing the Item
 * */
typedef struct item item_t;

/*!
 * \brief Creates a new item
 * Creates a new item witha given name, description, price and a list of shelves
 *
 * \param name The name of the item.
 * \param desc The description of the item, what it is e.t.c.
 * \param price The price of the item
 * \param shelf_list A list of shelf objects. Uses the list.c for the list and all the objects in it should be from shelf.c
 * \return A pointer to a Item, (struct item)
 */
item_t *    new_item(tree_key_t *name, char *desc, int price, list_t *shelf_list);

/*!
 * \brief Creates a deep copy of a item
 * Creates a deep copy of a item,  it allocates new memory for all the structs fields.
 * Then returns a pointer to a new one.
 *
 * \param item The item that is to be copied
 * \return Pointer to the new item
 */
item_t *    copy_item(item_t *item);

/*!
 * \brief Deletes a item and all its field
 * Deletes everything for the item, name, desc, price and list and its content.
 *
 * return void
 */
void        delete_item(item_t *item);

/*!\brief Changes the name for item
 * Frees the old name and points to a new on given as parameter
 * 
 * \param item The item that has it name changed
 * \param desc The new name of the item
 * \return void
 */
void        set_name(item_t *item, elem_t* name);

/*!\brief Changes the descriptiom for item
 * Frees the old descriptiom and points to a new on given as parameter
 * 
 * \param item The item that has it description changed
 * \param desc The new description of the item
 * \return void
 */
void        set_description(item_t *item, char *desc);

/*!\brief Changes the price for item
 * Frees the old price and points to a new on given as parameter
 * 
 * \param item The item that has it price changed
 * \param desc The new price of the item
 * \return void
 */
void        set_price(item_t *item, int price);

/*!
 * \brief Returns item name
 * Returns a pointer to the name of the item
 *
 * \param item The item
 * \return char *The name of the item
 */
tree_key_t * get_name(item_t *item);

/*!
 * \brief Returns item description 
 * Returns a pointer to the description of the item
 *
 * \param item The item
 * \return char *The description of the item
 */
char *      get_description(item_t *item);

/*!
 * \brief Returns item price
 * Returns the price of the item 
 *
 * \param item The item
 * \return int The price of the item
 */
int         get_price(item_t *item);

/*!
 * \brief Adds a shelf to the item list
 * Adds a shelf struct to the list for the item. Appends the shelf to the list
 *
 * \param item The item that gets a new shelf
 * \param shelf The shelf that is added
 * \return void
 */
void        add_shelf_item(item_t *item, shelf_t *shelf);

/*!
 * \brief Deletes a shelf for the list
 * Deletes a shelf in the items shelf_list at a given index. Also deletes its content.
 *
 * \param item The item that you remove a shelf for
 * \param index The index that you remove a shelf from
 * \return bool True if there was a item at that index and it was removed.
 * */
void      delete_shelf_item(item_t *item, int index);

/*!
 * \brief compares two items w1 & w2
 * Compares the two items w1 & w2 by there names.
 * Uses strcmp(s1, s2) to compare the names of the items;
 *
 * \param w1 The first item to be compare
 * \param w2 the second item
 * \return int Int displaying the relation between the two items
 */
int         cmp_item(const void *w1, const void *w2);

/*!
 * \brief compares a items name and a string
 * Compares a item w1 and char *name
 * Uses strcmp(s1, s2) to compare the strings;
 *
 * \param w1 The first item to be compare
 * \param name The char to compare the item with 
 * \return int Int displaying the relation between the items name and a string
 */
int        cmp_item_name_int(item_t *w1, elem_t *name);

/*!
 * \brief compares a items name and a string
 * Compares a item w1 and char *name
 * Uses strcmp(s1, s2) to compare the strings;
 *
 * \param w1 The first item to be compare
 * \param name The char to compare the item with 
 * \return int Int displaying the relation between the items name and a string
 */
bool        cmp_item_name(item_t *w1, elem_t *name);

/*!
 * \brief Checks if shelf existin item
 * Checks if a shelf with the name s1 exist in the shelf_list for the item
 *
 * \param w1 The item to be checked
 * \param s1 the Name of the shelf that is checked for
 * \return bool True if shelf exist
 */
bool        shelf_exist(item_t *w1, char *s1);

/*!
 * \brief Returns a pointer to a shelf at a certain index
 * Uses the get(int) function from list to return a shelf at a certain index
 *
 * \param w1 The item that has the shelf_list
 * \param index The index that the item is at
 * \return shelf_t *The shelf at the index, else NULL
 */
shelf_t *   shelf_list_get(item_t *w1, int index);

/*!
 * \brief checks if the list is empty
 * Returns true if the list is empty, uses size list == 0
 *
 * \param w1 the item that is is looked at
 * \return bool True if shelf_list is empy
 */
bool        shelf_list_empty(item_t *w1);

/*!
 * \brief The size of the list for the item
 * Uses list.c's function size_list() to return the size of the list
 *
 * \param w1 The item that has the list
 * \return The size of the shelf_list
 */
int         shelf_list_size(item_t *w1);

/*!
 * \biref Prints a item to the terminal
 * Prints it on the form
 * Name :
 * Desc :
 * Pris :
 * Hyllor :
 * 1. Hylla :
 *    Antal :
 * 2. OSV
 *
 */
void        print_item(elem_t *item);

#endif
