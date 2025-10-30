cpu_physical=$(grep "physical id" /proc/cpuinfo | wc -l)

cpu_virtual=$(grep processor /proc/cpuinfo | wc -l)

full_ram=$(free --mega | awk '$1 == "Mem:" {print $2}')

used_ram=$(free --mega | awk '$1 == "Mem:" {print $3}')

perc_ram=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf("%.1fGb\n"), disk_>

disk_used=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')

disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf(">

cpu_load=$(vmstat 1 2 | tail -1 | awk '{printf $15}')

cpu_op=$(expr 100 - $cpu_load)

cpu_fin=$(printf "%.1f" $cpu_op)

last=$(who -b | awk '$1 == "system" {print $3 " " $4}')

lvm=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

tcp=$(ss -ta | grep ESTAB | wc -l)

logs=$(users | wc -w)

ip=$(hostname -I)

mac=$(ip link | grep "link/ether" | awk '{print $2}')

sudo_exec=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  #Architecture: $arch
        #CPU physical : $cpu_physical
        #vCPU : $cpu_virtual
        #Memory Usage: $used_ram/${full_ram}MB ($perc_ram%)
        #Disk Usage: $disk_used/$disk_total ($disk_percent%)
        #CPU load: $cpu_fin%
        #Last boot: $last
        #LVM use: $lvm
        #Connections TCP : $tcp ESTABLISHED
        #User log: $logs
        #Network: IP $ip ($mac)
        #Sudo : $sudo_exec cmd"

