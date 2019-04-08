#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/* Location */
typedef struct
{
  float lat;
  float lon;
} location_t;

typedef struct location_state location_state_t;

typedef int
location_provider_init_func(location_state_t** state);
typedef int
location_provider_start_func(location_state_t* state);
typedef void
location_provider_free_func(location_state_t* state);
typedef void
location_provider_print_help_func(FILE* f);
typedef int
location_provider_set_option_func(location_state_t* state,
                                  const char* key,
                                  const char* value);
typedef int
location_provider_get_fd_func(location_state_t* state);
typedef int
location_provider_handle_func(location_state_t* state,
                              location_t* location,
                              int* available);

typedef struct
{
  char* name;

  /* Initialize state. Options can be set between init and start. */
  location_provider_init_func* init;
  /* Allocate storage and make connections that depend on options. */
  location_provider_start_func* start;
  /* Free all allocated storage and close connections. */
  location_provider_free_func* free;

  /* Print help on options for this location provider. */
  location_provider_print_help_func* print_help;
  /* Set an option key, value-pair. */
  location_provider_set_option_func* set_option;

  /* Listen and handle location updates. */
  location_provider_get_fd_func* get_fd;
  location_provider_handle_func* handle;
} location_provider_t;

typedef enum
{
  DAY_NIGHT = 0,
  DAY_SUNSET_NIGHT
} transition_mode_t;

#endif
