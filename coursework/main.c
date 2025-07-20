#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_api.h"

int main(int argc, char *argv[]) {
  sensor_stats_t *db = constructor();
  int opt;
  char *filename = NULL;
  int num_month;
  int exit_status = EXIT_SUCCESS;

  if (argc == 1) {
    fprintf(stdout, "Usage %s [-h] [-f filename.csv] [-m 1-12]\n", argv[0]);
    exit_status = EXIT_FAILURE;
    goto exit;
  }

  while ((opt = getopt(argc, argv, "hf:m:")) != -1) {
    switch (opt)
    {
    case 'h':
      fprintf(stdout, "Usage %s [-h] [-f filename.csv] [-m 1-12]\n", argv[0]);
      exit(EXIT_SUCCESS);
      break;
    case 'f':
      filename = optarg;
      if (get_records_from_file(db, filename) == -1) {
        exit_status = EXIT_FAILURE;
        goto exit;
      }
      if (argc == optind) {
        show_year_stats(db);
      }
      break;
    case 'm':
      num_month = atoi(optarg);
      if (num_month < 1 || num_month > 12) {
        fprintf(stdout, "Enter for option -m value 1-12\n");
        exit_status = EXIT_FAILURE;
        goto exit;
      }
      if (filename == NULL) {
        fprintf(stdout, "For option -m need file with data\n");
        exit_status = EXIT_FAILURE;
        goto exit;
      }
      show_month_stats(db, num_month);
      break;
    default:
      fprintf(stdout, "Usage %s [-h] [-f filename.csv] [-m 1-12]", argv[0]);
      exit_status = EXIT_FAILURE;
      goto exit;
    }
  }

exit:
  destructor(db);
  exit(exit_status);
}