## ReBootboX (RBX) is a Kludge to Remotely Power-Cycle Seismic Stations using Sierra 3G Modems

Currently the RBX is purpose-built for Anne Sheehan et al.'s [Weld County Seismic Experiment](https://cires.colorado.edu/news/preventing-human-caused-earthquakes) to save us from having to drive four hours round-trip just to power-cycle our stations whenever there's a telemetry dropout. 

This particular mode of telemetry failure appears to have vexed many operators of telemetered arrays using RT130 loggers, AirLink modems and an RTPD server. This failure mode is characterized, frustratingly, by the loss of a station's RTP connection despite its modem remaining online. 

I have yet to discover a better fix than merely power-cycling the offending station, which appears to have been the standard remedy for [quite some time](https://geohazards.usgs.gov/pipermail/anss-netops/2011-November/000209.html). Because the modem remains accessible during these failures, you can spare yourself an annoying drive by exploiting it to power-cycle your station remotely. The RBX is a cheap and simple example of such a solution.       

The [User Guide](https://github.com/bugoutput/ReBootboX/blob/master/rbxuserguidev0.pdf) contains a basic overview of the RBX and how to control it remotely through your Sierra/AirLink modem's serial port. 

The (extremely basic) Arduino [source code](https://github.com/bugoutput/ReBootboX/blob/master/RBX_v0.ino) was hacked together using demo code for the SoftwareSerial library and the RS232 shield we used to talk with the modem. 

The unit cost for the device as shown is $30, sourcing all parts from Amazon Prime.

### The RBX's BoM is pretty simple: 
-Arduino Uno R3 or cheap clone

-Max232 driver breakout board or serial shield

-Relay module capable of normally-closed (NC) operational state, so that your station won't die if the RBX does

-Enclosure of some kind

-Null-Modem serial cable with all flow control lines lifted ("data-only"). Just build your own. It's easier than finding one of these online.


![Image](https://github.com/bugoutput/ReBootboX/blob/master/rebootBox.jpg)





## This is about the most rudimentary Arduino application you can imagine: 


![Image](https://github.com/bugoutput/ReBootboX/blob/master/rbxoverview.png)


The one difficult part was compelling our Raven Xs to properly forward our remote hex commands out their serial port. See user guide for the configuration that worked for us.   
