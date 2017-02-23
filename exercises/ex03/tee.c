#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){
  if ((argc < 2)){
    fprintf(stderr, "%s\n", "usage: tee [-a] <filename1> [filename2, filename3, ...]");
    return 1;
  }

  char how_to_write = 'w';
  char ch;

  while ((ch = getopt(argc, argv, "a")) != EOF){
    switch(ch){
      case 'a':
        how_to_write = 'a';
        break;
      default:
        fprintf(stderr, "Unknown option: '%s'\n", optarg);
        return 1;
    }
  }

  argc -= optind;
  argv += optind;

  char output[8192];
  while (scanf("%s", &output) < 0) {
    fprintf(stderr, "%s\n", "scanf failed");
  }
  fprintf(stdout, "output: %s\n", output);

  int i = 0;
  FILE *the_file;
  while (i < argc){
    the_file = fopen(argv[i], how_to_write);
    fprintf(stdout, "%s\n", "help");
    fprintf(the_file, "%s\n", output);
    fclose(the_file);
    i++;
  }
  return 0;
}