#!/bin/bash

appRunning=1

while [ $appRunning == 1 ]; do
    echo "Compiling..."
    g++ -c src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++14
    mv -f *.o bin
    if [ $? -ne 0 ]
    then
        echo "ERROR: Compile failed!"
        exit 1
    fi

    g++ bin/*.o -o bin/Game/main.out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network -std=c++14 -Wall -Werror
    if [ $? -ne 0 ]
    then
        echo "Compile succeeded, but with warnings."
        bin/Game/main.out
        exit 2
    else
        echo "Compile succeeded without warnings."
        bin/Game/main.out
        exit
    fi
done
    