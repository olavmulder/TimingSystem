#!/bin/bash

#execute addUser program
echo $1
/home/timing/RPI/bin/addUser $1; res=$?
echo $res
exit $res


