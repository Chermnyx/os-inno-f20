# Lab 6

## Test

Format:

```txt
[(for task3 only) Q - quantum]
[N - the number of processes]
(N lines)
[arrival_time] [burst_time]
```

The test itself (from the lab):

```txt
(this line is required only for the 3rd scheduler) 2
10
0 1
0 2
0 4
0 6
0 8
11 8
11 6
11 4
11 2
11 1
```

## Task 1

This scheduler is the simplest in implementation. Each time the process is created we add it into queue. We always schedule the 1st item from the queue.

This scheduler doesn't waste time on switching between the threads so its throughput is the biggest.

Output:

```txt
Execution table: ('+' = running, '-' = waiting, '.' = not yet arrived, ' ' = completed)
tick:   0 | + | - | - | - | - | . | . | . | . | . |
tick:   1 |   | + | - | - | - | . | . | . | . | . |
tick:   2 |   | + | - | - | - | . | . | . | . | . |
tick:   3 |   |   | + | - | - | . | . | . | . | . |
tick:   4 |   |   | + | - | - | . | . | . | . | . |
tick:   5 |   |   | + | - | - | . | . | . | . | . |
tick:   6 |   |   | + | - | - | . | . | . | . | . |
tick:   7 |   |   |   | + | - | . | . | . | . | . |
tick:   8 |   |   |   | + | - | . | . | . | . | . |
tick:   9 |   |   |   | + | - | . | . | . | . | . |
tick:  10 |   |   |   | + | - | . | . | . | . | . |
tick:  11 |   |   |   | + | - | - | - | - | - | - |
tick:  12 |   |   |   | + | - | - | - | - | - | - |
tick:  13 |   |   |   |   | + | - | - | - | - | - |
tick:  14 |   |   |   |   | + | - | - | - | - | - |
tick:  15 |   |   |   |   | + | - | - | - | - | - |
tick:  16 |   |   |   |   | + | - | - | - | - | - |
tick:  17 |   |   |   |   | + | - | - | - | - | - |
tick:  18 |   |   |   |   | + | - | - | - | - | - |
tick:  19 |   |   |   |   | + | - | - | - | - | - |
tick:  20 |   |   |   |   | + | - | - | - | - | - |
tick:  21 |   |   |   |   |   | + | - | - | - | - |
tick:  22 |   |   |   |   |   | + | - | - | - | - |
tick:  23 |   |   |   |   |   | + | - | - | - | - |
tick:  24 |   |   |   |   |   | + | - | - | - | - |
tick:  25 |   |   |   |   |   | + | - | - | - | - |
tick:  26 |   |   |   |   |   | + | - | - | - | - |
tick:  27 |   |   |   |   |   | + | - | - | - | - |
tick:  28 |   |   |   |   |   | + | - | - | - | - |
tick:  29 |   |   |   |   |   |   | + | - | - | - |
tick:  30 |   |   |   |   |   |   | + | - | - | - |
tick:  31 |   |   |   |   |   |   | + | - | - | - |
tick:  32 |   |   |   |   |   |   | + | - | - | - |
tick:  33 |   |   |   |   |   |   | + | - | - | - |
tick:  34 |   |   |   |   |   |   | + | - | - | - |
tick:  35 |   |   |   |   |   |   |   | + | - | - |
tick:  36 |   |   |   |   |   |   |   | + | - | - |
tick:  37 |   |   |   |   |   |   |   | + | - | - |
tick:  38 |   |   |   |   |   |   |   | + | - | - |
tick:  39 |   |   |   |   |   |   |   |   | + | - |
tick:  40 |   |   |   |   |   |   |   |   | + | - |
tick:  41 |   |   |   |   |   |   |   |   |   | + |

Per-task stats:
Task | CT | TAT | WT
   0 |  1 |   1 |  0
   1 |  3 |   3 |  1
   2 |  7 |   7 |  3
   3 | 13 |  13 |  7
   4 | 21 |  21 | 13
   5 | 29 |  18 | 10
   6 | 35 |  24 | 18
   7 | 39 |  28 | 24
   8 | 41 |  30 | 28
   9 | 42 |  31 | 30

Avg TAT: 17.600000
Avg WT: 13.400000
```

