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

#ifndef REDSHIFT_PIPEUTILS_H
#define REDSHIFT_PIPEUTILS_H

int
pipeutils_create_nonblocking(int pipefds[2]);

void
pipeutils_signal(int write_fd);
void
pipeutils_handle_signal(int read_fd);

#endif /* ! REDSHIFT_PIPEUTILS_H */
