#!/usr/bin/env fish

# The # must be replaced by a number such as 1,2,3,...
# TODO: change show diff and test, test a specific test and show help
#TODo: show execution time

set IN ./testdata/*.in
set OUT ./testdata/*.out
set TESTS (count $IN)
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
    set TESTS (count ./$SOURCE/input/*.txt)  
    echo "=================TESTS================="
    set_color blue
    for i in (seq 1 $TESTS)
        ./a.out < ./$SOURCE/input/input$i.txt > ./$SOURCE/test/output$i.txt
        set result (diff  ./$SOURCE/output/output$i.txt  ./$SOURCE/test/output$i.txt)
        show_result "$result" $i $SOURCE
    end 
end

function show_result -a result testnum SOURCE
    if test -z "$result" 
        set_color green    
        echo "[TEST::$testnum] :: ✔️ PASSED!"
    else if $SHOW_DIFF
        set_color red 
        echo "[TEST::$testnum] :: X WRONG ANSWER!"
        set_color normal
        diff -c ./$SOURCE/output/output$testnum.txt ./$SOURCE/test/output$testnum.txt
    else 
        set_color red 
        echo "[TEST::$testnum] :: X WRONG ANSWER!"
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


