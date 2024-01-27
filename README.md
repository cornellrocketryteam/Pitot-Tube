# Pitot-Tube
Data logging software for the pitot tube on the 2023/2024 competition rocket.


## Getting Started
### Dependencies Required
* ```cmake```
* ```gcc-arm-embedded``` (for macOS)
* ```gcc-arm-none-eabi``` (for Linux)
  
### Setup
* Install the required dependencies
* Run ```git submodule update --init``` from within ```lib/```
* Run ```git submodule update --init``` from within ```lib/pico-sdk/```

## Running
1. Create a top-level ```build/``` directory
2. Run ```cmake ..``` from within ```build/```
3. Run ```make```
4. Move ```pts.uf2``` to a Pico in boot select mode
