#!/bin/bash

ip -6 addr add fc00:1234:ffff::10/64 dev tun0
ip -6 link set dev tun0 up
ip -6 route get fc00:1234:3::16

ip -6 route add fc00:1234:4::/64 via fc00:1234:ffff::1 dev tun0