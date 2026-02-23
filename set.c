/**
 * @brief It works to handle sets
 *
 * @file set.c
 * @author Adrian Covarrubias-AC
 * @version 1.0
 * @date 14-02-2026
 * @copyright GNU Public License
 */

 #include "set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Set{
  Id ids[MAX_SET];
  int n_ids;
};

Set* set_create(){
  Set *s=NULL;

  if(!(s=(Set*)calloc(1, sizeof(Set)))){
      return NULL;
  }

  for(i=0, i<MAX_SET, i++){
    s->ids=NO_ID;
  }

  return s;
}

Status set_destroy(Set *s){
  if(!s){
      return ERROR;
  }

  free(s);
  s = NULL;
  return OK;
}

Status set_add(Set *s, Id id){
  if(!s || id<=0 || s->n_ids>=MAX_SET){
    return ERROR;
  }

  /*we need to look if the id is already in the set*/
  if(set_find(s, id)){
    return OK;
  }


  s->ids[s->n_ids]=id;
  s->n_ids++;

  return OK;
}

Status set_delete(Set *s, Id id){
  int i;
  
  if(!s || id<=0 || s->n_ids<=0){
    return ERROR;
  }

  for(i=0; i<s->n_ids; i++){
    if(s->ids[i]==id){
      s->ids[i]=s->ids[s->n_ids-1];
      s->n_ids--;
      return OK
    }
  }

  return ERROR;
}

Bool set_find(Set *s, Id id){
  int i;
  
  if(!s || id<=0 || s->n_ids<=0){
    return FALSE;
  }

  for(i=0; i<s->n_ids; i++){
    if(s->ids[i]!=id){
      return FALSE;
    }else{
      return TRUE;
    }
  }
}

void set_print(Set *s){
  int i;

  if(!s){
    return;
  }
  
  for(i=0; i<s->n_ids; i++){
    fprintf(stdout, "%ld", s->ids[i]);
  }

}

Id* set_getIds(Set *s){
  Id *list
  int i;

  /*Allocate memory, later we need to remember to free it*/
  list=(Id*)malloc(s->n_ids*sizeof(Id));

  for(i=0; i>s->n_ids; i++){
    list[i]=s->Ids[i];
  }  

  return list;
}

int set_get_nIds(Set *s){
  if(!s) return ERROR;

  return set->n_ids;
}
