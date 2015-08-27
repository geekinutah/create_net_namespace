# create_net_namespace
Simple example that creates a network namespace and executes /bin/bash

# How to use
Download, and run 'make':

```
localhost.localdomain[master][create_net_namespace]$ make
cc    -c -o create_namespace.o create_namespace.c
gcc -o create_net_namespace create_namespace.o
localhost.localdomain[master][create_net_namespace]$
```

You should then be able to execute './create_net_namespace':


```
localhost.localdomain[master][create_net_namespace]$ sudo ./create_net_namespace 
[sudo] password for mwilson: 
Switching to the new namespace, here's us running ip link show in the current namespace:
1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN mode DEFAULT group default 
   link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
2: em1: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc pfifo_fast state DOWN mode DEFAULT group default qlen 1000
   link/ether 3c:97:0e:e4:b5:69 brd ff:ff:ff:ff:ff:ff
3: wlp3s0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc mq state UP mode DORMANT group default qlen 1000
   link/ether e0:9d:31:0c:6d:c0 brd ff:ff:ff:ff:ff:ff
4: virbr0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN mode DEFAULT group default 
   link/ether 52:54:00:0e:5f:4b brd ff:ff:ff:ff:ff:ff
5: virbr0-nic: <BROADCAST,MULTICAST> mtu 1500 qdisc pfifo_fast master virbr0 state DOWN mode DEFAULT group default qlen 500
   link/ether 52:54:00:0e:5f:4b brd ff:ff:ff:ff:ff:ff
6: br-attnet: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN mode DEFAULT group default 
   link/ether 52:54:00:35:dd:a5 brd ff:ff:ff:ff:ff:ff
7: br-attnet-nic: <BROADCAST,MULTICAST> mtu 1500 qdisc pfifo_fast master br-attnet state DOWN mode DEFAULT group default qlen 500
   link/ether 52:54:00:35:dd:a5 brd ff:ff:ff:ff:ff:ff
8: pxenet: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP mode DEFAULT group default 
   link/ether 52:54:00:24:8d:9d brd ff:ff:ff:ff:ff:ff
9: pxenet-nic: <BROADCAST,MULTICAST> mtu 1500 qdisc pfifo_fast master pxenet state DOWN mode DEFAULT group default qlen 500
   link/ether 52:54:00:24:8d:9d brd ff:ff:ff:ff:ff:ff
10: docker0: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc noqueue state DOWN mode DEFAULT group default 
   link/ether 00:00:00:00:00:00 brd ff:ff:ff:ff:ff:ff
14: vnet0: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast master pxenet state UNKNOWN mode DEFAULT group default qlen 500
   link/ether fe:54:00:a9:53:06 brd ff:ff:ff:ff:ff:ff
15: vnet1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc pfifo_fast master pxenet state UNKNOWN mode DEFAULT group default qlen 500
   link/ether fe:54:00:d0:8d:14 brd ff:ff:ff:ff:ff:ff


Welcome to your new network namespace!
Here's the new output of 'ip link show'
1: lo: <LOOPBACK> mtu 65536 qdisc noop state DOWN mode DEFAULT group default 
   link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00


[root@localhost create_net_namespace]#

```
You should get something like the above. Simple CTRL+D, logout or exit to destroy the namespace and return to the parent shell.

```
[root@localhost create_net_namespace]# exit
Back to the old namespace.
```
