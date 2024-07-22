# Philosophers
```
FINAL GRADE: -/100
```
- Multithreading
- Synchronization
  
Welcome to the 42 Philosophers project! This repository contains my implementation of the classic dining philosophers problem as part of the curriculum at [42 School](https://www.42.fr/). The dining philosophers problem is a fundamental synchronization problem in computer science, illustrating the challenges of avoiding deadlock and ensuring concurrency in a multi-threaded environment.

![Dining Philosophers](https://res.cloudinary.com/practicaldev/image/fetch/s--UJiIzrz5--/c_imagga_scale,f_auto,fl_progressive,h_900,q_auto,w_1600/https://dev-to-uploads.s3.amazonaws.com/i/4mrdvbtfbv2ma2avpp8i.png)

**Project goal:** To create a simulation of the dining philosophers problem, demonstrating threading, mutexes, and concurrent processing.

### Mandatory Part
In the mandatory part, each philosopher is a thread and each fork is protected by a mutex. There is exactly one fork between each philosopher and a philosopher must take the forks to his immediate left and right in order to eat. The goal is to manage resource allocation (forks) among multiple philosophers, ensuring no philosopher starves and preventing deadlock.

- Each philosopher should be a thread.
- Forks are shared resources protected by mutexes.
- Philosophers should alternately eat, think, and sleep.
- The program must handle proper termination and avoid data races.

### Bonus Part
For the bonus part of this project, the problem is the same with a few differences: philosophers are now processes and the forks are now a counting semaphore. The forks are arranged at the center of the table when not in use and any philosopher can take any fork.

### How to Use

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/prosviriakova/Philosophers.git philo
    cd philo
    ```

2. **Build the Project**:
    ```bash
    make
    ```

3. **Run the Simulation**:
    ```bash
    ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
    ```

    - `number_of_philosophers`: The number of philosophers and forks.
    - `time_to_die` (in milliseconds): Time a philosopher can go without eating before dying.
    - `time_to_eat` (in milliseconds): Time a philosopher spends eating.
    - `time_to_sleep` (in milliseconds): Time a philosopher spends sleeping.
    - `[number_of_times_each_philosopher_must_eat]` (optional): Number of times each philosopher must eat before the simulation ends.

    The arguments must be integers between 0 and INT_MAX representing a time in milliseconds. For example:
    ```bash
    ./philo 4 800 200 200 5
    ```

### Contributing

Contributions are welcome! If you have any suggestions or improvements, feel free to create an issue or submit a pull request.

*Subject version: 11.*
