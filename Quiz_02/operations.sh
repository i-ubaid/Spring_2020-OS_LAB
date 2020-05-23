#!/bin/bash

num=5

echo "Please Enter two numbers."
read a b
echo "Please enter Operator."
read c
  case "$c" in
  "+")
  val=`expr $a + $b`
echo "$a + $b : $val"
  ;;
  "-")
  val=`expr $a - $b`
echo "$a - $b : $val"
  ;;
  "/")
  val=`expr $a / $b`
echo "$a / $b : $val"
  ;;
    "*")
  val=`expr $a \* $b`
echo "$a * $b : $val"
  ;;
  *)
  echo "No Operator entered";;
  esac





