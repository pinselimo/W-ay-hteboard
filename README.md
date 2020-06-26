# W(ay)hteboard

Lacking a simple whiteboard app for stylus input supporting HiDPI on Wayland/Sway, I created my own.
All the code for the drawing capabilities is actually taken from the ![GNOME Control Center](https://gitlab.gnome.org/GNOME/gnome-control-center)'s wacom testing pane. My code only wraps it in a window and adds the capability to save the drawn masterpiece to ```.png```.

## Keyboard shortcuts

Since I'm mostly on Sway, I added two keyboard shortcuts:
+ ```CTRL + L``` moves the focus to the title bar so one can add a filename. 
+ ```CTRL + S``` saves the picture.

## Build

Building this app can be done with ```meson``` and ```ninja```:

~~~bash
$ git clone https://github.com/pinselimo/W-ay-hteboard.git
$ cd W-ay-hteboard
$ meson build && cd build
$ ninja
~~~

## LICENSE

GPLv3 (the code taken from the GNOME Control Center is originally GPLv2)

