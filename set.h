/**
 * @brief It defines the set interface
 *
 * @file set.h
 * @author Adrian Covarrubias-AC
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */
 #ifndef SET_H
 #define SET_H

 #include "types.h"

 #define MAX_SET 100

 typedef struct _Set Set;

 /**
 * @brief It initializates a new set
 * @author Adrian Covarrubias-AC 
 *
 * @return It returns the pointer to the structure, or NULL if something goes wrong
 */
 Set* set_create();

 /**
 * @brief It destroys the set
 * @author Adrian Covarrubias-AC
 *
 * @param s a pointer to the struct Set 
 * @return It returns the Status, either OK or ERROR
 */
 Status set_destroy(Set *s);

 /**
 * @brief It adds a new value to the sets
 * @author Adrian Covarrubias-AC
 *
 * @param s a pointer to the struct Set
  * @param Id An identificator of ids
 * @return It returns the Status, either OK or ERROR
 */
 Status set_add(Set *s, long Id);

 /**
 * @brief It deleates a value of the sets
 * @author Adrian Covarrubias-AC
 *
 * @param s a pointer to the struct Set
 * @param Id An identificator of ids
 * @return it returns the Status, either OK or ERROR
 */
 Status set_delete(Set *s, long Id);

 /**
 * @brief Search from an identificator in a set
 * @author Adrian Covarrubias-AC
 *
 * @param s a pointer to the struct Set
 * @param Id An identificator of ids
 * @return TRUE if it fins it or FALSE if not
 */
 Bool set_find(Set *s, long id);

 /**
 * @brief Prints the Ids from a set
 * @author Adrian Covarrubias-AC
 *
 * @param s a pointer to the struct Set
 * @return Void, no return
 */
 void set_print(Set *s);

 /**
 * @brief Returns the list with all of the Id's in a given set
 * @author Rafael Velasco-RV 
 *
 * @param s a pointer to the struct set
 * @return A list of type id which includes all the id's in the set
 */
 Id* set_getIds(Set *s):

 #endif