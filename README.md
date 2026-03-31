# Arduino---StopStepFullTwoDirections
# StopStepFullTwoDirections

An Arduino-based control-logic example using 5 buttons to drive latched and momentary outputs for two directions.

Originally created as part of testing logic for a motion-platform / stepper-motor project using NEMA 17 and Easy Driver hardware.

Although this project was built for Arduino, the core input/output logic can also be adapted to other Arduino-compatible or similar microcontroller platforms.

I intend to show this XYZ Platform on YouTube Channel: www.youtube.com/channel/UC5GQda77WExalrXs8D76sPA

I do use a Breadboard extender (my term, others probably would call them breadboard widgets). The details of those boards can be found on Hack-A-Day: https://hackaday.io/project/9305-breadboard-extenders

Of the 5 buttons used by the code: 

Pin 6 Button : LED Pin 8 will be Latched on, and LED Pin 11 will be latched on to indicate Full On Mode in Direction B is on.

Pin 5 Button : LED Pin 8 will be on while the button is pressed (momentary), and LED Pin 11 will be off to indicate Full On Mode in Direction B is off.

Pin 4 Button : Will turn all LEDs off.

Pin 3 Button : LED Pin 7 will be on while the button is pressed (momentary), and LED Pin 10 will be off to indicate Full On Mode in Direction A is off.

Pin 2 Button : LED Pin 7 will be Latched on, and LED Pin 10 will be latched on to indicate Full On Mode in Direction A is on.


