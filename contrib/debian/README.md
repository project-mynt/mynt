
Debian
====================
This directory contains files used to package myntd/mynt-qt
for Debian-based Linux systems. If you compile myntd/mynt-qt yourself, there are some useful files here.

## mynt: URI support ##


mynt-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install mynt-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your mynt-qt binary to `/usr/bin`
and the `../../share/pixmaps/mynt128.png` to `/usr/share/pixmaps`

mynt-qt.protocol (KDE)

