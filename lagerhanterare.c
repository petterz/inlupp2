#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "string.h"
#include <time.h>
#include <ctype.h>
#include "utils.h"
#include "common.h"
#include "tree.h"
#include "list.h"
#include "shelfs.h"
#include "item.h"


 


typedef struct action
{
  int type; // NOTHING = 0, ADD = 1, REMOVE = 2, EDIT = 3, REMOVE 4
  item_t *edited; // pekar på tillagd vara och redigerade
  item_t *copy; // sparar item vid borttagning och redigering
}A;

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

void add_goods(tree_t *db, A *action) {
    puts("\n---TILLÄGNING AV NY PRODUKT----\n");
tree_key_t *name = (void*)ask_question_string("Namn på produkten?");
item_t *item=NULL;
bool ans=tree_get(db, *name, (elem_t*)item);

    if (ans) {
        puts("Produkten finns redan, använder samma beskrivning och pris");
    }
    else {
        char *desc = ask_question_string("Beskrivning av produkten?");
        int pris = ask_question_int("Pris på produkten?");
item = new_item((char*)name, desc, pris, NULL);

        if (yes_or_no("Lägga till varan? (J/N)")) {
tree_insert(db, *name, (elem_t*)item);
            puts("Varan är tillagd!");
            }
        else {
            free(item);
            puts("Varan togs bort, inget tillagt!\nÅtergår till Startsidan!");
                        return;
        }
    }
    free(name);
    
    puts("\n\n\n----  HYLLOR ATT LÄGGA IN VARAN PÅ  ----");
    char *hylla;
    int antal;
    do {
        //Hyllor
        hylla = ask_question_shelf(" \nVilken hylla vill du lägga in på?"); 
if (tree_apply(db,0,(void*)(shelf_exist(item,hylla)),NULL)) { //HYLLAN ÄR UPPTAGEN
            puts("Hyllan är upptagen!");
            free(hylla);
        } else {
            antal = ask_question_int("Hur många varor ska ligga där?");
            add_shelf_item(item, new_shelf(hylla, antal));
            free(hylla);
        }
} while (yes_or_no("Fortsätta lägga till hyllor (J/N)") == true); //lägga till fler
    puts("Klar med varan!\nÅtergår till Startsidan!");
    
   action->edited = item;
   action->type = 1;
}

void remove_goods(tree_t *db, A *action) {
if (tree_size(db)==0) {
        puts("DB is empty, nothing to edit.");
        return;
    }

    puts("\n---BORTTAGNING AV PRODUKT----\n");
    item_t *item;
    tree_key_t *name;
    int index;

tree_key_t *keys=tree_keys(db);
for (int i=0;i<tree_size(db);i++){
printf("%p\n",keys[i].p);
}
    puts("\nFrån vilken vara vill ta bort produkter? (Namn, CaSe SenSiTiVe:)");
    do {
name =(elem_t*) ask_question_string("Vilken vara ska tas bort?");

tree_get(db, *name,(elem_t*)get_name(item));
    } while(item == NULL);
    action->copy=item;
action->type = 2;
     do {
        print_item(item);
        index = ask_question_int("Vilken hylla vill du tabort? (0,1,2,3...,eg)");
        if(index>list_length(item->shelf_list)) {
            puts("Ingen hylla finns för det indexet");
        }
        else
          {
delete_shelf_item(item, index);
}

        if (shelf_list_empty(item)) {
            if (yes_or_no("Inga fler hyllplan, vill du tabort varan? (J/N)") == true) {
delete_item(item);
tree_remove(db, *name,NULL);
            }
            break;
        }
    } while(yes_or_no("Ta bort fler hyllpan (J/N)") == true);
    free(name); 
}

/*
 * -------------------------------------------
 * --- --- ---  Edit a Item in DB  --- --- ---
 * -------------------------------------------
 * */
