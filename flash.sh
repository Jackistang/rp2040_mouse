#!/bin/bash

./tools/openocd/src/openocd -f interface/picoprobe.cfg -f target/rp2040.cfg -s ./tools/openocd/tcl -c "program $1 verify reset exit"