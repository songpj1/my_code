#!/bin/bash -x

bin_file=$0
host_ip=$1
usr_name=$2
if [ $# -ne 2 ]; then
    echo -e "usage: ${bin_file} [host_ip] [usr_name]"
    exit -1
fi

ssh-keygen -t rsa -N '' -f id_rsa -q

ssh-copy-id -i ${usr_name}@${host_ip}

[ -f ./id_rsa ] && rm -f ./id_rsa
[ -f ./id_rsa.pub ] && rm -f ./id_rsa.pub

ssh ${usr_name}@${host_ip}
