import pyperclip as pc
def pr(s):
    print(s)
    pc.copy(s)
infile = 'c:/Users/dk958/advent-of-code/day7/input.txt'
p1 = 0
p2 = 0
D = open(infile).read().strip()

def is_valid(target, ns, p2):
    if len(ns) == 1:
        return ns[0]==target
    if is_valid(target, [ns[0]+ns[1]] + ns[2:], p2):
        return True
    if is_valid(target, [ns[0]*ns[1]] + ns[2:], p2):
        return True
    if p2 and is_valid(target, [int(str(ns[0])+str(ns[1]))] + ns[2:], p2):
        return True
    return False

for line in D.strip().split('\n'):
    target, ns = line.strip().split(':')
    target = int(target)
    ns = [int(x) for x in ns.strip().split()]
    if is_valid(target, ns, p2=False):
        p1 += target
    if is_valid(target, ns, p2=True):
        p2 += target

pr(p1)
pr(p2)