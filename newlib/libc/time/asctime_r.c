/*
 * asctime_r.c
 */

#include <stdio.h>
#include <time.h>
#include "../machine/xtensa/pgmspace.h"

char *
_DEFUN (asctime_r, (tim_p, result),
	_CONST struct tm *__restrict tim_p _AND
	char *__restrict result)
{
  static _CONST char day_name[7][3] PROGMEM = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
  };
  static _CONST char mon_name[12][3] PROGMEM = {
	"Jan", "Feb", "Mar", "Apr", "May", "Jun", 
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
  };

  char day[3];
  memcpy_P(day, day_name, 3);
  char mon[3];
  memcpy_P(mon, mon_name, 3);

  siprintf (result, "%.3s %.3s%3d %.2d:%.2d:%.2d %d\n",
	    day, mon,
	    tim_p->tm_mday, tim_p->tm_hour, tim_p->tm_min,
	    tim_p->tm_sec, 1900 + tim_p->tm_year);
  return result;
}
