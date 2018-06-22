/* parse_argument.h */
#ifndef _PARSE_ARGUMENT_H_
#define _PARSE_ARGUMENT_H_

#include <string.h> /* fuer strcmp, strlen und strcpy */
#include <stdlib.h> /* fuer atoi und atof */

#define RETURN_OK 1
#define RETURN_NOT_FOUND 0
#define RETURN_ERROR -1

/**
* puts the value after <argname>
* in <val> and returns
* RETURN_OK if success
* RETURN_NOT_FOUND if argname wasn't found
* RETURN_ERROR if value after argname wasn't an integer
*/
int parse_argument_int( 
		       int argNum,
		       char **argVec,
		       char *argname,
		       int *val);
/**
 * \see parse_argument_int
*/
int parse_argument_2_int( 
		       int argNum,
		       char **argVec,
		       char *argname,
		       int *val, 
		       int *val2);

/**
 * \see parse_argument_int
*/
int parse_argument_3_int( 
		       int argNum,
		       char **argVec,
		       char *argname,
		       int *val1, 
		       int *val2,
		       int *val3);

/**
* puts the value after <argname>
* in <val> and returns
* RETURN_OK if success
* RETURN_NOT_FOUND if argname wasn't found
* RETURN_ERROR if value after argname wasn't a double
*/
int  parse_argument_double( 
			   int argNum,
			   char **argVec,
			   char *argname,
			   double *val);

/**
* puts the value after <argname>
* in <val> and returns
* RETURN_OK if success
* RETURN_NOT_FOUND if argname wasn't found
* RETURN_ERROR if there was no value after argname
*/
extern int parse_argument_string( 
			  int argNum,
			  char **argVec,
			  char *argname,
			  char **str);
/**
* searches for <argname> and returns
* RETURN_OK if success
* RETURN_NOT_FOUND if argname wasn't found
*/
int parse_argument_flag( 
			int argNum,
			char **argVec,
			char *argname);


#endif /*_PARSE_ARGUMENT_H_*/