## Task 2

In this scheduler we always execute the easiest task first. It allows to decrease the waiting time and turn around time.

Output:

```txt
Execution table: ('+' = running, '-' = waiting, '.' = not yet arrived, ' ' = completed)
tick:   0 | + | - | - | - | - | . | . | . | . | . |
tick:   1 |   | + | - | - | - | . | . | . | . | . |
tick:   2 |   | + | - | - | - | . | . | . | . | . |
tick:   3 |   |   | + | - | - | . | . | . | . | . |
tick:   4 |   |   | + | - | - | . | . | . | . | . |
tick:   5 |   |   | + | - | - | . | . | . | . | . |
tick:   6 |   |   | + | - | - | . | . | . | . | . |
tick:   7 |   |   |   | + | - | . | . | . | . | . |
tick:   8 |   |   |   | + | - | . | . | . | . | . |
tick:   9 |   |   |   | + | - | . | . | . | . | . |
tick:  10 |   |   |   | + | - | . | . | . | . | . |
tick:  11 |   |   |   | + | - | - | - | - | - | - |
tick:  12 |   |   |   | + | - | - | - | - | - | - |
tick:  13 |   |   |   |   | - | - | - | - | - | + |
tick:  14 |   |   |   |   | - | - | - | - | + |   |
tick:  15 |   |   |   |   | - | - | - | - | + |   |
tick:  16 |   |   |   |   | - | - | - | + |   |   |
tick:  17 |   |   |   |   | - | - | - | + |   |   |
tick:  18 |   |   |   |   | - | - | - | + |   |   |
tick:  19 |   |   |   |   | - | - | - | + |   |   |
tick:  20 |   |   |   |   | - | - | + |   |   |   |
tick:  21 |   |   |   |   | - | - | + |   |   |   |
tick:  22 |   |   |   |   | - | - | + |   |   |   |
tick:  23 |   |   |   |   | - | - | + |   |   |   |
tick:  24 |   |   |   |   | - | - | + |   |   |   |
tick:  25 |   |   |   |   | - | - | + |   |   |   |
tick:  26 |   |   |   |   | + | - |   |   |   |   |
tick:  27 |   |   |   |   | + | - |   |   |   |   |
tick:  28 |   |   |   |   | + | - |   |   |   |   |
tick:  29 |   |   |   |   | + | - |   |   |   |   |
tick:  30 |   |   |   |   | + | - |   |   |   |   |
tick:  31 |   |   |   |   | + | - |   |   |   |   |
tick:  32 |   |   |   |   | + | - |   |   |   |   |
tick:  33 |   |   |   |   | + | - |   |   |   |   |
tick:  34 |   |   |   |   |   | + |   |   |   |   |
tick:  35 |   |   |   |   |   | + |   |   |   |   |
tick:  36 |   |   |   |   |   | + |   |   |   |   |
tick:  37 |   |   |   |   |   | + |   |   |   |   |
tick:  38 |   |   |   |   |   | + |   |   |   |   |
tick:  39 |   |   |   |   |   | + |   |   |   |   |
tick:  40 |   |   |   |   |   | + |   |   |   |   |
tick:  41 |   |   |   |   |   | + |   |   |   |   |

Per-task stats:
Task | CT | TAT | WT
   0 |  1 |   1 |  0
   1 |  3 |   3 |  1
   2 |  7 |   7 |  3
   3 | 13 |  13 |  7
   4 | 34 |  34 | 26
   5 | 42 |  31 | 23
   6 | 26 |  15 |  9
   7 | 20 |   9 |  5
   8 | 16 |   5 |  3
   9 | 14 |   3 |  2

Avg TAT: 12.100000
Avg WT: 7.900000
```

