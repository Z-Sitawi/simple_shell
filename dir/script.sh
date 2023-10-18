#!/bin/bash
cat /proc/sys/kernel/pid_max
max_pid=$(getconf PID_MAX)
echo "The maximum process ID on this system is $max_pid"


# Get the maximum value for a process ID
max_pid=$(awk 'BEGIN {print 2^32 - 1}')

echo "Maximum Process ID: $max_pid"

