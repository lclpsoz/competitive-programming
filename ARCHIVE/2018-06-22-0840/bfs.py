#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the bfs function below.
def bfs(n, m, edges, s):
       
        queue = []
        distances = [-1] * n
        queue.append(s)
        distances[s-1] = 0
        
        while queue:
            v = queue.pop(0)
		# pra m muito grande fica um loop desnecessario, dai 
		# to vendo se mudo a forma como os dados estão 
		# sendo passados para a função
            for i in range(m):
                if v in edges[i]:
                    for u in edges[i]:
                        if distances[u-1] == -1:
                            queue.append(u)
                            distances[u-1] = distances[v-1]+6;
        distances.remove(0)
        
        return distances

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    for q_itr in range(q):
        nm = input().split()

        n = int(nm[0])

        m = int(nm[1])

        edges = []

        for _ in range(m):
            edges.append(list(map(int, input().rstrip().split())))
            

        s = int(input())

        result = bfs(n, m, edges, s)

        fptr.write(' '.join(map(str, result)))
        fptr.write('\n')

    fptr.close()
