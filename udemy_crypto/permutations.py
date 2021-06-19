# +++++++++++++++++++++++++++++++
# Part 1
# +++++++++++++++++++++++++++++++
from itertools import permutations


my_list = [1, 2, 3, 4, 5]

list_of_permutations = permutations(my_list)
cnt = 0
for permutation in list_of_permutations:
    #print(permutation)
    cnt += 1

print(len(my_list), cnt)



# +++++++++++++++++++++++++++++++
# Part 2
# +++++++++++++++++++++++++++++++

import cProfile


def faculty(n):
    if n <= 1:
        return 1
    else:
        return faculty(n-1)*n

def counter(n):
    cnt = 0
    for i in range(n):
        cnt += 1
    return cnt

cProfile.run("counter(faculty(12))")

for i in range(10):
    print(faculty(i))

