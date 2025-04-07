# Epidemic-Simulation

This is a C program that simulates disease spread using the SIR model in a grid-based world.

## Features
- Hash-based lookup for efficient infection checking
- Linked lists for infected location tracking
- Modular code in multiple files

## Build & Run

```bash
make
./epidemic k m T N
```

Where:
- 'k' = grid radius (world is (2k+1)x(2k+1))
- 'm' = number of hosts
- 'T' = recovery time for infected hosts
- 'N' = number of hash buckets

Jay Patel
