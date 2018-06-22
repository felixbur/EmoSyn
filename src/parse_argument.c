#include "parse_argument.h"


extern int parse_argument_int(int argc, char **argv,
			      char *argname, int *val)
{
  int i;
  char *end;
  
  for (i=1; i<argc; i++) {
    if (strcmp(argname, argv[i])==0) {
      if (i+1 < argc) {
	if ((*val = strtol(argv[i+1], &end, 0)) != 0) {
	  if (strlen(end)==0)
	    return RETURN_OK;
	}
	else if	(strcmp(argv[i+1], "0") == 0) {
	  *val = 0;
	  return RETURN_OK;
	}
      }
      return RETURN_ERROR;
    }
  }
  return RETURN_NOT_FOUND;
}

extern int parse_argument_double(int argc, char **argv,
				 char *argname, double *val)
{
	int i;
	char *end;
	
	for (i=1; i<argc; i++) {
		if (strcmp(argname, argv[i])==0) {
		  if (i+1 < argc) {
		    if ((*val = strtod(argv[i+1], &end)) != 0) {
		      if (strlen(end)==0)
			return RETURN_OK;
		    }
		    else if (strcmp(argv[i+1], "0") == 0 ||
			     strcmp(argv[i+1], "0.0") == 0 ||
			     strcmp(argv[i+1], ".0") == 0) {
		      *val = 0;
		      return RETURN_OK;
		    }
		  }
		  return RETURN_ERROR;
		}
	}
	return RETURN_NOT_FOUND;
}
int parse_argument_2_int(int argNum, char **argVec,
		       char *argname, int *val1, int *val2) {
  int i;
  char *end1, *end2;
  
  for (i=1; i<argNum; i++) {
    if (strcmp(argname, argVec[i])==0) {
      if (i+2 < argNum) {
	if ((*val1 = strtol(argVec[i+1], &end1, 0)) != 0 && (*val2 = strtol(argVec[i+2], &end2, 0)) != 0)
	  return RETURN_OK;
	else if ((*val1 = strtol(argVec[i+1], &end1, 0)) != 0 && (strcmp(argVec[i+2], "0") == 0)) {
	  *val2 = 0;
	  return RETURN_OK; 
	}
	else if ((*val2 = strtol(argVec[i+2], &end2, 0)) != 0 && (strcmp(argVec[i+1], "0") == 0)) {
	  *val1 = 0;
	  return RETURN_OK; 
	}
      }
      return RETURN_ERROR;
    }
  }
  return RETURN_NOT_FOUND;
}
int parse_argument_3_int(int argNum, char **argVec,
			 char *argname, int *val1, int *val2, int *val3) {
  int i, ok=0;
  char *end1, *end2, *end3;
  
  for (i=1; i<argNum; i++) {
    if (strcmp(argname, argVec[i])==0) {
      if (i+3 < argNum) {
	if ((*val1 = strtol(argVec[i+1], &end1, 0)) != 0 && strlen(end1)==0)
	  ok++;
	if (strcmp(argVec[i+1], "0") == 0) {
	  *val1 = 0;
	  ok++; 
	}
	if ((*val2 = strtol(argVec[i+2], &end2, 0)) != 0  && strlen(end2)==0)
	  ok++;
	if (strcmp(argVec[i+2], "0") == 0) {
	  *val2 = 0;
	  ok++; 
	}
	if ((*val3 = strtol(argVec[i+3], &end3, 0)) != 0  && strlen(end3)==0)
	  ok++;
	if (strcmp(argVec[i+3], "0") == 0) {
	  *val3 = 0;
	  ok++; 
	}
	if (ok==3)
	  return RETURN_OK; 
      }
      return RETURN_ERROR;
    }
  }
  return RETURN_NOT_FOUND;
}

extern int parse_argument_string(int argc, char **argv,
				 char *argname, char **str)
{
  int i;
  
  for (i=1; i<argc; i++) {
    if (strcmp(argname, argv[i])==0) {
      if (i+1 < argc) {
	*str = argv[i+1];
	return RETURN_OK;
      }
      return RETURN_ERROR;
    }
  }
  return RETURN_NOT_FOUND;
}

extern int parse_argument_flag(int argc, char **argv,
			       char *argname)				   
{
  int i;
  
  for (i=1; i<argc; i++) {
    if (strcmp(argname, argv[i])==0)
      return RETURN_OK;
  }
  return RETURN_NOT_FOUND;
}


