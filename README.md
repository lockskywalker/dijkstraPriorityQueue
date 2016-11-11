# dijkstraPriorityQueue

# Functional Requirements

Write a program that reads information about a weighted graph from the standard input. The input format is described in detail below. After the description of the graph, the input has two vertex numbers, s and t.

Your program should print a description of the graph, followed by the shortest path from s to t and the distance from s to t via that path, on the standard output.

For example, the input might look like this.

5  
1 2  9.0  
1 3 12.0  
2 4 18.0  
2 3  6.0  
2 5 20.0  
3 5 15.0  
0  
1 5  
  
That says that there are five vertices. There is an edge from vertex 1 to vertex 2 with weight 9.0, an edge from vertex 1 to vertex 3 with weight 12.0, etc. The start vertex s is 1, and the end vertex t is 5. The output for this input would be as follows.
There are 5 vertices and 6 edges.
The edges are as follows.
  
 (1,3) weight 12.000  
 (1,2) weight 9.000  
 (2,5) weight 20.000  
 (2,3) weight 6.000  
 (2,4) weight 18.000  
 (3,5) weight 15.000  
  
The shortest path from 1 to 5 has length 27.000 and is   
1 -> 3 -> 5  
