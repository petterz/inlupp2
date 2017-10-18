#ifndef __ITEM_H__
#define __ITEM_H__

#include "list.h"
#include "shelfs.h"

/*!
 * \brief A struct representing the Ware
 * */
typedef struct ware ware_t;

/*!
 * \brief Creates a new ware
 * Creates a new ware witha given name, description, price and a list of shelves
 *
 * \param name The name of the ware.
 * \param desc The description of the ware, what it is e.t.c.
 * \param price The price of the ware
 * \param shelf_list A list of shelf objects. Uses the list.c for the list and all the objects in it should be from shelf.c
 * \return A pointer to a Ware, (struct ware)
 */
ware_t *    new_ware(char *name, char *desc, int price, list_t *shelf_list);

/*!
 * \brief Creates a deep copy of a ware
 * Creates a deep copy of a ware,  it allocates new memory for all the structs fields.
 * Then returns a pointer to a new one.
 *
 * \param ware The ware that is to be copied
 * \return Pointer to the new ware
 */
ware_t *    copy_ware(ware_t *ware);

/*!
 * \brief Deletes a ware and all its field
 * Deletes everything for the ware, name, desc, price and list and its content.
 *
 * return void
 */
void        delete_ware(ware_t *ware);

/*!\brief Changes the name for ware
 * Frees the old name and points to a new on given as parameter
 * 
 * \param item The ware that has it name changed
 * \param desc The new name of the ware
 * \return void
 */
void        set_name(ware_t *item, char* desc);

/*!\brief Changes the descriptiom for ware
 * Frees the old descriptiom and points to a new on given as parameter
 * 
 * \param item The ware that has it description changed
 * \param desc The new description of the ware
 * \return void
 */
void        set_description(ware_t *item, char *desc);

/*!\brief Changes the price for ware
 * Frees the old price and points to a new on given as parameter
 * 
 * \param item The ware that has it price changed
 * \param desc The new price of the ware
 * \return void
 */
void        set_price(ware_t *item, int price);

/*!
 * \brief Returns ware name
 * Returns a pointer to the name of the ware
 *
 * \param item The ware
 * \return char *The name of the ware
 */
char *      get_name(ware_t *item);

/*!
 * \brief Returns ware description 
 * Returns a pointer to the description of the ware
 *
 * \param item The ware
 * \return char *The description of the ware
 */
char *      get_description(ware_t *item);

/*!
 * \brief Returns ware price
 * Returns the price of the ware 
 *
 * \param item The ware
 * \return int The price of the ware
 */
int         get_price(ware_t *item);

/*!
 * \brief Adds a shelf to the ware list
 * Adds a shelf struct to the list for the ware. Appends the shelf to the list
 *
 * \param ware The ware that gets a new shelf
 * \param shelf The shelf that is added
 * \return void
 */
void        add_shelf_ware(ware_t *ware, shelf_t *shelf);

/*!
 * \brief Deletes a shelf for the list
 * Deletes a shelf in the wares shelf_list at a given index. Also deletes its content.
 *
 * \param ware The ware that you remove a shelf for
 * \param index The index that you remove a shelf from
 * \return bool True if there was a ware at that index and it was removed.
 * */
bool        delete_shelf_ware(ware_t *ware, int index);

/*!
 * \brief compares two wares w1 & w2
 * Compares the two wares w1 & w2 by there names.
 * Uses strcmp(s1, s2) to compare the names of the wares;
 *
 * \param w1 The first ware to be compare
 * \param w2 the second ware
 * \return int Int displaying the relation between the two wares
 */
int         cmp_ware(const void *w1, const void *w2);

/*!
 * \brief compares a wares name and a string
 * Compares a ware w1 and char *name
 * Uses strcmp(s1, s2) to compare the strings;
 *
 * \param w1 The first ware to be compare
 * \param name The char to compare the ware with 
 * \return int Int displaying the relation between the wares name and a string
 */
int        cmp_ware_name_int(ware_t *w1, char *name);

/*!
 * \brief compares a wares name and a string
 * Compares a ware w1 and char *name
 * Uses strcmp(s1, s2) to compare the strings;
 *
 * \param w1 The first ware to be compare
 * \param name The char to compare the ware with 
 * \return int Int displaying the relation between the wares name and a string
 */
bool        cmp_ware_name(ware_t *w1, char *name);

/*!
 * \brief Checks if shelf existin ware
 * Checks if a shelf with the name s1 exist in the shelf_list for the ware
 *
 * \param w1 The ware to be checked
 * \param s1 the Name of the shelf that is checked for
 * \return bool True if shelf exist
 */
bool        shelf_exist(ware_t *w1, char *s1);

/*!
 * \brief Returns a pointer to a shelf at a certain index
 * Uses the get(int) function from list to return a shelf at a certain index
 *
 * \param w1 The ware that has the shelf_list
 * \param index The index that the ware is at
 * \return shelf_t *The shelf at the index, else NULL
 */
shelf_t *   shelf_list_get(ware_t *w1, int index);

/*!
 * \brief checks if the list is empty
 * Returns true if the list is empty, uses size list == 0
 *
 * \param w1 the ware that is is looked at
 * \return bool True if shelf_list is empy
 */
bool        shelf_list_empty(ware_t *w1);

/*!
 * \brief The size of the list for the ware
 * Uses list.c's function size_list() to return the size of the list
 *
 * \param w1 The ware that has the list
 * \return The size of the shelf_list
 */
int         shelf_list_size(ware_t *w1);

/*!
 * \biref Prints a ware to the terminal
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
void        print_ware(ware_t *item);

#endif
