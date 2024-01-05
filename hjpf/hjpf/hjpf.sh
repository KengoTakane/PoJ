#!/bin/bash
/usr/bin/echo 950000 > /sys/fs/cgroup/cpu,cpuacct/system.slice/hjpf.service/cpu.rt_runtime_us
./hjpf >& /tmp/hjpf.log

