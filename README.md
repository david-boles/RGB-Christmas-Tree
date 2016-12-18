# RGB-Christmas-Tree
The codebase for my RGB IOT christmas tree.

# Repo
This is currently under heavy development in the dev branch. Master should stay relatively bug free but I won't be doing extensive documentation or even commenting for the time being.

# Software
This is written in Arduino using the ESP8266 community core and Adafruit's neopixel library, you'll need to install those yourself.

# Hardware
This is currently using a 450 neopixel strip with the top 30 inside of a decorative angel. I'm running it on a NodeMCU v1.0 with power taps from the LEDs going to Vin and GND and D1 going to the LEDs' data input. Power is coming from an old ATX PSU with PS_ON shorted to ground. I would recommend something that beefy but with a slightly higher voltage (up to ~ 5.5) or running power to the end of the strip because on high loads I get some glitches in the upper LEDs.
