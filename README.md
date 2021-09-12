# myDijkstra

A C/C++ program to read in a weighted graph and implement a variant of Dijkstra's algorithm to answer user queries.

## Getting Started

### Requirements

[gcc](https://gcc.gnu.org/)

### Installation

```
cd ./myDijkstra
Makefile
```
## Usage

### Query Input Format

```
1. find <source> <destination> <flag>

// Denote by source, destination, and flag the values of <source>, <destination>, and <flag>, respectively.
// If flag=1, your program prints information about each insertion, deletion, and decrease-key operations in the min-heap as it computes the paths.
// If flag=0, no min-heap operations are printed

2. write path <s> <d>

// The answer to this query is based on the computed information by the most recent valid find query: find <source> <destination> <flag>.
// Denote by s and d the values of <s> and <d>, respectively, in this write query.
// Denote by source and destination the values of <source> and <destination>, respectively, in the most recent valid find query, if there has been one.

3. stop

// Your program exits gracefully.
```
