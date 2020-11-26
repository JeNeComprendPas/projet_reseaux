#!/bin/bash

sudo ip tuntap add mode tun dev tun0

ip -6 link set tun0 up
ip -6 addr add fc00:1234:ffff::1/64 dev tun0

ip -6 route add fc00:1234:4::/64 via fc00:1234:ffff::10 dev tun0