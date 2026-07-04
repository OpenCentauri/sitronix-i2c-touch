#!/bin/sh
# Poll Sitronix TS registers on stock CC2
source /kip/profile-kipware.sh 2>/dev/null || true
BUS=2
ADDR=0x55
REGS="0x01 0x02 0x03 0x04 0x05 0x06 0x0c 0x0d 0x0e 0x0f 0x10 0x3e 0x3f 0xf4 0xf5 0xf6"

echo "=== Sitronix register poll ==="
echo "PATH=$PATH"
echo "Start: $(date)"
echo "i2cget=$(which i2cget 2>/dev/null || echo 'NOT FOUND')"

for i in $(seq 1 30); do
  printf "t=%02d " "$i"
  for r in $REGS; do
    v=$(i2cget -f -y $BUS $ADDR $r 2>/dev/null || echo "--")
    printf "%s=%s " "$r" "$v"
  done
  printf "\n"
  sleep 0.2
done

echo "End: $(date)"
