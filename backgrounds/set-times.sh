#! /bin/bash
set -eu
source "times.txt"

#
# Use the times to calculate the duration of each phase for timed backgrounds.
#

mode=$(sed -n "s,[[:space:]]*<mode>\(.*\)</mode>,\1,p" ${1})
case ${mode} in
  day-night)
    start_offset=$(( $(sed -n "s,[[:space:]]*<hour>\(.*\)</hour>,\1,p" ${1}) * 3600 ))

    sunrise_half=$(( $(date -d "${sunrise}" +%s) - $(date -d "${nautical_twilight_begin}" +%s) ))
    sunset_half=$(( $(date -d "${nautical_twilight_end}" +%s) - $(date -d "${sunset}" +%s) ))

    sunrise_start=$(( $(date -d "${nautical_twilight_begin}" +%s) - $(date -d "0" +%s) - ${start_offset} ))
    # If the offset puts the starting time of the animation before sunrise,
    # decrement the starting <hour> so that sunrise occurs after the starting
    # time. Assumes the first part of the animation is night until sunrise.
    if (( $sunrise_start < 0 )); then
      offset=$(( (3600 - $sunrise_start) / 3600 ))
      start_offset=$(( $start_offset - (3600 * $offset) ))
      sed -i "s,<hour>.*</hour>,<hour>$(( $start_offset / 3600 ))</hour>,g" ${1}
      sunrise_start=$(( $(date -d "${nautical_twilight_begin}" +%s) - $(date -d "0" +%s) - ${start_offset} ))
    fi
    sunrise_end=$(( $(date -d "${sunrise}" +%s) - $(date -d "0" +%s) - ${start_offset} + ${sunrise_half} ))
    sunset_start=$(( $(date -d "${sunset}" +%s) - $(date -d "0" +%s) - ${start_offset} - ${sunset_half} ))
    sunset_end=$(( $(date -d "${nautical_twilight_end}" +%s) - $(date -d "0" +%s) - ${start_offset} ))

    sunrise_length=$(( $sunrise_end - $sunrise_start ))      # night -> day
    day_length=$(( ${sunset_start} - ${sunrise_end} ))       # day
    sunset_length=$(( $sunset_end - $sunset_start ))         # day -> night
    night_to_start=$(( 86400 - $sunrise_start - $sunrise_length - $day_length - $sunset_length ))

    sed -i "s/@starttosunrise@/${sunrise_start}.0/g" ${1}
    sed -i "s/@sunrise@/${sunrise_length}.0/g" ${1}
    sed -i "s/@day@/${day_length}.0/g" ${1}
    sed -i "s/@sunset@/${sunset_length}.0/g" ${1}
    sed -i "s/@nighttostart@/${night_to_start}.0/g" ${1}
    ;;
  day-sunset-night)
    start_offset=$(( $(sed -n "s,[[:space:]]*<hour>\(.*\)</hour>,\1,p" ${1}) * 3600 ))
    
    sunrise_half=$(( $(date -d "${sunrise}" +%s) - $(date -d "${nautical_twilight_begin}" +%s) ))
    sunset_half=$(( $(date -d "${nautical_twilight_end}" +%s) - $(date -d "${sunset}" +%s) ))

    sunrise_start=$(( $(date -d "${nautical_twilight_begin}" +%s) - $(date -d "0" +%s) - ${start_offset} ))
    # If the offset puts the starting time of the animation before sunrise,
    # decrement the starting <hour> so that sunrise occurs after the starting
    # time. Assumes the first part of the animation is night until sunrise.
    if (( $sunrise_start < 0 )); then
      offset=$(( (3600 - $sunrise_start) / 3600 ))
      start_offset=$(( $start_offset - (3600 * $offset) ))
      sed -i "s,<hour>.*</hour>,<hour>$(( $start_offset / 3600 ))</hour>,g" ${1}
      sunrise_start=$(( $(date -d "${nautical_twilight_begin}" +%s) - $(date -d "0" +%s) - ${start_offset} ))
    fi
    sunrise_end=$(( $(date -d "${sunrise}" +%s) - $(date -d "0" +%s) - ${start_offset} + ${sunrise_half} ))
    sunset_start=$(( $(date -d "${sunset}" +%s) - $(date -d "0" +%s) - ${start_offset} - ${sunset_half} ))
    sunset_end=$(( $(date -d "${sunset}" +%s) - $(date -d "0" +%s) - ${start_offset} ))
    nightfall_end=$(( $(date -d "${nautical_twilight_end}" +%s) - $(date -d "0" +%s) - ${start_offset} ))

    sunrise_length=$(( $sunrise_end - $sunrise_start ))                 # night -> day
    day_length=$(( ${sunset_start} - ${sunrise_end} ))                  # day
    sunset_length=$(( $sunset_end - $sunset_start ))                    # day -> sunset
    nightfall_length=$(( $nightfall_end - $sunset_end ))                # sunset -> nightfall
    night_to_start=$(( 86400 - $sunrise_start - $sunrise_length - $day_length - $sunset_length - $nightfall_length )) # night

    sed -i "s/@starttosunrise@/${sunrise_start}.0/g" ${1}
    sed -i "s/@sunrise@/${sunrise_length}.0/g" ${1}
    sed -i "s/@day@/${day_length}.0/g" ${1}
    sed -i "s/@sunset@/${sunset_length}.0/g" ${1}
    sed -i "s/@nightfall@/${sunset_length}.0/g" ${1}
    sed -i "s/@nighttostart@/${night_to_start}.0/g" ${1}
    ;;
  *)
    ;;
esac
