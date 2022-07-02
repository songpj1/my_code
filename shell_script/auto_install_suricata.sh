#!/bin/bash -x
version="6.0.5"
request_install_things="wget libpcap-devel libnet-devel pcre-devel gcc-c++ automake autoconf libtool make libyaml-devel zlib-devel file-devel jansson-devel nss-devel lua-devel rustc cargo"
os_type=`cat /etc/os-release | head -n 1 | awk -F"=" '{print $2}' | awk -F" " '{print $1}' | awk -F"\"" '{print $2}'`
if [ "$os_type" == "CentOS" ];then
    echo -e $os_type
    sudo yum -y install $request_install_things
    if [ ! -f ./suricata-${version}.tar.gz ];then
        wget https://www.openinfosecfoundation.org/download/suricata-${version}.tar.gz
    fi
    tar xzvf suricata-${version}.tar.gz
    cd suricata-${version}
    ./configure --prefix=/usr --sysconfdir=/etc --localstatedir=/var --enable-nfqueue --enable-lua
    make && sudo make install && sudo ldconfig
    make install-full
    cd ../  
    rm -f suricata-${version}.tar.gz
fi

