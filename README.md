# Timed Backgrounds

This is a set of timed backgrounds that change during the day. Only tested on
Cinnamon and GNOME desktop environments, but will work with any other desktop
environment that supports `gnome-backgrounds`.

Available backgrounds:
 * Island (by [arsenixc](https://arsenixc.deviantart.com/gallery/))
 * Firewatch (by [Campo Santo](https://blog.camposanto.com/post/138965082204/firewatch-launch-wallpaper-when-we-redid-the) and [\_felics](https://www.reddit.com/r/Firewatch/comments/458ohf/i_made_a_night_version_of_the_launch_wallpaper/))
 * Metropolis (by [???](https://imgur.com/a/JH7RJ#2))
 * Mountainside (by [???](https://imgur.com/a/vqb7Q))


## Installation

Run:
```
git clone https://github.com/pseudorook/timed-backgrounds
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


### GNOME

To select a wallpaper in GNOME, use "Backgrounds" in "System Settings".


### Cinnamon

For Cinnamon, the background selection app doesn't show timed backgrounds. Set
one manually with dconf. In the command line, run:

```
dconf write /org/cinnamon/desktop/background/picture-uri "'file:///usr/share/backgrounds/timed/island-timed.xml'"
```

Replace `island-timed.xml` with the any other available background XML file.

> Note: By default, Cinnamon looks for files in
`/usr/share/cinnamon-background-properties/`, but some distros (such as Arch)
patch it to look in `/usr/share/gnome-background-properties/` instead.


### MATE

**Untested** Background metadata is installed in
`/usr/share/mate-background-properties`. If they cannot be selected via the
mate background app, you will need to use dconf to select one manually.
