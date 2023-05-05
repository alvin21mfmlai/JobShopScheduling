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


