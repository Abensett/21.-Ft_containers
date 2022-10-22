#!/bin/bash
#shebang means gotta use bash to run this

# number of tests
NOMBRE_DE_TESTS=4

<< 'This-is-a-comment-thanks-to-here-doc'
This is a containers tester. It will test the containers and see
if they are working properly.

This is a function that will test the containers VECTOR
This-is-a-comment-thanks-to-here-doc


# (()) will change variables see there the rest: https://stackoverflow.com/questions/31255699/double-parenthesis-with-and-without-dollar


# .out are the output files of a program
tests=(constructeur  operateur_= iterator iterators insert
 operateur_div operateur_inf operateur_sup operateur_infeg operateur_supeg operateur_eg operateur_diff)

# This the execution of the testers and the diff
i=0
printf "%-23s%s%s\n" "TESTS " "  FT STD DIF (en ms)"
while [[ $i -le $NOMBRE_DE_TESTS ]]
do

start=$(date +%s%N)                                             # start time in nanoseconds
./test_results/ft ${i} > ./test_results/ft_test_${i}.out
runtime_ft=$((($(date +%s%N) - $start)/1000000))                # runtime in milliseconds

start=$(date +%s%N)
 ./test_results/std  ${i} > ./test_results/std_test_${i}.out
runtime_std=$((($(date +%s%N) - $start)/1000000))

diff ./test_results/std_test_${i}.out ./test_results/ft_test_${i}.out > test_results/difftest_${i}.out

time_diff=$((${runtime_ft}/${runtime_std}));

if ! [[ -s test_results/difftest_${i}.out ]];
then
    printf "%-20s%-15s\n" "Test ${tests[${i}]}"  " ✅   ${runtime_ft}   ${runtime_std}   ${time_diff}"
else
    echo -e "TEST ${tests[${i}]} ❌ "
    diff -y ./test_results/std_test_${i}.out ./test_results/ft_test_${i}.out
fi
    ((i = i + 1))
done

<< testers
https://unix.stackexchange.com/questions/243489/bash-command-script-to-diff-all-mytestn-out-and-testn-out
 diff test${i}.out mytest${i}.out > difftest${i}.txt

  if ! [[ -s difftest${i} ]]; then
      echo "
  else
      echo "❌"
  fi
testers

