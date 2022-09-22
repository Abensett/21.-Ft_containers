#!/bin/bash
#shebang means gotta use bash to run this

<< 'This-is-a-comment-thanks-to-here-doc'
This is a containers tester. It will test the containers and see
if they are working properly.

This is a function that will test the containers VECTOR
This-is-a-comment-thanks-to-here-doc

# .out are the output files of a program
tests=(constructeur  operateur_= operateur_plus operateur_moins operateur_mult
 operateur_div operateur_inf operateur_sup operateur_infeg operateur_supeg operateur_eg operateur_diff)

# This the execution of the testers and the diff
for i in {0..1}; do
 ./test_results/ft ${i} > ./test_results/ft_test_${i}.out
 ./test_results/std  ${i} > ./test_results/std_test_${i}.out
diff ./test_results/std_test_${i}.out ./test_results/ft_test_${i}.out > test_results/difftest_${i}.out

# if condition is between brackets  -s check if the file is empty

if ! [[ -s test_results/difftest_${i}.out ]];
then
    echo -e "Test ${tests[${i}]} ✅"
else
    echo -e "TEST ${tests[${i}]} ❌ voir le fichier difftest_${i}"
fi
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

