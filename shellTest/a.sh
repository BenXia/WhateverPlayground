#!/bin/zsh

export HELLO="123"

echo "$@"
echo "$*"
echo $HELLO

foreach num ( $* )
    echo $num
end

function testFunc() {
    echo "\$0:$0 in func"
}

echo "\$0:$0 out func"
testFunc a b c
