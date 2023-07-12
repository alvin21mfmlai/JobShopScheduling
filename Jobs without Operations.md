# JobShopScheduling (Jobs without Operations)

## 1. Define the Job Shop Scheduling Problem:
  - Input: A set of jobs J = {J1, J2, ..., Jn} and a set of machines M = {M1, M2, ..., Mm}.
  - Each job Oi has a processing time pij, which represents the time required to complete the operation on machine Mj.

## 2. Formulate the problem as a space search tree:
  - Create a search tree where each node represents a partial schedule.
  - Each level of the tree corresponds to a specific time slot.
  - Each node contains the following information:
    - Parent node
    - Total path cost for ancestors and current node
    - Available jobs which need to be scheduled 
    - Least cost
    - Machine ID
    - Job ID

## 3. Develop lower bound cost function
  - Compute least cost for current partial schedule of available jobs which are not yet assigned to any machines

## 4. Implement Branch & Bound function
  - Initialize an empty priority queue to store the nodes of the space search tree
  - Initialize the best known solution with an initial high value (INT_MAX = 2147483647  (for 32-bit Integers))
  - Push dummy root node (initial partial schedule) into the queue
  - While queue is not empty:
      - Pop node with the minimum lower cost from the queue
      - Iterate for all jobs
          - if current job is not assigned, generate all possible child nodes by extending the current partial schedule
          - Compute least cost for each child node
          - Push child node into queue
          - If a complete schedule is reached (no remaining jobs), update the best known solution if the current makespan is lower.
      - Once the queue is empty, the best known solution represents the optimal (or reasonably good) schedule.
  
## 5. Using pruning strategies
  - Consider any of the following: (1) precedence rules, (2) time-window constraints, or/and (3) resource constraints, to prune infeasible solutions
