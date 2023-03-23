#!/bin/bash

tr '[:upper:]' '[:lower:]' < "$1" | sort | uniq > "$2"