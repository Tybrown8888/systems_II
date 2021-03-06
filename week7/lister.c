#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

int 	main 	(int 	argc,
 		 char* 	argv[]
	)	
{
    // This sets 'dirName' = the entered path if one was entered, else self.
    const  	char*    	dirName = (argc > 2) ? argv[1] : ".";

    // This opens the directory 'dirName' and saves a pointer to that directory
    DIR* 	dirPtr = opendir(dirName);

    // If: that's a bad directory name (ie if opendir() returns NULL)
    // Then: an error message is recorded in the stderr filestream
    if (dirPtr == NULL)     
    {
        fprintf(stderr, "C0uld n0t 0pen %s \n", dirName);
        exit(EXIT_FAILURE);
    }

    // while(readAnotherEntry)

    struct 	dirent* 	entryPtr;

    while ( (entryPtr = readdir(dirPtr)) != NULL )
        printf("%s\n",entryPtr->d_name);

    // close
    closedir(dirPtr);

    return(EXIT_SUCCESS);
}
