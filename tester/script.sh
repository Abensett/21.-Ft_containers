#!/bin/bash
#shebang means gotta use bash to run this

<< 'This-is-a-comment-thanks-to-here-doc'
This is a containers tester. It will test the containers and see
if they are working properly.

This is a function that will test the containers VECTOR
This-is-a-comment-thanks-to-here-doc

if !(diff=`diff test_results/std.txt test_results/ft.txt`)
then
    echo $diff
    echo "The tests are not the same"
    exit 0
else
    echo $diff
    echo "The tests are the same"
    exit 0
fi

<< testers
https://unix.stackexchange.com/questions/243489/bash-command-script-to-diff-all-mytestn-out-and-testn-out
 diff test${i}.out mytest${i}.out > difftest${i}.txt

  if ! [[ -s difftest${i} ]]; then
      echo success
  else
      echo "difference found"
  fi
testers
