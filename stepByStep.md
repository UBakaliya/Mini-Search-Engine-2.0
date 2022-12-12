# Documentation's for the "Mini Search Engine"

### Steps to take:

#### \* Using the graph class we are going to add the URLs are as vertex with the descriptions of the URls.

#### \* Edges are going to be the number of times the one particular word appears in a on paragraph (description of URLs), if there a tie between two paragraphs then we choose the first one that had the most occurrences. The reason we are doing that is because the user is most likely to search the most common word.

#### - Inside of our graph class we are going to have the A\* algorithm to find the best matching result the user given query and also we are going to have DFS & BFS (Note: The DFS & BFS are written only for learning purpose and for testing).

#### Code for graph is written in `graph.h`

#### Functions in graph.h:

##### `addVertex()` &larr; To add vertex in our graph

##### `addEdge()` &larr; To add edge

##### `getWeight()` &larr; To get weight from graph

#### `AStartAlgo()` &larr; To find shortest path (To get most occurrent url)

#### `DFS()` &larr; Used for testing

#### `BFS()` &larr; User for testing

---

#### The second best occurrences and also the tie occurrences will be store in a <b>"Singly Linked List"</b> Note we can improve the time complexity by using a better data structure, but we are going to use singly linked list for learning purpose.

#### Code for singly linked list written in `linkedList.h`

#### `insert()` &larr; For inserting in a Linked List

#### `contains()` &larr; Check if a value is exists in linked list

---
