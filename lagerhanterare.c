#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>
#include<ctype.h>
#include "tree.h"
#include "list.h"
#include "utils.h"
#include "common.h"


typedef struct shelf {
  elem_t *name;
  int amount;
}shelf_t;



typedef struct action
{
  int type; // NOTHING = 0, ADD = 1, REMOVE = 2, EDIT = 3, REMOVE 4
  item_t *merch; // pekar på tillagd vara och redigerade
  item_t *copy; // sparar item vid borttagning och redigering
  list_t *shelves;
}action_t;

void print_menu_db(){
  printf("%s%s%s%s%s%s%s%s"             ,
         "===========================\n",
         "[L]ägga till en vara\n"       ,
         "[T]a bort en vara\n"          ,
         "[R]edigera en vara\n"         ,
         "Ån[g]ra senaste ändringen\n"  ,
         "Lista [h]ela varukatalogen\n" ,
         "[A]vsluta\n"                  ,
         "===========================\n"
         );
}

void print_menu_file(){
  printf("%s%s%s%s%s"             ,
         "===========================\n",
         "[L]äs en databas från en fil\n",
         "[N]y databas\n"          ,
         "[A]vsluta\n"                  ,
         "===========================\n"
         );
}

bool input_is_shelf(elem_t *shelf){
  if (shelf == NULL){
    return false;
  }
  else
    return true;
}

bool unique_shelf(tree_t *db, elem_t *newshelf)
{
 int len = tree_size(db);
  elem_t *elems = tree_elements(db);
  for(int i = 0; i<len; ++i)
    {
      elem_t elem = elems[i];
      list_t *shelflist = elem->shelfs;
      for(int j = 0; j < list_length(shelflist); ++j)
        {
          
          L *shelf = list_get(shelflist, j);
          if(strcmp(newshelf, shelf->name) == 0)
            {
              printf("%s används redan i databasen välj en ny hylla\n",newshelf);
              return false;
            }
        }
    }
  return true;
}
}
