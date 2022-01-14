ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_Mac $ARG

ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_Mac $ARG

ARG=$(ruby -e "puts (1..50).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_Mac $ARG

ARG=$(ruby -e "puts (1..10).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_Mac $ARG

ARG=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_Mac $ARG

ARG=$(ruby -e "puts (1..3).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_Mac $ARG
