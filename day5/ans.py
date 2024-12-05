from collections import defaultdict
import os
infile = 'c:/Users/dk958/advent-of-code/day5/input.txt'

p1, p2 = open(infile).read().split('\n\n')
orders = defaultdict(list)
for lines in p1.split('\n'):
    before,after = lines.split('|')
    orders[int(before)].append(int(after))

updates = [list(map(int, line.split(','))) for line in p2.splitlines()]
part1 = 0
part2 = 0
for pages in updates:
    sorted_pages = sorted(pages, key=lambda page: -len([order for order in orders[page] if order in pages]))
    if pages == sorted_pages:
        part1 += pages[len(pages) // 2]
    else:
        part2 += sorted_pages[len(sorted_pages) // 2]
print('Part 1', part1)
print('Part 2', part2)
