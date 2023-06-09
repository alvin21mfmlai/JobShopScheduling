# JobShopScheduling
An overview on the traditional job-shop scheduling problem, followed by models descriptions and algorithms.

## 1. Overview
The job-shop scheduling problem (JSSP) is a widely studied optimization problem with multiple important industrial applications. The goal of JSSP is to define how to minimize the makespan required to allocate shared resources (machines) over time to complete competing activities/operations (jobs).

### 1.1 Problem Statement
Suppose a set of jobs J needs to be processed in a set of machines M, each in a given order. 

For example, consider two jobs (J1, J2), and four machines (M1, M2, M3, M4) where Job number 1 needs to be processed in machines (M1, M4, M3, M2), and Job number 2 needs to be processed in machines (M2, M3, M4, M1). The following pointers can be noted:
  - Before going to M4, J1 must have gone to M1 already
  - Before going to M1, J2 must have gone to M4 already
  - Each machine can process one job at a time
  - Each operation is defined by pairs (machine, job), and each has a specific processing time (p)
  - Total makespan depends on how one allocate resources to perform the tasks/operations

The figure below illustrates an optimal sequence of operations for a simple instance with five machines and four jobs. Note that (1) each machine processes just one job at a time, and (2) each job is processed by only one machine at a time.

![image](https://user-images.githubusercontent.com/70025024/236583834-a09c0810-733e-4e90-8c19-b5be4798a7d1.png)

## 2. Formulations for JSSP
The two standard formulations for JSSP are presented as follows:

### 2.1 Disjunctive model
Consider a set J jobs and a set M machines. 

#### Premise:
Each job j must follow a processing order (σʲ₁, σʲ₂, …, σʲₖ) and each operation (m, j) has a processing time p. 

#### Decision variables: 
  - Time that job j starts on machine m, xₘⱼ
  - Binary that marks precedence of job i before j on machine m, zₘᵢⱼ

#### Objective function: 
Total makespan of operation, C; minimize C

#### Constraints: 
  - The starting time of job j in machine m must be greater than the starting time of the previous operation of job j plus its processing time.
  - Each machine processes just one job at a time. Hence, if i precedes j in machine m, the starting time of job j in machine m must be greater than or equal to the starting time of job i plus its processing time.
  - Of every pair of jobs i, j, one element must precede the other for each machine m in M.
  - The total makespan (C) is greater than the starting time of every operation plus its processing time.

![image](https://user-images.githubusercontent.com/70025024/236586894-d24f751e-fcf5-4e2a-beba-ef4c6950ce3a.png)

where V is sum of all processing times. 

### 2.2 Time-indexed model
Only integer processing times can be considered and it produces a constraint matrix with several nonzero elements, which makes it computationally more expensive than the disjunctive model. Furthermore, as processing times increase, the number of decision variables increases as well.

#### Premise:
Each job j must follow a processing order (σʲ₁, σʲ₂, …, σʲₖ) and each operation (m, j) has a processing time p. In addition, a set of discrete intervals (T). 
Unlike from the previous disjunctive model, only binary variables are considered which mark it job j starts at machine m at instant t, xₘⱼₜ, besides the real-valued (or integer) makespan C.

#### Decision variables: 
  - Time that job j starts on machine m, xₘⱼ
  - Binary that marks precedence of job i before j on machine m, zₘᵢⱼ

#### Objective function: 
Total makespan of operation, C; minimize C

#### Constraints: 
  - Each job j at machine m starts only once.
  - Each machine processes just one job at a time, where only one job j can start at machine m during the time span between the current time t and pₘⱼ previous times. 
  - Starting time of job j in machine m must be greater than the starting time of the previous operation of job j plus its processing time.
  - Total makespan (C) is greater than the starting time of every operation plus its processing time.

![image](https://user-images.githubusercontent.com/70025024/236589388-0418096f-d5dc-4a18-b3ff-ceb5d14e85fd.png)
