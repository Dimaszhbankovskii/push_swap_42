# ARG=$(ruby -e "puts (1..1000).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
# ./../push_swap $ARG | ./checker_linux $ARG

ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
./../push_swap $ARG | ./checker_linux $ARG

ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
./../push_swap $ARG | ./checker_linux $ARG

# ARG=$(ruby -e "puts (1..50).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
# ./../push_swap $ARG | ./checker_linux $ARG

# ARG=$(ruby -e "puts (1..10).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
# ./../push_swap $ARG | ./checker_linux $ARG

ARG=$(ruby -e "puts (1..5).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
./../push_swap $ARG | ./checker_linux $ARG

ARG=$(ruby -e "puts (1..4).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
./../push_swap $ARG | ./checker_linux $ARG

ARG=$(ruby -e "puts (1..3).to_a.shuffle.join(' ')"); ./../push_swap $ARG | wc -l
./../push_swap $ARG | ./checker_linux $ARG

# ARG=$(ruby -e "puts (1..500).to_a.shuffle.join(' ')"); ./../push_swap $ARG
# ./../push_swap $ARG | ./checker_linux $ARG

# ARG="10 8 0 2 1 -12 66"; ./push_swap $ARG

# ARG="10 8 0 2 1 -12 66 99"; ./push_swap $ARG