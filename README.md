# MOS Entertainment System

An NES emulator. 

## Very early, very subject to change project structure

### `include`
Public interface for the emulator core to be used by platform-specific implementations.

### `/src/emu`
Home of the core emulator functionality.

### `/src/moses-pc`
PC-specific code for the initial implementation (e.g. display, input handling) via a to-be-determined display library. 
This is to enable cross-platform development in the future.

### `/tests`
Code will be tested.