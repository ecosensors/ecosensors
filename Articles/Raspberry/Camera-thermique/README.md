# Utilisation d’une camera thermique

Dans cet article je vais brièvement vous montrer comment j'ai configuré une camera thermique ARG8833 avec un Rasberry Pi 4 et un display PiTFT 3.5″ resistive touch (320×480)

> [Edit 09.2024] Cet article est à revoir entièrement
> Cet article est un aide-mémoire. 

Nous partons dans le principe que vous savez et avez (ré)installé l'OS de votre Raspberry. J'ai écris des articles à ce sujet.

**Attention, dans le cadre de cette exercice, ne supprimer pas le compte pi.**

## Préparation de votre Rasberry

Il vous faudra encore faire les mises à jour et installer git (et vim et ntpdate, si ce n’est pas fait)

```
sudo apt-get update 
sudo apt-get upgrade 
sudo apt-get install vim ntpdate 
sudo apt-get install git
```

## Installation de l’écran PiTFT 3.5″ resistive touch (320×480)

*Références: https://learn.adafruit.com/adafruit-pitft-3-dot-5-touch-screen-for-raspberry-pi?view=all , 
https://learn.adafruit.com/circuitpython-on-raspberrypi-linux/installing-circuitpython-on-raspberry-pi*

```
cd ~
sudo apt-get install -y git python3-pip
sudo pip3 install --upgrade adafruit-python-shell click
git clone https://github.com/adafruit/Raspberry-Pi-Installer-Scripts.git
cd Raspberry-Pi-Installer-Scripts
sudo python3 adafruit-pitft.py --display=35r --rotation=90 --install-type=fbcp
```

Redémarrer votre Raspberry et votre écran fonctionnera

> Il faudrait mettre à jour cet article. Je le conserve afin de conserver ce qui a été fait le temps que je le refasse.

```
Select configuration:
1. PiTFT 2.4", 2.8" or 3.2" resistive (240x320)
2. PiTFT 2.2" no touch (240x320)
3. PiTFT 2.8" capacitive touch (240x320)
4. PiTFT 3.5" resistive touch (320x480)
5. Quit without installing

SELECT 1-5: 4
Select rotation:
1. 90 degrees (landscape)
2. 180 degrees (portait)
3. 270 degrees (landscape)
4. 0 degrees (portait)

SELECT 1-4: 1
[PITFT] Checking init system...
Found systemd
/boot is mounted
[PITFT] System update
Updating apt indexes...
.........
Reading package lists...
.........
[PITFT] Installing Python libraries & Software...
Installing Pre-requisite Software...This may take a few minutes!
[PITFT] Updating /boot/config.txt...
[PITFT] Updating SysFS rules for Touchscreen...
[PITFT] Updating TSLib default calibration...
Would you like the console to appear on the PiTFT display? [y/n] n
[PITFT] Making sure console doesn't use PiTFT
Removing console fbcon map from /boot/cmdline.txt
Screen blanking time reset to 10 minutes
Would you like the HDMI display to mirror to the PiTFT display? [y/n] y
[PITFT] Adding FBCP support...
Installing cmake...
W: --force-yes is deprecated, use one of the options starting with --allow instead.
Downloading rpi-fbcp...
Uncompressing rpi-fbcp...
Building rpi-fbcp...
Installing rpi-fbcp...
Remove fbcp from /etc/rc.local, if it's there...
We have systemd, so install fbcp systemd unit...
Created symlink /etc/systemd/system/multi-user.target.wants/fbcp.service → /etc/systemd/system/fbcp.service.
Setting raspi-config to boot to desktop w/o login...
Created symlink /etc/systemd/system/default.target → /lib/systemd/system/graphical.target.
Configuring boot/config.txt for forced HDMI
Using x1.5 resolution
[PITFT] Updating X11 default calibration...
[PITFT] Success!

Settings take effect on next boot.

REBOOT NOW? [y/N] y
```

## Installation de la camera thermique

https://learn.adafruit.com/adafruit-amg8833-8×8-thermal-camera-sensor/raspberry-pi-thermal-camera

Vin à la broche t3V ou 5V
GND à la broche GND
SDA  à la broche o SDA
SCL à la broche  SCL

Contrôler les connections:

```
sudo i2cdetect -y 1
```

Ce qui devrait afficher

```
0 1 2 3 4 5 6 7 8 9 a b c d e f 
00: -- -- -- -- -- -- -- -- -- -- -- -- -- 
10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
40: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
60: -- -- -- -- -- -- -- -- -- 69 --
69 -- -- -- -- -- -- 
70: -- -- -- -- -- -- -- --
```

### Installation des softs

