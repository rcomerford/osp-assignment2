# 📂 OSP Assignment 2
Built by Ryan Comerford (s3945787)

## 🚧 Building
- Compile all using `make`.
- Compile only `fifo` using `make fifo`.
- Compile only `sjf` all using `make sjf`.
- Compile only `rr` all using `make rr`.
- Clean build files using `make clean`.

## 🔴 First-In-First-Out ("fifo")
``` bash
./fifo <datafile>
```

- datafile: the input file for pulling process details from.

## 🔵 Shortest Job First ("sjf")
``` bash
./sjf <datafile>
```

- datafile: the input file for pulling process details from.

## 🟢 Round Robin ("rr")
``` bash
./rr <quantum> <datafile>
```

- quantum: the time slice to use when running the round robin.
- datafile: the input file for pulling process details from.