## Task 3

This scheduler is most suitable for interactive system. It gives proportional time to all the tasks so no one task can wait for scheduling forever (if some tasks runs infinitely long). Because of often switching between tasks the waiting time (and turn around time) is the biggest of all 3 schedulers.

Output:

```txt
Execution table: ('+' = running, '-' = waiting, '.' = not yet arrived, ' ' = completed)
tick:   0 | + | - | - | - | - | . | . | . | . | . |
tick:   1 |   | + | - | - | - | . | . | . | . | . |
tick:   2 |   | + | - | - | - | . | . | . | . | . |
tick:   3 |   |   | + | - | - | . | . | . | . | . |
tick:   4 |   |   | + | - | - | . | . | . | . | . |
tick:   5 |   |   | + | - | - | . | . | . | . | . |
tick:   6 |   |   | - | + | - | . | . | . | . | . |
tick:   7 |   |   | - | + | - | . | . | . | . | . |
tick:   8 |   |   | - | + | - | . | . | . | . | . |
tick:   9 |   |   | - | - | + | . | . | . | . | . |
tick:  10 |   |   | - | - | + | . | . | . | . | . |
tick:  11 |   |   | - | - | + | - | - | - | - | - |
tick:  12 |   |   | - | - | - | + | - | - | - | - |
tick:  13 |   |   | - | - | - | + | - | - | - | - |
tick:  14 |   |   | - | - | - | + | - | - | - | - |
tick:  15 |   |   | - | - | - | - | + | - | - | - |
tick:  16 |   |   | - | - | - | - | + | - | - | - |
tick:  17 |   |   | - | - | - | - | + | - | - | - |
tick:  18 |   |   | - | - | - | - | - | + | - | - |
tick:  19 |   |   | - | - | - | - | - | + | - | - |
tick:  20 |   |   | - | - | - | - | - | + | - | - |
tick:  21 |   |   | - | - | - | - | - | - | + | - |
tick:  22 |   |   | - | - | - | - | - | - | + | - |
tick:  23 |   |   | - | - | - | - | - | - |   | + |
tick:  24 |   |   | + | - | - | - | - | - |   |   |
tick:  25 |   |   |   | + | - | - | - | - |   |   |
tick:  26 |   |   |   | + | - | - | - | - |   |   |
tick:  27 |   |   |   | + | - | - | - | - |   |   |
tick:  28 |   |   |   |   | + | - | - | - |   |   |
tick:  29 |   |   |   |   | + | - | - | - |   |   |
tick:  30 |   |   |   |   | + | - | - | - |   |   |
tick:  31 |   |   |   |   | - | + | - | - |   |   |
tick:  32 |   |   |   |   | - | + | - | - |   |   |
tick:  33 |   |   |   |   | - | + | - | - |   |   |
tick:  34 |   |   |   |   | - | - | + | - |   |   |
tick:  35 |   |   |   |   | - | - | + | - |   |   |
tick:  36 |   |   |   |   | - | - | + | - |   |   |
tick:  37 |   |   |   |   | - | - |   | + |   |   |
tick:  38 |   |   |   |   | + | - |   |   |   |   |
tick:  39 |   |   |   |   | + | - |   |   |   |   |
tick:  40 |   |   |   |   |   | + |   |   |   |   |
tick:  41 |   |   |   |   |   | + |   |   |   |   |

Per-task stats:
Task | CT | TAT | WT
   0 |  1 |   1 |  0
   1 |  3 |   3 |  1
   2 | 25 |  25 | 21
   3 | 28 |  28 | 22
   4 | 40 |  40 | 32
   5 | 42 |  31 | 23
   6 | 37 |  26 | 20
   7 | 38 |  27 | 23
   8 | 23 |  12 | 10
   9 | 24 |  13 | 12

Avg TAT: 20.600000
Avg WT: 16.400000
```
