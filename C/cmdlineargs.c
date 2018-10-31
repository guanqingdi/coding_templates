//====================================
// Handling command line arguments
//====================================




#include <stdio.h>      /* input, output    */
#include <string.h>
#include <unistd.h>     /* parse options starting with - or -- */
#include <stdlib.h>     /* abort() */


int
main( int argc,     // input argument count (including program name)
      char *argv[]  // input argument vector
    )
{
  
  printf("For best results, run ./cmdlineargs.o something 17 -a -c 1 -b -d \n\n");


  printf("Doing things manually. ");
  printf("These were your cmd line args:\n");

  for (int i = 0; i < argc; i++){
    printf("Arg %d: %s\n", i, argv[i]);
  }


  printf("\n\nUsing getopt():\n");

  int c;
  char *cval = NULL;

  while ((c = getopt(argc, argv, "abc:")) != -1)
  {
    switch (c)
    {
      case 'a':
        printf("Got arg a.\n");
        break;
      case 'b':
        printf("Got arg b.\n");
        break;
      case 'c':
        cval = optarg;
        printf("Got arg c with optional argument %c\n", *cval);
        break;
      case '?':
        if (optopt == 'c')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        /* else if (isprint(optopt)) */
        /*   fprintf (stderr, "Unknown option `-%c'.\n", optopt); */
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
        printf("Aborting.\n");
        abort();
    }
  }

  printf("Finished.\n");



  return(0);
}

