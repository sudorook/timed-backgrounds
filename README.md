# Backgrounds

This is a set of timed backgrounds that change during the day. Only tested on
Cinnamon and GNOME desktop environments, but will work with any other desktop
environment that supports `gnome-backgrounds`.

Available backgrounds:
 * Island (by [arsenixc](https://arsenixc.deviantart.com/gallery/))
 * Firewatch (by [Campo Santo](https://blog.camposanto.com/post/138965082204/firewatch-launch-wallpaper-when-we-redid-the) and [\_felics](https://www.reddit.com/r/Firewatch/comments/458ohf/i_made_a_night_version_of_the_launch_wallpaper/))

Will add autotools installation later. For now, install by:

```
git clone https://github.com/pseudorook/extra-backgrounds
cd extra-backgrounds
sudo cp -r backgrounds/*.jpg /usr/share/backgrounds/gnome/
sudo cp -r backgrounds/*.xml /usr/share/gnome-background-properties/
```

For GNOME, use the "Backgrounds" app in GNOME to pick a background.

For Cinnamon, the background selection app doesn't show timed backgrounds. Set
them manually via dcont instead. In the terminal, run:

```
dconf write /org/cinnamon/desktop/background/picture-uri "'file:///usr/share/backgrounds/extra/island-timed.xml'"
```

Replace `island-timed.xml` with the any other available background XML file.


## Editing Notes

For gnome-backgrounds, backgrounds are installed in
`/usr/share/backgrounds/gnome` but can also be installed in
`/usr/local/share/backgrounds/gnome`. The metadata (specified in various XML
files) needed to make backgrounds show up in selection menus is found in
`/usr/share/gnome-background-properties`.
