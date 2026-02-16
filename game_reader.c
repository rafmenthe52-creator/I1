/**
 * @brief This function reads the data in castle.dat and calls space to create a space. Later it creates a a game with that space
 *
 * @file game_reader.c
 * @author Rafael Velasco-RV
 * @version 1.0
 * @date 04-02-2025
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>

#include "game_reader.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "game.h"

/**
   Implementation of public functions
*/

Status game_reader_load_spaces(Game *game, char *filename) {
  FILE *file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char *toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  Bool bool_object = FALSE;
  Space *space = NULL;
  Status status = OK;

  /* Control error */
  if (!game || !filename) {
    return ERROR;
  }

  /* Opens file in read mode */
  if (!(file = fopen(filename, "r"))) {
    return ERROR;
  }

  /* Reads file line by line */
  while (fgets(line, WORD_SIZE, file)) {

    /* Checks if the line defines a space */
    if (strncmp("#s:", line, 3) == 0) {

      /* Divides space id */
      toks = strtok(line + 3, "|");
      id = atol(toks);

      /* Divides space name */
      toks = strtok(NULL, "|");
      if (!toks) continue;
      strcpy(name, toks);

      /* Divides connections (north, east, south, west) */
      toks = strtok(NULL, "|");
      if (!toks) continue;
      north = atol(toks);

      toks = strtok(NULL, "|");
      if (!toks) continue;
      east = atol(toks);

      toks = strtok(NULL, "|");
      if (!toks) continue;
      south = atol(toks);

      toks = strtok(NULL, "|");
      if (!toks) continue;
      west = atol(toks);

      /* Divides object presence flag */
      toks = strtok(NULL, "|");
      if (!toks) continue;
      bool_object = atol(toks) ? TRUE : FALSE;

      /* Creates the space */
      space = space_create(id);
      if (!space) {
        fclose(file);
        return ERROR;
      }

      /* Sets the space attributes */
      space_set_name(space, name);
      space_set_north(space, north);
      space_set_east(space, east);
      space_set_south(space, south);
      space_set_west(space, west);
      space_set_object(space, bool_object);
      
      /* Adds the space to the game */
      status = game_add_space(game, space);
    }
  }

  /* Checks for reading errors */
  if (ferror(file)) {
    status = ERROR;
  }

  fclose(file);
  return status;
}

Status game_reader_load_objects(Game* game, char* filename) {
  FILE *file = NULL;
  char line[WORD_SIZE];
  char name[WORD_SIZE];
  char *toks = NULL;
  Id id = NO_ID, location = NO_ID;
  Object *object = NULL;
  Space *space = NULL;
  Status status = OK;

  /* Control error */
  if (!game || !filename) {
    return ERROR;
  }

  /* Opens the file */
  if (!(file = fopen(filename, "r"))) {
    return ERROR;
  }
  
  /* Reads the file line by line */
  while (fgets(line, WORD_SIZE, file)) {

    /* Checks if the line defines an object */
    if (strncmp("#o:", line, 3) == 0) {

      /* Divides the object id */
      toks = strtok(line + 3, "|");
      id = atol(toks);

      /* Divides the object name */
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      /* Divides the object location */
      toks = strtok(NULL, "|");
      location = atol(toks);

      /* Creates the object */
      object = object_create(id);
      if (!object) {
        fclose(file);
        return ERROR;
      }      

      /* Sets the object attributes */
      object_set_name(object, name);
      object_set_location(object, location);

      /* Adds the object to the game */
      game_add_object(game, object);

      /* Updates the space so it registers the object located in it */
      space = game_get_space(game, location);
      if (space != NULL) {
        space_set_objects(space, id);
      }
    }
  }

  fclose(file);
  return status;
}

Status game_reader_load_player(Game* game, char* filename) {
  FILE *file = NULL;
  char line[WORD_SIZE];
  char name[WORD_SIZE];
  char *toks = NULL;
  Id id = NO_ID;
  Player *player = NULL;
  Status status = OK;
  
  /* Control error */
  if (!game || !filename) {
    return ERROR;
  }
  
  /* Opens the file */
  if (!(file = fopen(filename, "r"))) {
    return ERROR;
  }
  
  /* Reads the file line by line */
  while (fgets(line, WORD_SIZE, file)) {

    /* Checks if the line defines the player */
    if (strncmp("#p:", line, 3) == 0) {

      /* Divides the player id */
      toks = strtok(line + 3, "|");
      id = atol(toks);

      /* Divides the player name */
      toks = strtok(NULL, "|");
      strcpy(name, toks);

      /* Creates the player */
      player = player_create(id);
      if (!player) {
        fclose(file);
        return ERROR;
      }

      /* Sets the player attributes */
      player_set_name(player, name);

      /* Adds the player to the game */
      game_add_player(game, player);
    }
  }
  
  fclose(file);
  return status;
}
