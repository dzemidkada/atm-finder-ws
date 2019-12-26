#!/usr/bin/env bash

docker run ^
    -v C:\Users\Dzmitry_Dzemidka\Desktop\EPAM_Projects\uni\atm-finder-ws\cppweb\tank:/var/loadtest ^
    -v 8080:/ssh-agent -e SSH_AUTH_SOCK=/ssh-agent ^
    --net host ^
    -it direvius/yandex-tank
