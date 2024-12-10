def aoc10():
    # Read the input file and create the map
    M = {(i, j): int(c) for (i, l) in enumerate(open("c:/Users/dk958/advent-of-code/day10/input.txt")) for (j, c) in enumerate(l.strip())}
    
    # Create the neighbors dictionary
    N = {(i, j): {(i-1, j), (i+1, j), (i, j-1), (i, j+1)} & M.keys() for (i, j) in M}
    
    # Define the path function
    p = lambda s: [s] if M[s] == 9 else sum([p(n) for n in N[s] if M[n] == M[s] + 1], [])
    
    # Part 1: Count trailheads
    print(sum(len(set(p(c))) for c in M if M[c] == 0))
    
    # Part 2: Count paths
    print(sum(len(p(c)) for c in M if M[c] == 0))

# Call the function
aoc10()