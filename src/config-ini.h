// SPDX-FileCopyrightText: 2010 Jon Lund Steffensen <jonlst@gmail.com>
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

#ifndef REDSHIFT_CONFIG_INI_H
#define REDSHIFT_CONFIG_INI_H

typedef struct _config_ini_section config_ini_section_t;
typedef struct _config_ini_setting config_ini_setting_t;

struct _config_ini_setting
{
  config_ini_setting_t* next;
  char* name;
  char* value;
};

struct _config_ini_section
{
  config_ini_section_t* next;
  char* name;
  config_ini_setting_t* settings;
};

typedef struct
{
  config_ini_section_t* sections;
} config_ini_state_t;

int
config_ini_init(config_ini_state_t* state, const char* filepath);
void
config_ini_free(config_ini_state_t* state);

config_ini_section_t*
config_ini_get_section(config_ini_state_t* state, const char* name);

#endif /* ! REDSHIFT_CONFIG_INI_H */
