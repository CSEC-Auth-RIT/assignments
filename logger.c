#include<unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LOGFILE "logfile"

void initialize()
{
  // Lots of other stuff could be happening here
  printf("Initializing the program.\n");
}

FILE *secure_open(char *filename, char *mode)
{
  // This should really do things like:
  //   - check the format filename (if input from the user)
  //   - check the file descriptor number (not stdout, say)
  // BUT you don't need to for this assignment.

  FILE *file;
  file = fopen(filename, mode);
  return file;
}

void error()
{
  printf("Error opening logfile. Exiting.\n");
  exit(1);
}

void operate()
{
  // ADD HERE
  // write to the log file
  // time, ctime, and strchr may be useful here
}

int main(int argc, char *argv[])
{
  // ADD BELOW
  // useful commands: getuid, geteuid, setuid, setruid, seteuid, setreuid
  FILE *logfile;

  initialize();         // arbitrary

  logfile = secure_open(LOGFILE, "a+");

  if (!logfile) {
    error();            // report and exit
  }

  // write to the logfile, close the file
  operate();
  return 1;
}
