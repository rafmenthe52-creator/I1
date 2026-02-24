#include "object.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Object
 *
 * This struct stores all the information of an object
 */

struct Object {
  Id id;                    /*!< Id number of the object, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  Id space;                 /*!< Id of the space the object is located at*/
  Id player;                /*!< Id of the player the player who is carrying the object*/
  int damage;
};


/**
   Implementation of public functions
*/


/** object_create allocates memory for a new object
 *  and initializes its members
 */
Object* object_create(Id id) {
  Object* newObject = NULL;

  /* Error control */
  if (id == NO_ID) return NULL;

  newObject = (Object*)malloc(sizeof(Object));
  if (newObject == NULL) {
    return NULL;
  }

  /* Initialization of an empty object*/
  newObject->id = id;
  newObject->name[0] = '\0';
  newObject->object_location = NO_ID;
  newObject->damage = 0;

  return newObject;
}

Status object_destroy(Object* object) {
  /*Check for content in object*/
  if (!object) {
    return ERROR;
  }

  /*Clear memory*/
  free(object);          
  return OK;
}

Id object_get_id(Object* object){
  /*Check for content in object*/
  if(!object){
    return NO_ID;
  }
  /*returns the id */
  return object->id;
}

Status object_set_name(Object* object, char* name){
  /*Checks for content*/
  if(!object|!name){
    return ERROR;
  }

  /*copies the input name to the variable name in the struct object*/
  if(!(strcpy(object->name, name))){
    return ERROR;
  }

  return OK;
}

char* object_get_name(Object* object){
  /*Check for content in object*/
  if(!object){
    return NULL;
  }

  return object->name;
}

Status object_set_location(Object* object, Id id){
  /*Checks for content*/
  if (!object||!id){
    return ERROR;
  }

  /*sets the object location to the given id*/
  object->object_location = id;   

  return OK;
}

Id object_get_location(Object* object){
  /*Check for content in object*/
  if(!object){
    return NO_ID;
  }

  return object->object_location;
}

Status object_set_player(Object *object, Id id){
  if(!object||!id){
    return ERROR;
  }

  object->player = id;

  return OK;
}

Id object_get_player(Object *object){
  return object->player; 
}

Status object_set_damage(Object* object, int damage){
  if(!object){
    return ERROR;
  }

  object->damage=damage;

  return OK;
}

int object_get_damage(Object* object){
  return object->damage;
}

Status object_print(Object* object) {
  Id idaux = NO_ID;

  /* Error Control */
  if (!object) {
    return ERROR;
  }

  /* 1. Print the id and the name of the object */
  fprintf(stdout, "--> object (Id: %ld; Name: %s)\n", object->id, object->name);

  /* 2. Print the objects location */
  idaux = object_get_location(object);
  if (idaux != NO_ID) {
    fprintf(stdout, "---> Object location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No object location.\n");
  }
  

  return OK;
}