[Documentation](https://eco-sensors.ch/wp-content/uploads/2018/12/adafruit-amg8833-8x8-thermal-camera-sensor.pdf) | https://learn.adafruit.com/adafruit-amg8833-8×8-thermal-camera-sensor/raspberry-pi-thermal-camera

```
sudo apt-get install libatlas-base-dev
sudo pip3 install adafruit-circuitpython-amg88xx
sudo apt-get install -y python3-scipy python3-pygame
sudo pip3 install colour
```

## Le script
Créer le script

```
sudo nano /home/pi/thermcam.py
```

Avec le script d’adafruit

```
# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
# SPDX-License-Identifier: MIT

"""This example is for Raspberry Pi (Linux) only!
   It will not work on microcontrollers running CircuitPython!"""

import os
import math
import time

import numpy as np
import pygame
import busio
import board

from scipy.interpolate import griddata

from colour import Color

import adafruit_amg88xx

i2c_bus = busio.I2C(board.SCL, board.SDA)

# low range of the sensor (this will be blue on the screen)
MINTEMP = 15.0

# high range of the sensor (this will be red on the screen)
MAXTEMP = 28.0

# how many color values we can have
COLORDEPTH = 1024

os.putenv("SDL_FBDEV", "/dev/fb1")
# pylint: disable=no-member
pygame.init()
# pylint: enable=no-member

# initialize the sensor
sensor = adafruit_amg88xx.AMG88XX(i2c_bus)

# pylint: disable=invalid-slice-index
points = [(math.floor(ix / 8), (ix % 8)) for ix in range(0, 64)]
grid_x, grid_y = np.mgrid[0:7:32j, 0:7:32j]
# pylint: enable=invalid-slice-index

# sensor is an 8x8 grid so lets do a square
height = 400
width = 400

# the list of colors we can choose from
blue = Color("indigo")
colors = list(blue.range_to(Color("red"), COLORDEPTH))

# create the array of colors
colors = [(int(c.red * 255), int(c.green * 255), int(c.blue * 255)) for c in colors]

displayPixelWidth = width / 30
displayPixelHeight = height / 30

lcd = pygame.display.set_mode((width, height))

lcd.fill((255, 0, 0))

pygame.display.update()
pygame.mouse.set_visible(False)

lcd.fill((0, 0, 0))
pygame.display.update()

# some utility functions
def constrain(val, min_val, max_val):
	return min(max_val, max(min_val, val))


def map_value(x, in_min, in_max, out_min, out_max):
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min


# let the sensor initialize
time.sleep(0.1)

while True:
	# read the pixels
	pixels = []
	for row in sensor.pixels:
		pixels = pixels + row
	pixels = [map_value(p, MINTEMP, MAXTEMP, 0, COLORDEPTH - 1) for p in pixels]

	# perform interpolation
	bicubic = griddata(points, pixels, (grid_x, grid_y), method="cubic")

	# draw everything
	for ix, row in enumerate(bicubic):
		for jx, pixel in enumerate(row):
			pygame.draw.rect(
				lcd,
				colors[constrain(int(pixel), 0, COLORDEPTH - 1)],
				(
					displayPixelHeight * ix,
					displayPixelWidth * jx,
					displayPixelHeight,
					displayPixelWidth,
				),
			)

	pygame.display.update()
```

Rendre le script exécutable et redémarrer votre Pi

```
sudo chmod +x /home/pi/thermcam.py
```

## Lancement du script au démarrage
Editez le fichier

```
sudo nano /etc/xdg/lxsession/LXDE-pi/autostart
```

et ajoutez

```
@lxpanel --profile LXDE-pi
@pcmanfm --desktop --profile LXDE-pi
@xscreensaver -no-splash
@python3 /home/pi/thermcam.py &
```

## Screenshot

Voici une solution simple pour faire des screenshots de l’image rendu par la caméra thermique

Installation de scrot

```
sudo apt install scrot
```

Création du script

```
sudo nano /home/pi/scrot.sh
```

et ajoutez les lignes

```
#!/bin/sh
LOCATION="$(date +/path/to/home/Pictures/shots/%Y/%m/%d)"
mkdir -p $LOCATION
cd $LOCATION
DISPLAY=:0 scrot '%Y-%m-%d-%H%M.jpg' -q 20
```

modification des permissions

```
chmod u+x /home/pi/scrot.sh
```

essayez

```
cd /home/pi/
./scrot.sh
```

## Prendre un screenshot toutes les 15mn
```
crontab -e
```

ajoutez la ligne

```
*/15 * * * 1-7 /home/pi/scrot.sh
```

Le fichier sera exécuté toutes les 15mn, du lundi au dimanche

## Discussion
https://forums.adafruit.com/viewtopic.php?f=50&t=143684&p=709531&hilit=raspberry+numpy#p709531

