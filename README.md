# Conflict Serializabilty Determiner

<!-- ## Transactions in DBMS
In Database Management System, the processes are called as transactions-> those will either be successful or be failure. -->
## ACID Properties
A->Atomicity, C->Consistancy, I->Isolation and D->Durability

Atomicity refers to the definition of Transaction, i.e., the transaction will be successful or will undergo failure.
Isolation basically means that one transaction should not effect another transaction 
Durability means the changes made to the DBMS should be permanent
Consistancy is the summary of the above mentioned properties. If a transaction follows Atomicity, Isolation and Durability then it is consistant.

## Schedule
The arrangement of transaction operations is called a schedule.
It is of two types-> Serial and Non serial
Serial Schedules are always consistant as there is no context switching present, but it is not possible to run transactions serially one after another in real life scenario.
Therefore, Non serial schedules are mainly used in practical cases.
If we can prove a non serial schedule to be equivalent to serial schedule then we can conclude that the non serial schedule is also consistant.
## Conflicting Instructions
If two transaction operations happen on two different transactions on the same data value of a schedule and one of them is "Write" then those instruction pairs are called
as conflicting instructions.
## Conflict Serializability
To prove a schedule to be equivalent to a serial schedule comprising of same set of transaction operations, the best way is to prove it to be conflict equivalent to the
serial schedule . If we can prove , then the schedule is said to be conflict serializable and hence can be proved as consistant.
## Precedence Graph
To prove conflict serializability precedance graph is the best way.
## Algorithm:
1) Draw number of transactions number of nodes, starting from 0 to (number of transactions -1).
2) From one transaction say "A"  we look at an another transaction say "B" operations:
     (a)Look for operation on same data value and see if one of the operations is write: if so make a  directed edge from the A to B.
     (b)If at any point we get a cycle on the graph formed then we print that the transaction is not conflict serializable and return; 
3) We come to this step when we unable to detect cycle, so we print that the transaction is conflict serializable and return. 
## Cycle Detection Algorithm:
To detect the cycle in directed graph we have two algorithms: Depth First Search(DFS) and Breadth First Search(BFS); DFS is recursive and BFS is iterative;
so BFS gives better peformance so we have used BFS to implement cycle detection, it is known popularly as "Kahn's Algorithm": which is originally used for generating topological sorting of a graph applicable only for directed acylic graph: i.e., those that don't have cycles.
## Topological sort
It is the order of a graph nodes, such that if there is an edge from a to b then a should appear before b.

## Kahn's Algorithm
1) Data Structures used are: A queue for BFS, An indegree Array.
2) Important variable used: an interger type variable "Count=0";
3) Steps:
         (a) Compute the indegrees
         (b) Push the nodes having zero indegree to the queue
         (c) start popping out from front of queue while queue is not empty,when we pop then increase count, when we pop we go to the adjacent nodes of the same and decrease their indegrees one by one, when some indegree becomes zero push it to the queue.
         (d) when the queue becomes empty check if the count variable becomes equal to the number of elements, if it becomes equal to no of nodes then it means that the algorithm became able to generate topological sort of the graph and it is hence can be said as "Directed Acyclic Graph" or "A graph with no cycles" and we can return false.else it must  not be able to generate topological sort and hence must be directed cyclic graph, and we can return true.
## Actual algorithm
In the actual algorithm we check if there is a cycle in the graph using Kahn's algorithm:
if yes, then we print that the transaction is not conflict serializable
else , we print that the transaction is conflict serializable

         
       







