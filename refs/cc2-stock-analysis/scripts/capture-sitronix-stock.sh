#!/bin/sh
# Capture Sitronix TS registers and input events on stock CC2
source /kip/profile-kipware.sh 2>/dev/null || true
BUS=2
ADDR=0x55
REGS="0x01 0x02 0x03 0x04 0x05 0x06 0x0c 0x0d 0x0e 0x0f 0x10 0x3e 0x3f 0xf4 0xf5 0xf6"

echo "=== Sitronix register + input capture ==="
echo "PATH=$PATH"
echo "Start: $(date)"
echo "i2cget=$(which i2cget 2>/dev/null || echo 'NOT FOUND')"
echo "evtest=$(which evtest 2>/dev/null || echo 'NOT FOUND')"

# Start input capture in background
capture_input() {
  local dev=$1
  if [ -r "$dev" ]; then
    timeout 8 dd if="$dev" bs=16 count=200 2>/dev/null | od -An -tx1
  else
    echo "cannot read $dev"
  fi
}

# Run register poll and input capture in parallel for ~6 seconds
( for i in $(seq 1 30); do
    printf "t=%02d " "$i"
    for r in $REGS; do
      v=$(i2cget -f -y $BUS $ADDR $r 2>/dev/null || echo "--")
      printf "%s=%s " "$r" "$v"
    done
    printf "\n"
    sleep 0.2
  done ) &
PID_REGS=$!

capture_input /dev/input/event0 > /tmp/input_event0.hex &
PID_INPUT=$!

capture_input /dev/input/event1 > /tmp/input_event1.hex &
PID_INPUT1=$!

wait $PID_REGS
kill $PID_INPUT $PID_INPUT1 2>/dev/null
wait $PID_INPUT $PID_INPUT1 2>/dev/null

echo ""
echo "=== /dev/input/event0 ==="
cat /tmp/input_event0.hex
echo ""
echo "=== /dev/input/event1 ==="
cat /tmp/input_event1.hex
echo ""
echo "End: $(date)"
