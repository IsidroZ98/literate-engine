#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smp0_tests.h"

#define LENGTH(s) (sizeof(s) / sizeof(*s))

typedef struct {
  char *word;
  int counter;
} WordCountEntry;

int process_stream(WordCountEntry entries[], int entry_count)
{
  short line_count = 0;
  char buffer[30];

  while (fgets(buffer, 30, stdin)) {
    if (*buffer == '.')
      break;

    int i = 0;
    while (i < entry_count) {
      if (!strcmp(entries[i].word, buffer))
        entries[i].counter++;
      i++;
    }
    line_count++;
  }

  return line_count;
}

void print_result(WordCountEntry entries[], int entry_count)
{
    fprintf(stderr,"Result:\n");

    int i =0;
    while (entry_count-- > 0) {
        fprintf(stdout,"%s:%d\n", entries[i].word, entries[i].counter);
        i++;
        
    }
}

void printHelp(const char *name)
{
    fprintf(stderr,"usage: %s [-h] <word1> ... <wordN>\n", name);
}

int main(int argc, char **argv)
{
  const char *prog_name = *argv;

  WordCountEntry *entries = malloc(argc * sizeof(WordCountEntry));
  int entryCount = 0;

  if (argc > 1 && !strcmp(argv[1], "-test")) {
    run_smp0_tests(argc - 1, argv + 1);
    return EXIT_SUCCESS;
  }

  argv++;
  while (*argv != NULL) {
    if (**argv == '-') {
      switch ((*argv)[1]) {
        case 'h':
          printHelp(prog_name);
          return EXIT_FAILURE;

        default:
          fprintf(stderr,"%s: Unknown option '%s'\n", prog_name, *argv);
          printHelp(prog_name);
          return EXIT_FAILURE;
      }
    } else {
      entries[entryCount].word = *argv;
      entries[entryCount].counter = 0;
      entryCount++;
    }
    argv++;
  }

  if (entryCount == 0) {
    fprintf(stderr,"%s: Please specify at least one word to look for\n", prog_name);
    printHelp(prog_name);
    return EXIT_FAILURE;
  }

  fprintf(stderr,"Looking for %d words\n", entryCount);
  int lines = process_stream(entries, entryCount);
  fprintf(stderr,"Processed %d lines\n", lines);
  print_result(entries, entryCount);

}
