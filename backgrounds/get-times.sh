#! /bin/bash
set -eu

#
# Parse timezone to find the current location, and then use it to find the
# corresponding map coordinates via the google maps api.
#

timezone=$(timedatectl status | sed -e "s/^[[:space:]]*//g" | grep "Time zone" | cut -d" " -f3)
location=$(echo $timezone | cut -d"/" -f2)
json=$(curl "https://nominatim.openstreetmap.org/search?format=json&city=${location}")

latitude=$(echo $json | jq -r '.[0].lat')
longitude=$(echo $json | jq -r '.[0].lon')


#
# Use the location latitude/longitude to query the sunrise-sunset.org api to
# get the current day cycle timings. Results are in UTC and must be converted
# to the current time zone.
#

json=$(curl "https://api.sunrise-sunset.org/json?lat=${latitude}&lng=${longitude}&date=$(date +%F)&formatted=0")

sunrise=$(echo ${json} | jq -r '.results["sunrise"]' | { read time; TZ=$timezone date -d "$time"; })
sunset=$(echo ${json} | jq -r '.results["sunset"]' | { read time; TZ=$timezone date -d "$time"; })
solar_noon=$(echo ${json} | jq -r '.results["solar_noon"]' | { read time; TZ=$timezone date -d "$time"; })
day_length=$(echo ${json} | jq -r '.results["day_length"]')
civil_twilight_begin=$(echo ${json} | jq -r '.results["civil_twilight_begin"]' | { read time; TZ=$timezone date -d "$time"; })
civil_twilight_end=$(echo ${json} | jq -r '.results["civil_twilight_end"]' | { read time; TZ=$timezone date -d "$time"; })
nautical_twilight_begin=$(echo ${json} | jq -r '.results["nautical_twilight_begin"]' | { read time; TZ=$timezone date -d "$time"; })
nautical_twilight_end=$(echo ${json} | jq -r '.results["nautical_twilight_end"]' | { read time; TZ=$timezone date -d "$time"; })
astronomical_twilight_begin=$(echo ${json} | jq -r '.results["astronomical_twilight_begin"]' | { read time; TZ=$timezone date -d "$time"; })
astronomical_twilight_end=$(echo ${json} | jq -r '.results["astronomical_twilight_end"]' | { read time; TZ=$timezone date -d "$time"; })

echo sunrise=\"$sunrise\"
echo sunset=\"$sunset\"
echo solar_noon=\"$solar_noon\"
echo day_length=$day_length
echo civil_twilight_begin=\"$civil_twilight_begin\"
echo civil_twilight_end=\"$civil_twilight_end\"
echo nautical_twilight_begin=\"$nautical_twilight_begin\"
echo nautical_twilight_end=\"$nautical_twilight_end\"
echo astronomical_twilight_begin=\"$astronomical_twilight_begin\"
echo astronomical_twilight_end=\"$astronomical_twilight_end\"
