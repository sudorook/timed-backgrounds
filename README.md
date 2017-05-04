# Backgrounds

This is a set of timed backgrounds that change during the day. Only tested on
Cinnamon and GNOME desktop environments, but it probably works for others, too.

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

To set a background in Cinnamon:
```
dconf write /org/cinnamon/desktop/background/picture-uri "'file:///usr/share/backgrounds/extra/firewatch-timed.xml'"
```

Replace `firewatch-timed.xml` with the desired option.
