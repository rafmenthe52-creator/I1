/**
 * @brief 
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 0
 * @date 27-01-2025
 * @copyright GNU Public License
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include "types.h"
#include "object.h"

typedef struct _Character Character;

/**
 * @brief It creates a character
 * @author Adrian Covarrubias-AC
 *
 * @param id the identification number of the new character 
 * @return A new character initialized
 */
Character* character_create(Id id);

/**
 * @brief It destroys the character
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character 
 * @return It returns the Status, either OK or ERROR
 */
Status character_destroy(Character* character);

/**
 * @brief It gets the Id of the character
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character 
 * @return The Id of the character
 */
Id character_get_id(Character* character);

/**
 * @brief It sets the name of the character
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character 
 * @param name a string with the name of the character
 * @return It returns the Status, either OK or ERROR
 */
Status character_set_name(Character* character, char* name);

/**
 * @brief It gets the name of the character
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character 
 * @return a string with the name of the character
 */
const char* character_get_name(Character* character);

/**
 * @brief It sets the general description of the character
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character 
 * @param name a string with the general description of the character
 * @return It returns the Status, either OK or ERROR
 */
Status character_set_gdesc(Character* character, char* gdesc);

/**
 * @brief It sets the general description of the character
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character 
 * @return a string with the general description of the character
 */
const char* charcater_get_gdesc(Character* character);

/**
 * @brief It sets the health of the player
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character
 * @param id The id of the character
 * @return It returns the Status, either OK or ERROR
 */
Status character_set_health(Character* character, ID id);

/**
 * @brief It gets the health of the player
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character
 * @return It returns the health of the character
 */
Id character_get_health(Character* character);

/**
 * @brief It adds health to the player
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character
 * @return It returns the Status, either OK or ERROR
 */
Status character_health_add(Character* character, Id id);

/**
 * @brief It decrease health to the player
 * @author Adrian Covarrubias-AC
 *
 * @param character a pointer to the struct Character
 * @param id The id of the character
 * @param damage The damage the object makes
 * @return It returns the Status, either OK or ERROR
 */
Status character_health_decrease(Character* character, Id id, int damage);

#endif