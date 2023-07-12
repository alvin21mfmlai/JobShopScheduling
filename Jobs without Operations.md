# JobShopScheduling (Jobs without Operations)

## 1. Define the Job Shop Scheduling Problem:
  - Input: A set of jobs J = {J1, J2, ..., Jn} and a set of machines M = {M1, M2, ..., Mm}.
  - Each job Oi has a processing time pij, which represents the time required to complete the operation on machine Mj.

## 2. Formulate the problem as a space search tree:
  - Create a search tree where each node represents a partial schedule.
  - Each level of the tree corresponds to a specific time slot.
  - Each node contains the following information:
    - Current partial schedule (assignment of jobs to machines)
    - Remaining jobs that need to be scheduled
    - The current makespan (the time at the current level)

