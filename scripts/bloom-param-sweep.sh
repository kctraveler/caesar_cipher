#!/bin/bash

# Set default maximum and step values for the two integer parameters
max_bits=100000000000
step_val=10000000
max_k=3

# Parse the command line arguments for the maximum and step values
while [[ $# -gt 0 ]]; do
  case "$1" in
    -m)
        max_bits="$2"
        shift 2
        ;;
    -s)
        step_val="$2"
        shift 2
        ;;
    -k)
      max_k="$2"
      shift 2
      ;;
    *)
      echo "Unknown option: $1"
      exit 1
      ;;
  esac
done

# Define the ranges for the two integer parameters using the maximum and step values
bit_test_range=($(seq $step_val $step_val $max_bits))
k_range=($(seq 1 1 $max_k))

# Loop through each combination of parameter values
for k in "${k_range[@]}"
do
    for size in "${bit_test_range[@]}"
    do
      num_collisions=$(~/Caesar-Cipher-1-comp-339-439-ds-1/bin/bloom-filter -b $size -h $k)
        if [ $num_collisions -eq 0 ]
        then
          printf "Min bits with %d hash functions:\t\t%d\n" $k $size 
          break
        fi
    done
done

