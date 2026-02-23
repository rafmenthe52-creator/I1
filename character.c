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

struct _Character{
    ID id;
    char name[WORDS_SIZE +1];
    char gdesc[MAX_DESC];
    int health;
    bool friendly;
    char message[WORDS_SIZE +1];
};

Character* character_create(Id id){
    Character *character=NULL;
    if(id==NO_ID){
        return NULL;
    }

    if(!(character=(Character*)calloc(1,sizeof(Character)))){
        return NULL;
    }
}

Status character_deleate(Character* character){
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

