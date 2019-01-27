# Arduino---StopStepFullTwoDirections
This Arduino program is just some coded up logic that turns on a couple of LEDs based on which of 5 buttons have been pushed.

I will be using this code in another Arduino project that I will use to control / test a NEMA 17 stepper moter using the easy driver stepper motor control boards.

I am doing this just to test a XYZ motion platfom I am working on as described on Hack-A-Day: https://hackaday.io/project/9349-xyz-repeatable-platform

I intend to show this XYZ Platform on YouTube Channel: www.youtube.com/channel/UC5GQda77WExalrXs8D76sPA

I do use a Breadboard extender (my term, others probably would call them breadboard widgets). The details of those boards can be found on Hack-A-Day:

Of the 5 buttons used by the code: https://hackaday.io/project/9305-breadboard-extenders

Pin 6 Button : LED Pin 8 will be Latched on, and LED Pin 11 will be latched on to indicate Full On Mode in Direction B is on.

Pin 5 Button : LED Pin 8 will be on while the button is pressed (momentary), and LED Pin 11 will be off to indicate Full On Mode in Direction B is off.

Pin 4 Button : Will turn all LEDs off.

Pin 3 Button : LED Pin 7 will be on while the button is pressed (momentary), and LED Pin 10 will be off to indicate Full On Mode in Direction A is off.

Pin 2 Button : LED Pin 7 will be Latched on, and LED Pin 10 will be latched on to indicate Full On Mode in Direction A is on.


