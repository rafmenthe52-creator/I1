/**
 * @brief It defines the game interface
 *
 * @file game.h
 * @author Rafael Velasco-RV
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "object.h"
#include "player.h"
#include "types.h"
#include "game_reader.h"
#include "character.h"

#define MAX_SPACES 100
#define MAX_OBJECTS 5
#define MAX_CHARACTERS 5

typedef struct _Game Game;

/**
 * @brief It creates a new Game, allocating memory for it;
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to a struct of type Game
 * @return it returns the Status, either OK or ERROR
 */
Status game_create(Game *game);

/** 
* @brief It creates a new game loading all the spaces, objects and players.
* @author Rafael Velasco-RV
*
* @param game a pointer to struct of type Game
* @param filename a string that contains the name of the file
* @return It returns the Status, either OK or ERROR
*/

Status game_create_from_file(Game *game, char *filename);

/**
 * @brief It deletes the alocated memory and therefore deletes the struct game
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game, which intends to be deleted
 * @return it returns the Status, either OK or ERROR
 */
Status game_destroy(Game *game);

/**
 * @brief This function gets game data (game and its id) and returns the struct of type space which is saved inside the struct game
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the game
 * @return it returns the Space that is saved inside game;
 */
Space *game_get_space(Game *game, Id id);

/**
 * @brief It gets the player from the game
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return the Player pointer stored in the game
 */
Player* game_get_player(Game *game);

/**
 * @brief It gets an object from the game by its id
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the object
 * @return the Object pointer with the specified id, or NULL if not found
 */
Object* game_get_object(Game *game, Id id);

/**
 * @brief It gets the id of the space where the player is located
 * @author Rafae Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return The id of the space the player is located at
 */
Id game_get_player_location(Game *game);

/**
 * @brief It sets the id of the location where the player is located at
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the space 
 * @return The status, either ERROR or OK
 */
Status game_set_player_location(Game *game, Id id);

/*Note: we could eliminate these functions and just use player_get and player_set location. But i prefer to keep them for now. -RV*/

/**
 * @brief It gets the id of the space where the object is located
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return The id of the space the object is located at
 */
Id game_get_object_location(Game *game);

/**
 * @brief It sets the id of the location where the object is located at
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param id the identification number of the space 
 * @return The status, either ERROR or OK
 */
Status game_set_object_location(Game *game, Id id);

/*Note: we could eliminate these functions and just use object_get and object_set location. But i prefer to keep them for now. -RV*/

/**
 * @brief It gets the command used by the player
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return The las command used by the player
 */
Command* game_get_last_command(Game *game);

/**
 * @brief It sets the command used by the player
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param command a pointer to struct of type Command
 * @return Ok if everythin goes well, or Error if there was a mistake
 */
Status game_set_last_command(Game *game, Command *command);

/**
 * @brief It gets if the game has finished
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return The pointer of the finished game
 */
Bool game_get_finished(Game *game);

/** 
 * @brief It sets if the game has finished
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param finished a bool for the game end
 * @return Ok if everythin goes well, or Error if there was a mistake
 */
Status game_set_finished(Game *game, Bool finished);

/**
 * @brief It prints the game map
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return void, no return
 */
void game_print(Game *game);

/**
 * @brief It sums the spaces that there are and creatint a space
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return Ok if everythin goes well, or Error if there was a mistake
 */
Status game_add_space(Game *game, Space *space);

/** 
 * @brief It sums the players that there are and creating a player
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @return Ok if everythin goes well, or Error if there was a mistake
 */
Status game_add_object(Game *game, Object *object);

/**
 * @brief It gets the id of the space where the player is located
 * @author Rafael Velasco-RV
 *
 * @param game a pointer to struct of type Game
 * @param position a parameter for the location of the player
 * @return The Id giving the space id with the position of the player
 */
Status game_add_player(Game *game, Player *player);

#endif
