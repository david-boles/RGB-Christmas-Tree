# RGB-Christmas-Tree
The codebase for my [RGB IOT christmas tree](https://www.youtube.com/watch?v=rQdXf35lHvQ).

This is hacky and bad. I just pull it out once a year for kicks.

# Software
This is written in Arduino using the ESP8266 community core and Adafruit's neopixel library, you'll need to install those yourself. You can control the tree by connecting to RGB_Tree and navigating to 192.168.4.1/control. That page uses /set?=\<animation_num\> and has a link to /update for updating the code (Sketch -> Export compiled Binary in Arduino).

# Hardware
This is currently using a 450 neopixel strip all on the tree but the code supports having a top portion of the strip in something decorative (e.g. a star or an angel). I'm running it on a NodeMCU v1.0 with power taps from the LEDs going to Vin and GND and D1 going to the LEDs' data input. Power is coming from a beefy 5V (laptop?) PSU. I would recommend something similar but with a slightly higher voltage (up to ~ 5.5) or running power to the end of the strip because on high loads I get some glitches in the upper LEDs.
