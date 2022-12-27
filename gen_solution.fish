#!/usr/bin/env fish

# The # must be replaced by a number such as 1,2,3,...
# TODO: change show diff and test, test a specific test and show help
#TODo: show execution time

set TESTS (count $IN)
set SHOW_DIFF true

# Compiling option
set CPP g++ -O2 -w -lm # C++

function compile -a SOURCE
    echo "================COMPILE================"
    $CPP $SOURCE
    set_color blue 
    echo "[COMPILE] 💨 Starting..."
    set_color green
    echo "[COMPILE] ⭕ $SOURCE compiled!"
    set_color normal
end 


function execute -a SOURCE
    mkdir $SOURCE
    echo "=================TESTS================="
    for i in (seq 1 $TESTS)
        ./a.out < ./$SOURCE/in/$i.in > ./$SOURCE/out/$i.out
    end 
end



# MAIN ==================================================================
if test (count $argv) -lt 1
  echo "ℹ️ Usage: ./test <source-code>"
else 
    compile $argv[1]
    execute $argv[1]
end

