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
    long *ids;
    int n_ids;
};

 Set* set_create(){
    Set *s=NULL;
    
    if(!(s=(Set*)calloc(1, sizeof(Set)))){
        return NULL;
    }

    if(!(s->ids=(long*)calloc(s->n_ids, sizeof(long)))){
        return NULL;
    }
    return s;
 }

  Status set_destroy(Set *s){
    if(!s){
        return ERROR;
    }

    free(s);
    free(s->ids);
    s = NULL;
    s->ids = NULL;
    return OK;
  }

   Status set_add(Set *s, long Id){
    if(!s || Id<=0){
        return ERROR;
    }

    s->ids[s->n_ids]=ids;
    s->n_ids++;

    return OK;
 }

 Status set_deleate(Set *s, long Id){
    if(!s || Id<=0 || s->n_ids<=0){
        return ERROR;
    }


    s->ids[s->n_ids-1]=NO_ID;
    s->n_ids--;

 }

  Bool set_find(Set *s, long Id){
    int i;
    if(!s || Id<=0 || s->n_ids<=0){
        return FALSE;
    }
    for(i=0; i<s->n_ids; i++){
        if(s->ids[i]!=Id){
            return FALSE;
        }else{
            return TRUE;
        }
    }
  }

   Void set_print(Set *s){
    int i;

    if(!s){
        return;
    }
    for(i=0; i<s->n_ids; i++){
        fprintf(stdout, "%s", s->ids[i]);
    }

   }

