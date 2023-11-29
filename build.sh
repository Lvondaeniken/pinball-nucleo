#!/bin/sh
cd app
cmake -Bbuild -GNinja
cmake --build build
