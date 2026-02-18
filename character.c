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

