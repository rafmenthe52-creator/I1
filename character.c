/**
 * @brief 
 *
 * @file character.c
 * @author Adrian Covarrubias-AC
 * @version 1.0
 * @date 14-02-2026
 * @copyright GNU Public License
 */

#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DESC 7
#define MAX_HEALTH 10

struct _Character{
  ID id;
  char name[WORDS_SIZE +1];
  char gdesc[MAX_DESC];
  int health;
  bool friendly;
  char message[WORDS_SIZE +1];
};

Character* character_create(Id id){
  Character *newCharacter=NULL;
  if(id==NO_ID){
      return NULL;
  }

  if(!(newCharacter=(Character*)calloc(1,sizeof(Character)))){
      return NULL;
  }
  
  newCharacter->id = id;
  newCharcater->name[0] = '\0';
  for(i=0; i<MAX_DESC; i++){
  newCharacter->gdesc[i] = '\0';
  }
  newCharacter->health = MAX_HEALTH;
  newCharacter->friendly = TRUE;
  newCharacter->message[0] = '\0';
}

Status character_destroy(Character* character){
  if(!character){
      return ERROR;
  }
  free(character);
  return OK;
}

Id character_get_id(Character* character){
  if(!character){
      return NULL;
  }

  return character->id;
}

Status character_set_name(Character* character, char* name){
  if(!character || !name){
      return ERROR;
  }

  if(!(strcpy(character->name, name))){
      return ERROR;
  }
  return OK;
}

const char* character_get_name(Character* character){
  if(!character){
      return NULL;
  }
  return character->name;
}

Status character_set_gdesc(Character* character, char* gdesc){
  if(!character || gdesc>MAX_DESC){
      return ERROR;
  }
  if(!(strcpy(character->gdesc, gdesc))){
          return ERROR;
      }
  return OK;
}

const char* charcater_get_gdesc(Character* character){
  if(!character){
      return NULL;
  }
  return character->gdesc;
}

Status character_set_health(Charcter* character, ID id){
  if(!character || id==NO_ID){
    return ERROR;
  }
  If(character->health>MAX_HEALTH){
    return ERROR;
  }
return OK;
}

Id character_get_health(Character* character){
  if(!character){
    return 0;
  }
  return character->health;
}

Status character_health_add(Character* character, Id id){
  if(!character || id==NO_ID || character->health>MAX_HEALTH){
    return ERROR;
  }
  character->health++;
  return OK;
}

Status character_health_decrease(Character* character, Id id, int damage){
  int i;
  if(!character || id==NO_ID || damage<0 || character->health<=0){
    return ERROR;
  }

  character->health-=damage;

  return OK;
}