void edit_goods(tree_t *db, A *action) {
if (tree_size(db)==0) {
        puts("DB is empty, nothing to edit.");
        return;
    }

    puts("\n----REDIGERING AV PRODUKT----\n");
    tree_key_t *names;
    tree_key_t name;
elem_t *temp;
    char *c;
names=tree_keys(db);
  int index=ask_question_int("Vilken vara vill du redigera?");
name=names[index];
tree_get(db, name, temp); 
action->copy= copy_item((item_t*)temp);

do
  {
c=ask_question_string("Vad vill du redigera?\n"
                          "[B]eskrivning\n"
                          "[P]ris\n"
                          "[H]ylla\n"
                          "[A]ntal\n"
                          "[E]xit\n");
    if (toupper(*c)== 'B')
      {
char* desc=get_description((item_t*)temp);
printf("Nuvarande beskrivning: %s\n",desc);
        desc=ask_question_string("Ny beskrivning: ");
action->edited=(item_t*)temp;
      }
    else if (toupper(*c)== 'P')
        {
int price =get_price((item_t*)temp);
          printf("Nuvarande pris: %d\n",price);
          price = ask_question_int("Nytt pris för varan: ");
action->edited=(item_t*)temp;
        }
    
    else if (toupper(*c)== 'H')
        {
list_t *shelfs=get_shelfs_item((item_t*)temp);
int length=list_length(shelfs);
shelf_t *shelf;
          for (int i=0 ; i<length ; i++)
            {
list_get(shelfs, i,(elem_t*)shelf);
printf("Hyllnamn:  %s\n",shelf->shelfName);
            }

int hylla=(ask_question_int("Vilken hylla vill du redigera: "));
          char *c;
shelf_t *newShelf;
list_get(shelfs,hylla,(elem_t*)newShelf);
int unique=0;
          while(unique!=-1)
            {
              c = ask_question_shelf("Ny hylla för varan: ");
unique = list_contains(shelfs,*(elem_t*)c);
            }

          newShelf->shelfName = c;
list_remove(shelfs,hylla,false);
list_insert(shelfs,hylla,*(elem_t*)newShelf);
action->edited=(item_t*)temp;
  list_delete(shelfs,false);
free(shelf);
        }
      
      else if(toupper(*c)== 'A')
        {
         list_t *shelfs=get_shelfs_item((item_t*)temp);
int length=list_length(shelfs);
shelf_t *shelf;
          for (int i=0 ; i<length ; i++)
            {
list_get(shelfs, i,(elem_t*)shelf);
printf("Hyllnamn:  %s\n",shelf->shelfName);
            }

int hylla=(ask_question_int("Vilken hylla vill du redigera: "));
          int c;
shelf_t *newShelf;
list_get(shelfs,hylla,(elem_t*)newShelf);
              c = ask_question_int("Nytt antal på hyllan: ");
          newShelf->ammount = c;
list_remove(shelfs,hylla,false);
list_insert(shelfs,hylla,*(elem_t*)newShelf);
action->edited=(item_t*)temp;
  list_delete(shelfs,false);
free(shelf);
        }
  }
 while (toupper(*c) != 'E');
    
  printf("Var god lägg till en vara innan du försöker ändra varorna i databasen");
}

/*
 * Displays the Database
 * */
void display_goods(tree_t *db) {
    puts("\n---- VISNING AV DATABAS ----\n");
    print(db);
    puts("\n----   SLUT PÅ DATABAS  ----\n");
}

/*
 * Adds a Item to DB
 * */
void undo_action(tree_t *db) {
    switch(global_action) {
        case add_a:
            delete_elem(db, (cmp_t)cmp_item_name_int , get_name(global_pointer));
            break;
        case delete_a:
            insert_elem(db, global_saved);
            break;
        case edit_a:
            delete_elem(db, (cmp_t)cmp_item_name_int ,get_name(global_pointer));
            insert_elem(db, global_saved);
            break;
        default:
            puts("Nothing can be undone!");
            break;
    }
    global_action = nothing_a;
    return;
}

/*
 * Save a item pointer, so that it can be reversed
 * */
void save_goods_undo(item_t *item) {
    print_item(item); //LÄGG TILL RETURN NAME
    if (global_saved && global_saved != item) {
        delete_item(global_saved);
    }
    if (!item) {
        puts("FEEEEEEEEEEEEEEEL");
        return;
    }
    global_saved = copy_item(item);
}

