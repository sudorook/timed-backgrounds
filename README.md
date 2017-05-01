# Backgrounds

This is a set of timed backgrounds that change during the day. Backgrounds: 
 * Island (by [arsenixc](https://arsenixc.deviantart.com/gallery/))
 * Firewatch (by [Campo Santo](https://blog.camposanto.com/post/138965082204/firewatch-launch-wallpaper-when-we-redid-the) and [\_felics](https://www.reddit.com/r/Firewatch/comments/458ohf/i_made_a_night_version_of_the_launch_wallpaper/))

Will add autotools installation later. For now, install by:

```
git clone https://github.com/pseudorook/backgrounds
sudo cp -r backgrounds /usr/share/backgrounds/extra
```

To set the background in Cinnamon: 
```
dconf write /org/cinnamon/desktop/background/picture-uri "'file:///usr/share/backgrounds/extra/firewatch-timed.xml'"
```

Replace `firewatch-timed.xml` with the desired option.
