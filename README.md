## ReBootboX (RBX) is a Kludge to Remotely Power-Cycle Seismic Stations using Sierra 3G Modems

Currently the RBX is purpose-built for Anne Sheehan et al.'s [Weld County Seismic Experiment](https://cires.colorado.edu/news/preventing-human-caused-earthquakes) to save us from having to drive four hours round-trip just to power-cycle our stations whenever there's a telemetry dropout. 

The [User Guide](https://github.com/bugoutput/ReBootboX/blob/master/rbxuserguidev0.pdf) contains a basic overview of the RBX system and how to talk to it over your 3G modem's serial port. 

The (extremely simple) Arduino [source code](https://github.com/bugoutput/ReBootboX/blob/master/RBX_v0.ino) is hacked together from demo code for the SoftwareSerial library and the RS232 shield we use to talk with the modem. The unit cost for the device as shown is $30, sourcing all parts from Amazon Prime.

### The RBX's BoM is pretty simple: 
-Arduino Uno R3 or cheap clone

-Max232 driver breakout board or serial shield

-Relay module capable of normally-closed (NC) operational state, so that your station won't die if the RBX does

-Enclosure of some kind

-Null-Modem serial cable with all flow control lines lifted ("data-only"). Just build your own, it's easier than finding one of these online.


![Image](https://github.com/bugoutput/ReBootboX/blob/master/rebootBox.jpg)
