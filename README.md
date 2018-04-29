# Timed Backgrounds

**Build Requirements:** autotools, curl, jq

This is a set of timed backgrounds that change during the day. The time
transitions are calculated by using the Google Maps API to get the latitude and
longitude of the user's time zone, which are then used to query the
sunrise-sunset.org API to get current times for sunrise/sunset. 

Only tested on Cinnamon and GNOME desktop environments, but will work with any
other desktop environment that supports `gnome-backgrounds`.

Available backgrounds:
 * Firewatch (by [Campo Santo](https://blog.camposanto.com/post/138965082204/firewatch-launch-wallpaper-when-we-redid-the) and [\_felics](https://www.reddit.com/r/Firewatch/comments/458ohf/i_made_a_night_version_of_the_launch_wallpaper/))
 * Island (by [arsenixc](https://arsenixc.deviantart.com/gallery/))
 * Metropolis (by [???](https://imgur.com/a/JH7RJ#2))
 * Mountainside (by [???](https://imgur.com/a/vqb7Q))


## Installation

Run:
```
git clone https://github.com/sudorook/timed-backgrounds.git
cd timed-backgrounds
./autogen.sh
make
sudo make install
```

The backgrounds will be installed in `/usr/share/backgrounds/timed` and the
relevant metadata in `/usr/share/gnome-background-properties`,
`/usr/share/cinnamon-background-properties`, and
`/usr/share/mate-background-properties`.

Uninstall by running `sudo make uninstall`.

**Note:** Times for sunrise and sunset vary throughout the year due to the tilt
in Earth's axis. Rebuild and reinstall this periodically so that the background
transition times more-or-less match real-world day/night cycles.

To rebuild and reinstall, run:
```
make clean
make
sudo make install
```


### GNOME

To select a wallpaper in GNOME, use "Backgrounds" in "System Settings".


### Cinnamon

For Cinnamon, the background selection app doesn't show timed backgrounds. Set
one manually with dconf. In the command line, run:

```
dconf write /org/cinnamon/desktop/background/picture-uri "'file:///usr/share/backgrounds/timed/island-timed.xml'"
```

Replace `island-timed.xml` with the any other available background XML file.

> Note: By default, Cinnamon looks for the timed.xml file (which contains a
> list of all the aviailable backgrounds) in
> `/usr/share/cinnamon-background-properties/`, but some distros (such as Arch)
> patch it to look in `/usr/share/gnome-background-properties/` instead.


### MATE (Untested)

Background metadata is installed in `/usr/share/mate-background-properties`. If
they cannot be selected via the mate background app, you will need to use dconf
to select one manually. See the above instructions for Cinnamon.
