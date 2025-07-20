#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include "temp_api.h"

#define BORDER() \
printf("------------------------------------------------------------\n"); \

#define HEADEARTABLE() \
BORDER() \
printf("| Year | Month | NumMonth | MonthAvg | MonthMax | MonthMin |\n"); \
BORDER() \

#define BODYTABLE(year, month, num, mavg, mmax, mmin) \
printf("| %4d | %5d | %8d | %8.2f | %8d | %8d |\n", year, month, num, mavg, mmax, mmin); \

#define FOOTER() \
BORDER()

#define UPDATEMAX(mx, curr) \
if (mx < curr) mx = curr; \

#define UPDATEMIN(mn, curr) \
if (mn > curr) mn = curr; \


sensor_stats_t* constructor() {
  sensor_stats_t *ss = malloc(sizeof(sensor_stats_t));
  ss->stats = malloc(sizeof(sensor_t) * 2);
  ss->len = 0;
  ss->size = 2;
  return ss;
}

void destructor(sensor_stats_t *this) {
  free(this->stats);
  free(this);
}

static void add_record(sensor_stats_t *this, sensor_t rec) {
  if (this->len == this->size) {
    sensor_t *tmp = (sensor_t*)realloc(this->stats, sizeof(sensor_t) * this->size * 2);
    this->stats = tmp;
    this->size *= 2;
  }
  sensor_t *tmp2 = &(this->stats[this->len]);
  memcpy(tmp2, &rec, sizeof(sensor_t));
  this->len++;
}

int get_records_from_file(sensor_stats_t *this, char *path_to_file) {
  FILE *fd = NULL;
  fd = fopen(path_to_file, "r");
  if (!fd) {
    perror("fopen");
    return -1;
  }
  char buf[256] = {};
  sensor_t tmp;
  while (fgets(buf, sizeof(buf), fd) != NULL) {
    int ret = sscanf(buf, "%hd;%hhd;%hhd;%hhd;%hhd;%hhd",
           &tmp.year, &tmp.month, &tmp.day, &tmp.hour, &tmp.minutes, &tmp.temp);
    // is buf not valid
    if (ret != 6) continue;
    add_record(this, tmp);
  }
  fclose(fd);
  return 1;
}

int show_year_stats(sensor_stats_t *this) {

  HEADEARTABLE();

  int curr_year = -1;
  int curr_month = -1;
  int curr_counter = 0;
  int month_avg = 0;
  int month_max = INT_MIN;
  int month_min = INT_MAX;

  double year_avg = 0;
  int year_max = INT_MIN;
  int year_min = INT_MAX;
  for (int i = 0; i < this->len; i++) {
    if (this->stats[i].month != curr_month) {
      if (curr_month != -1) {
        BODYTABLE(curr_year, curr_month, curr_counter, (double)month_avg/(double)curr_counter, month_max, month_min);
        year_avg += (double)month_avg/(double)curr_counter;
        UPDATEMAX(year_max, month_max);
        UPDATEMIN(year_min, month_min);
      }
      curr_year = this->stats[i].year;
      curr_month = this->stats[i].month;
      curr_counter = 0;
      month_avg = 0;
      month_max = INT_MIN;
      month_min = INT_MAX;
    }

    curr_counter++;
    month_avg += this->stats[i].temp;
    UPDATEMAX(month_max, this->stats[i].temp);
    UPDATEMIN(month_min, this->stats[i].temp);
  }

  // последний месяц, в цикле мы его не захватываем
  BODYTABLE(curr_year, curr_month, curr_counter, (double)month_avg/(double)curr_counter, month_max, month_min);
  // последний месяц может изменить год ;)
  year_avg += (double)month_avg/(double)curr_counter;
  UPDATEMAX(year_max, month_max);
  UPDATEMIN(year_min, month_min);

  FOOTER();
  printf("Year statistic: average is %f, max temp is %d, min temp is %d\n", year_avg/(double)12, year_max, year_min);
}

void show_month_stats(sensor_stats_t *this, uint8_t month) {
  int curr_counter = 0;
  int month_avg = 0;
  int month_max = INT_MIN;
  int month_min = INT_MAX;
  int flag = 0;
  int i = 0;
  for (i = 0; i < this->len; i++) {
    if (flag && this->stats[i].month != month) {
      break;
    }
    if (this->stats[i].month == month) {
      curr_counter++;
      month_avg += this->stats[i].temp;
      UPDATEMAX(month_max, this->stats[i].temp);
      UPDATEMIN(month_min, this->stats[i].temp);
      flag = 1;
    }
  }

  HEADEARTABLE();
  BODYTABLE(this->stats[i].year, month, curr_counter, (double)month_avg/(double)curr_counter, month_max, month_min);
  FOOTER();
}
