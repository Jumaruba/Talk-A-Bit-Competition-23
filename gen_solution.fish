#!/usr/bin/env fish

# The # must be replaced by a number such as 1,2,3,...
# TODO: change show diff and test, test a specific test and show help
#TODo: show execution time

set SHOW_DIFF true

# Compiling option
set CPP g++ -O2 -w -lm # C++

function compile -a SOURCE
    echo "================COMPILE================"
    $CPP $SOURCE.cpp
    set_color blue 
    echo "[COMPILE] 💨 Starting..."
    set_color green
    echo "[COMPILE] ⭕ $SOURCE compiled!"
    set_color normal
end 


function execute -a SOURCE
    set TESTS (count ./$SOURCE/in/*.in)  
    set_color blue
    for i in (seq 1 $TESTS)
        ./a.out < ./$SOURCE/in/$i.in > ./$SOURCE/out/$i.out
        echo "[GENERATED] Test $i"
    end 
    set_color normal
end



# MAIN ==================================================================
if test (count $argv) -lt 1
  echo "ℹ️ Usage: ./test <source-code>"
else 
    compile $argv[1]
    execute $argv[1]
end

