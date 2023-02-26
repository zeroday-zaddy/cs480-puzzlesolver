A file named puzzle.in will be read:
- Name of search to be used Uniform or Informed follwed by colon
- Then BFS or DFS for Uniform search
  or 1-4 for heuristic functions in Informed search
- Next two number are w x h dimensions
- The next numbers are the tiles from left to right top to bottom 
  - with 0 as the blank

### Assignment 1:
The given sample problem is seems to take long even with BFS

simple problems are given as an example in puzzle.in
program only read 1st problem, you can rearrange to read others
###### analysis:
- BFS will find the shortest solution given there is one in a reasonable time compared to DFS
- DFS can end up going down a long a fruitless route before it considers other path a given level
  - from the way my program is set up it will try moving
    various states' blank spot to the left, down, right, then up
  - it tries pushing those states in that prioirty to an extreme
  - even with skipping visited states DFS is not good with a large solution space
 

### Assignment 2:
The heuristic searches work pretty nicely
I still dont see the assignment example getting solved

###### analysis:
- This works way better than naive DFS and BFS
- I would suspect h4 is more powerful than h1 and h2 alone
  - although I haven't tried bigger problems
- h4 confused me for a while then I realized you have to count matching tiles too
  - or else it takes significantly longer as the heuristic decreases as it matches


### how to compile:
make command will complile this



## Example
here is sample input:

Informed; 4 4 4

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 0

1  0  3  4
5  2  7  8
9  6  10 11
13 14 15 12




and it's  output:

start
 1     3  4 
 5  2  7  8 
 9  6 10 11 
13 14 15 12 

goal
 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15    


steps
 1     3  4 
 5  2  7  8 
 9  6 10 11 
13 14 15 12 

 1  2  3  4 
 5     7  8 
 9  6 10 11 
13 14 15 12 

 1  2  3  4 
 5  6  7  8 
 9    10 11 
13 14 15 12 

 1  2  3  4 
 5  6  7  8 
 9 10    11 
13 14 15 12 

 1  2  3  4 
 5  6  7  8 
 9 10 11    
13 14 15 12 

 1  2  3  4 
 5  6  7  8 
 9 10 11 12 
13 14 15    


