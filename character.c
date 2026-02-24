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

Status character_set_health(Charcter* character, int health){
  if(!character || health>MAX_HEALTH || health<0){
    return ERROR;
  }

  character->health=health;
return OK;
}

int character_get_health(Character* character){
  if(!character){
    return 0;
  }
  return character->health;
}

Status character_health_add(Character* character){
  if(!character || character->health>=MAX_HEALTH){
    return ERROR;
  }
  character->health++;
  return OK;
}

Status character_health_decrease(Character* character, int damage){
  int i;
  if(!character || damage<0 || character->health<=0){
    return ERROR;
  }

  character->health-=damage;

  if(character->health<=0){
    character_destroy(character);
  }

  return OK;
}

Status character_set_ifenemy(Character* character, Bool value){
  if(!character){
    return ERROR;
  }void set_print(Set *s)
  character->friendly = value;
  return OK;
}

Bool character_get_ifenemy(Character* character){
  if(!character){
    return FALSE;
  }
  return character->friendly;
}

Status character_set_message(Character* character, char* message){
  if(!character || message>WORD_SIZE){
    return ERROR;
  }
  if(!(strcpy(character->message, message))){
    return ERROR,
  }
  return OK;
}

const char* charcater_get_message(Character* character){
  if(!character){
    return NULL;
  }
  return character->message;
}

Status character_print(Character* character){
  if(!character){
    return ERROR;
  }

  fprintf(stdout, "--> Character (ID: %ld; Name: %s)\n", character->id, character->name);

  if(character_get_gdesc(character)==ERROR){
    return ERROR;
  }else{
    fprintf(stdout, "--> Graphical description: %s", character->gdesc);
  }

  if(character_get_health(Character* character)==0){
    return;
  }else{
    fprintf(stdout, "--> Health: %d", character->health);
  }

  if(character_get_ifenemy(character)==FALSE){
    fprintf(stdout, "--> Enemy");
  }else{
    fprintf(stdout, "--> Friendly");
  }

    fprintf(stdout, "--> Message: %s", character->message);
  
return OK;
}




