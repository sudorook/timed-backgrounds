// SPDX-FileCopyrightText: 2010 - 2014 Jon Lund Steffensen <jonlst@gmail.com>
// SPDX-FileCopyrightText: 2019 sudorook <daemon@nullcodon.com>
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program. If not, see <https://www.gnu.org/licenses/>.

#include <stdio.h>
#include <unistd.h>

#if _POSIX_TIMERS > 0
#include <time.h>
#else
#include <sys/time.h>
#include <time.h>
#endif

#include "systemtime.h"

/* Return current time in T as the number of seconds since the epoch. */
int
systemtime_get_time(double* t)
{
#if _POSIX_TIMERS > 0 /* POSIX timers */
  struct timespec now;
  int r = clock_gettime(CLOCK_REALTIME, &now);
  if (r < 0) {
    perror("clock_gettime");
    return -1;
  }

  *t = now.tv_sec + (now.tv_nsec / 1000000000.0);
#else /* other platforms */
  struct timeval now;
  int r = gettimeofday(&now, NULL);
  if (r < 0) {
    perror("gettimeofday");
    return -1;
  }

  *t = now.tv_sec + (now.tv_usec / 1000000.0);
#endif

  return 0;
}

/* Sleep for a number of milliseconds. */
void
systemtime_msleep(unsigned int msecs)
{
  struct timespec sleep;
  sleep.tv_sec = msecs / 1000;
  sleep.tv_nsec = (msecs % 1000) * 1000000;
  nanosleep(&sleep, NULL);
}
