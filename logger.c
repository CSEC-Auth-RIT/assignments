#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LOGFILE "logfile"


// helper function
void print_ids(const char* label) {
  printf("[%s] EUID: %d, UID: %d\n", label, geteuid(), getuid());
}

void initialize()
{
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

void operate(FILE *logfile)
{
  // ADD HERE
  // write to the log file
  // time, ctime, and strchr may be useful here
  time_t now;
  char *time_str;

  //current time
  time(&now);
  time_str = ctime(&now);

  //new line added and replace to match the format
  char *newline = strchr(time_str, '\n');
  if (newline) *newline = '\0';

  //write to log file
  fprintf(logfile, "%s: Nothing happened.\n", time_str);
    printf("Log entry written.\n");
    
    fclose(logfile);
}

int main(int argc, char *argv[])
{
  // ADD BELOW
  // useful commands: getuid, geteuid, setuid, setruid, seteuid, setreuid
  FILE *logfile;

  print_ids("Startup");

  initialize();         // arbitrary

  logfile = secure_open(LOGFILE, "a+");

  if (!logfile) {
    error();            // report and exit
  }

  if (seteuid(getuid()) != 0) {
    perror("Failed to drop privileges");
    return 1;
  }

  print_ids("After Dropping Privileges");

  // write to the logfile, close the file
  operate(logfile);
  return 1;
}
