#ifndef TEMP_API_H
#define TEMP_API_H
#include <stdint.h>

typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minutes;
  int8_t temp;
} sensor_t;

typedef struct {
  sensor_t *stats;
  uint32_t len;
  uint32_t size;
} sensor_stats_t;

sensor_stats_t* constructor();
void destructor(sensor_stats_t *this);

int  get_records_from_file(sensor_stats_t *this, char *path_to_file);
int  show_year_stats(sensor_stats_t *this);
void show_month_stats(sensor_stats_t *this, uint8_t month);

#endif