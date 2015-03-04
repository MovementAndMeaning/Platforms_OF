yarp of empty project

expects YARP_DIR and ACE_ROOT to point to correct locations, and YARP libs to be compiled.

should compile when deployed in an oF apps directory using Visual Studio version of oF 0.8, as well as Xcode. MUST have the 32 bit compiled static libraries for YARP linked - may have to change the absolute path in the build settings as Xcode does not support $YARP_DIR.

example performs a simple register of a port, and will print received messages to screen similar to "yarp read"