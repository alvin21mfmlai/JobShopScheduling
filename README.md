# JobShopScheduling (Jobs with Operations)

## 1. Define the Job Shop Scheduling Problem:
  - Input: A set of jobs J = {J1, J2, ..., Jn} and a set of machines M = {M1, M2, ..., Mm}.
  - Each job Ji consists of a sequence of operations Oi = {O1i, O2i, ..., Oki}, where each operation Oji represents a task that needs to be processed on a specific machine.
  - Each operation Oji has a processing time pij, which represents the time required to complete the operation on machine Mj.

## 2. Initialize variables and data structures:
  - Create an empty schedule S.
  - Create a priority queue Q to store the partial schedules.
  - Create a lower bound variable LB and set it to infinity.
  - Create an upper bound variable UB and set it to infinity.

## 3. Create the initial partial schedule:
  - Select an arbitrary job J1 from the set of jobs J.
  - For each operation O1i in J1, assign it to the corresponding machine Mi in the schedule S.
  - Calculate the lower bound of the initial schedule using a heuristic or an exact method.

## 4. Add the initial schedule to the priority queue:
  - Insert the initial schedule S into the priority queue Q.

## 5. Loop until the priority queue is empty:
  - Dequeue the schedule S with the highest priority from the priority queue Q.

### 5.1. Check if the schedule S is complete:
  - If all operations have been assigned, update the upper bound UB if necessary.
  - If the lower bound LB of the schedule is greater than the current upper bound UB, discard the schedule and continue to the next iteration.

### 5.2. Branch the schedule:
  - Select an unassigned operation Oji from the set of unassigned operations.
  - Create new schedules by assigning Oji to each possible machine that can process it.
  - Update the lower bound LB of each new schedule.

### 5.3. Add the new schedules to the priority queue:
  - Insert the new schedules into the priority queue Q.
  - Return the optimal schedule with the minimum makespan found.
