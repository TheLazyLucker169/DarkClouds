#! /bin/bash

# Global build directory
BUILD_DIR="./Build"
TEST_DIR="$BUILD_DIR/DC_Test"
EXEC_DIR="$BUILD_DIR/DarkClouds"

# Clear function
function Clear {
    if [ -d $BUILD_DIR ] ; then
        rm -rf $BUILD_DIR
    fi
}

# Build function
function Build {
    if [ -d $BUILD_DIR ] ; then
        Clear
        mkdir $BUILD_DIR
        cd $BUILD_DIR
        cmake .. -DBUILD_TYPE=Debug
        make
        cd ..
    else
        mkdir $BUILD_DIR
        cd $BUILD_DIR
        cmake ..
        make
        cd ..
    fi
}

# Test function
function Test {
    Build
    cd $TEST_DIR
    ctest
    cd ../..
}

# Run function
function Run {
    Build
    cd $BUILD_DIR/DarkClouds
    ./DarkClouds
}

# Script used for build automation and quick deploy
# Check number of arguments
if [ $# -gt 0 ] ; then
    echo "$# arguments passed."

    # Check for individual commands
    if [ $1 = "build" ] ; then
        echo "Build command."
        Build
    else
        if [ $1 = "clear" ] ; then
            echo "Clear command."
            Clear
        else
            if [ $1 = "test" ] ; then
                echo "Test command."
                Test
            else
                if [ $1 = "run" ] ; then
                    echo "Execute command."
                    Run
                else
                    echo "Unknown command."
                fi
            fi
        fi
    fi

else
    echo "No arguments passed."
fi