#ifndef __SHELFS_H__
#define __SHELFS_H__

#include <stdbool.h>


/*!
 * \brief A shelf
 * 
 * Each shelf contains a name and a value.
 * The name represents the shelf, nad the value the number of articles on that shelf.
 */
typedef struct shelf shelf_t;

struct shelf {
  char *shelfName; /*!<The name of the shelf, at initialization it is allocated 100*char */
  int ammount; /*!<The ammount of 'Stuff' at a the shelf */
};

/*!
 * \brief Creates a new shelf.
 *
 * Creates a new shelf with a given name and a ammount.
 * \param name  Name of the shelf, max lenght of 99 char
 * \param num   Ammount of wares at the shelf
 *
 * \return Returns a pointer to the shelf
 */
shelf_t *new_shelf(char *name, int num);

/*!
 * \brief Creates a copy of a given shelf
 *
 * Creates a new shelf with new allocated memory with the
 * same name and number of articles as another shelf.
 *
 * \param shelf The shelf that you want a copy of
 *
 * \return Returns a pointer to the copy
 *
 */
shelf_t *copy_shelf(shelf_t *shelf);

/*!
 * \brief Deletes a shelf
 *
 * Frees the struct, name. And thusly deletes it.
 *
 * \param shelf The shelf that is to be deleted
 * \return void
 */
void delete_shelf(shelf_t *shelf);

/*!
 * \brief Prints a shelf
 * Prints the the shelf and number followed by a newline.
 * The for is "[Name] : Num 'st' \n"
 *
 * \param shelf The shelf that is to be printed
 * \return void
 */
void print_shelf(shelf_t *shelf);

/*!
 *\brief Compares two Shelves
 * Compares two shelves's names with 'strcmp(char *1, char *2)' and returns the result, which is a integer.
 * Negative, 0 or positive depending on which shelfe has the 'greater' name. S1 corresponds to char *1 and s2 to char *2
 * 
 * \param s1 The first shelf of the pair to be compared
 * \param s2 The second shelf of the pair to be compared
 * \return int The difference between the names of the shelves.
 */
int cmp_shelf(const void *s1, const void *s2);

/*!
 *\brief Checks if two shelves have the same name
 * Compares the names of two shelves and returns true if the have 'equal' names.
 * Works in the same fashion as cmp_shelf. with cmp_shelf == 0 is true else false.
 *
 * \param shelf The first shelf of the pair to be compared
 * \param name The second shelf of the pair to be compared
 * \return int The difference between the shelfs name and the given one
 */
int cmp_shelf_name(shelf_t *shelf, char *name);


/*!
 * \brief Changes the ammount on one shelf
 * Changes the value of shelf -> num for a given shelf.
 *
 * \param shelf The shelf that is given a new ammount
 * \param newAmmount The new ammount for the shelf
 * \return void
 */
void set_ammount(shelf_t *shelf, int newAmmount);

/*!
 * \brief Changes the name for one shelf
 * Changes the value of shelf -> shelfName for a given shelf.
 *
 * \param shelf The shelf that is given a new Name
 * \param newName The new name for the shelf
 * \return void
 */
void set_shelfname(shelf_t *shelf, char *newName);

/*!
 * \brief Returns the name for a shelf
 * Returns a pointer to the name, not a copy, a pointer.
 * Might be bad, but as of now, it makes no difference
 *
 * \param shelf The shelf to return from
 * \return char *Name for the shelf
 */
char * get_shelfname(shelf_t *shelf);

/*!
 * \brief Returns the amount for a shelf
 * Returns a int with the same value as for shelf -> ammount
 *
 * \param shelf The shelf to return from
 * \return int Ammount for the shelf
 */
int get_ammount(shelf_t *shelf);

#endif
