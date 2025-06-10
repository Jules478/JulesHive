# Philosophers

## What it is?

Philosophers is a progam based on the [Dining Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem). There are n number of philosophers seated at a round table with a fork between them. Philosophers pick up the forks either side of them and eat from a communal plate of spaghetti. After eating they will sleep for a defined amount of time before waking to eat more. If a philosopher does not eat within a specified amount of time they will die and the simulation ends.

## How does it work?

This project works by the use of threads and mutexes to control how data is used and accessed across multiple concurrent threads. Each philospher is a thread and the threads cannot communicate between eachother. 

> [!NOTE]
> This is intended as a guide only. Writing and understanding your own code is better than copying code.