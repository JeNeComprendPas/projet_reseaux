#!/bin/bash

sudo ip -6 tuntap add mode tun tun0

ip -6 link set tun0 dev up
ip -6 addr add fc00:1234:ffff::1/64 dev tun0

ip -6 route add fc00:1234:4::/64 via fc00:1234:ffff::10 dev tun0