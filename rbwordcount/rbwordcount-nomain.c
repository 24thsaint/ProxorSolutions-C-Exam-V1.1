/* rbwordcount-nomain.c -- a file used to build test version
 *
 * Copyright 2014, Proxor
 *
 * This file is used to test rbwordcount.c. It redefines main so that
 * main() can exist in a test driver. 
 * DO NOT MODIFY THIS FILE.
 */

#define main solution_main
#include "rbwordcount.c"

