#ifndef _VIEW_H_
#define _VIEW_H_

/**
 * @brief Prints the logo
*/
void view_logo();

/**
 * @brief Prints a message saying that the file does not exist
*/
void view_print_file_nonexistent(char *filename);

/**
 * @brief Prints a message saying that the file have no connections
*/
void view_print_no_connections(char *filename);

/**
 * @brief Prints a message saying that the file is empty
*/
void view_print_file_empty(char *file);


#endif