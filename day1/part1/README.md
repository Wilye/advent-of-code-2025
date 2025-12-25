To compile:
```
clang++ -std=c++20 -Wall -Wextra -Werror day1_part1.cpp -o day1_part1
```

Needed to use mathematical modulo because apparently C++ modulo, when it handles negatives, just treats it as the value of the positive result of modulo-ing but then make it negative.

Mathematical modulo is `((a % n) + n) % n`
1. `a % n`: [-(n-1), ..., 0, ..., (n-1)]
    - -7 % 5 = -2
    - 7 % 5 = -2
    - 7 % 6 = 1
2. `(a % n) + n`: 
    - if `a % n` was already non negative, it pushes it above n
    - if `a % n` was negative, it pulls it into [1, n-1]
3. `((a % n) + n) % n`:
    - take % n again, leaves values in [0, n-1]