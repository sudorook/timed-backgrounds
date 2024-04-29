// SPDX-FileCopyrightText: 2017 Jon Lund Steffensen <jonlst@gmail.com>
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

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/* Create non-blocking set of pipe fds. */
int
pipeutils_create_nonblocking(int pipefds[2])
{
  int r = pipe(pipefds);
  if (r == -1) {
    perror("pipe");
    return -1;
  }

  int flags = fcntl(pipefds[0], F_GETFL);
  if (flags == -1) {
    perror("fcntl");
    close(pipefds[0]);
    close(pipefds[1]);
    return -1;
  }

  r = fcntl(pipefds[0], F_SETFL, flags | O_NONBLOCK);
  if (r == -1) {
    perror("fcntl");
    close(pipefds[0]);
    close(pipefds[1]);
    return -1;
  }

  flags = fcntl(pipefds[1], F_GETFL);
  if (flags == -1) {
    perror("fcntl");
    close(pipefds[0]);
    close(pipefds[1]);
    return -1;
  }

  r = fcntl(pipefds[1], F_SETFL, flags | O_NONBLOCK);
  if (r == -1) {
    perror("fcntl");
    close(pipefds[0]);
    close(pipefds[1]);
    return -1;
  }

  return 0;
}

/* Signal on write-end of pipe. */
void
pipeutils_signal(int write_fd)
{
  write(write_fd, "", 1);
}

/* Mark signal as handled on read-end of pipe. */
void
pipeutils_handle_signal(int read_fd)
{
  char data;
  read(read_fd, &data, 1);
}
