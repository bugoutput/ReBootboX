## ReBootboX (RBX) is a Kludge to Remotely Power-Cycle Seismic Stations using Sierra 3G Modems

Currently the RBX is purpose-built for Anne Sheehan et al.'s [Weld County Seismic Experiment](https://cires.colorado.edu/news/preventing-human-caused-earthquakes) to save us from having to drive four hours round-trip just to power-cycle our stations whenever there's a telemetry dropout. 

This particular mode of telemetry failure appears to have vexed many other operators of telemetered seismic arrays using RT130 loggers, AirLink modems and an RTPD server. This failure mode is characterized by the 3G modem remaining online while the RTP connection to the RT130 has been lost. Presumably some initial cell service outage triggers this situation, from which the modem eventually recovers but the RTP connection does not. 

I have yet to find a better solution than power-cycling the station, which appears to have been the standard fix for [quite some time](https://geohazards.usgs.gov/pipermail/anss-netops/2011-November/000209.html). Since the modem typically remains accessible remotely during these failures, you can save yourself an annoying drive by using your modem's serial port to trigger a relay which power-cycles the station for you. The RBX is a cheap and simple example of such a device.       

The [User Guide](https://github.com/bugoutput/ReBootboX/blob/master/rbxuserguidev0.pdf) contains a basic overview of the RBX system and how to control it remotely through your 3G modem's serial port. 

The (extremely basic) Arduino [source code](https://github.com/bugoutput/ReBootboX/blob/master/RBX_v0.ino) is hacked together from demo code for the SoftwareSerial library and the RS232 shield we use to talk with the modem. 

The unit cost for the device as shown is $30, sourcing all parts from Amazon Prime.

### The RBX's BoM is pretty simple: 
-Arduino Uno R3 or cheap clone

-Max232 driver breakout board or serial shield

-Relay module capable of normally-closed (NC) operational state, so that your station won't die if the RBX does

-Enclosure of some kind

-Null-Modem serial cable with all flow control lines lifted ("data-only"). Just build your own, it's easier than finding one of these online.


![Image](https://github.com/bugoutput/ReBootboX/blob/master/rebootBox.jpg)

### This is about the most rudimentary Arduino application you can imagine: 


![Image](https://github.com/bugoutput/ReBootboX/blob/master/rbxoverview.png)

The only difficult part was getting our Raven X's to properly forward hex commands out their serial port. (see user guide for the configuration that worked for us)   
