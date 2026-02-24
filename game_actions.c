/**
 * @brief It implements the game update through user actions
 *
 * @file game.c
 * @author Profesores PPROG & Adrian Covarrubias-AC & Rafael Velasco-RV
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#include "game_actions.h"
#include "player.h"
#include "space.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
   Private functions
*/

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Profesores PPROG
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_unknown(Game *game);

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Profesores PPROG
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_exit(Game *game);

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Profesores PPROG
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_next(Game *game);

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Profesores PPROG
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_back(Game *game);

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Adrian Covarrubias-AC
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_left(Game *game);

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Adrian Covarrubias-AC
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_right(Game *game);

/**
 * @brief This function puts the item in the space into the player and deletes it from the space
 * @author Adrian Covarrubias-AC & Rafael Velasco-RV
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_take(Game *game);

/**
 * @brief This function puts the item from the player in the space and deletes it from the player
 * @author Adrian Covarrubas-AC & Rafael Velasco-RV
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
void game_actions_drop(Game *game);

/**
   Game actions implementation
*/

Status game_actions_update(Game *game, Command *command) {
  CommandCode cmd;

  game_set_last_command(game, command);

  cmd = command_get_code(command);

  switch (cmd) {
    case UNKNOWN:
      game_actions_unknown(game);
      break;

    case EXIT:
      game_actions_exit(game);
      break;

    case NEXT:
      game_actions_next(game);
      break;

    case BACK:
      game_actions_back(game);
      break;

    case TAKE:
      game_actions_take(game);
      break;

    case DROP:
      game_actions_drop(game);
      break;

    default:
      break;
  }

  return OK;
}

/**
   Calls implementation for each action
*/

void game_actions_unknown(Game *game) {}

void game_actions_exit(Game *game) {}

void game_actions_left(Game *game){}

void game_actions_right(Game *game){}

void game_actions_next(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  if (!game || !game_get_player(game)) {
    return;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }    

  current_id = space_get_south(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    player_set_player_location(game_get_player(game), current_id);
  }

  return;
}

void game_actions_back(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  if (!game || !game_get_player(game)) {
    return;
  }

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return;
  }

  current_id = space_get_north(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    player_set_player_location(game_get_player(game), current_id);
  }

  return;
}


void game_actions_left(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  if (!game || !game_get_player(game)) {
    return;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }    

  current_id = space_get_west(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    player_set_player_location(game_get_player(game), current_id);
  }

  return;
}

void game_actions_right(Game *game) {
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  if (!game || !game_get_player(game)) {
    return;
  }

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }    

  current_id = space_get_east(game_get_space(game, space_id));
  if (current_id != NO_ID) {
    player_set_player_location(game_get_player(game), current_id);
  }

  return;
}

void game_actions_take(Game *game){}

void game_actions_drop(Game *game){}

void game_actions_take(Game *game){
  Id current_id = NO_ID;
  Id player_space_id = NO_ID;
  Object *obj = NULL;

  if(!game || !game_get_player(game)){
    return;
  }

  if(player_get_n_objects(game_get_player(game)) >= MAX_OBJECTS){
    return;
  }

  player_space_id = player_get_player_location(game_get_player(game));
  if(player_space_id == NO_ID){
    return;
  }

  /* Get object id from the space */
  current_id = space_get_object_id(game_get_space(game, player_space_id));

  if(current_id == NO_ID){
    return;
  }

  /* Delete object from space */
  if(space_delete_object(game_get_space(game, player_space_id)) != OK){
    return;
  }

  /* Add object to player inventory */
  player_set_objects(game_get_player(game), current_id);

  /* Update object location to NO_ID since it's now in player inventory */
  obj = game_get_object(game, current_id);
  if(obj){
    /*Unassign object location from the space*/
    object_set_location(obj, NO_ID);

    /* Assign object location to player*/
    object_set_player(obj, player_get_id(game_get_player(game)))
  }

  return;
}

void game_actions_drop(Game *game){
  Id current_id = NO_ID;
  Id player_space_id = NO_ID;
  Object *obj = NULL;

  if(!game || !game_get_player(game)){
    return;
  }

  if(player_get_n_objects(game_get_player(game)) == 0){
    return;
  }


  player_space_id = player_get_player_location(game_get_player(game));
  if(player_space_id == NO_ID){
    return;
  }

  /*Check if there is an object in the space*/
  if(space_get_object_id!=NO_ID){
    return;
  }

  /* Get object id from player "inventory" */
  current_id = player_get_objects(game_get_player(game));
  if(current_id == NO_ID){
    return;
  }

  /* Place object in the space */
  space_set_object_id(game_get_space(game, player_space_id), current_id);

  /* Update object location to the space */
  obj = game_get_object(game, current_id);
  if(obj){
    /*Unassign object location from the player*/
    object_set_player(obj, NO_ID);

    object_set_location(obj, player_space_id);
  }

  player_delete_object_from_inventory(game_get_player(game));

  return; 
}

/*Implement new game actions for left right movement */