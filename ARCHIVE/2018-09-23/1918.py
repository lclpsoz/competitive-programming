from datetime import date
from datetime import datetime
from datetime import timedelta
from heapq import heappush, heappop
import gc

def dij (adj, n):
    h = []
    heappush (h, (0, 0))
    vis = [False for i in range(n)]
    dist = [1e18 for i in range(n)]
    dist[0] = 0
    while (len(h) > 0):
        w, u = heappop (h)
        if (vis[u]):
            continue
        vis[u] = True
        for i in adj[u]:
            v = i[0]
            w = i[1]
            if (dist[v] > (dist[u]+w)):
                dist[v] = dist[u]+w
                if (dist[v] > 1e18):
                    dist[v] = 1e18
                #print (dist[v], v)
                heappush (h, (dist[v], v))
    return dist[n-1]

def str_to_datetime (start):
    start = start.split(" - ")
    d, m, y = map (int, start[0].split('/'))
    h, mi, s = map (int, start[1].split(':'))
    st = datetime (y, m, d, h, mi, s)
    return st
    

t = int(input())
for i in range (t):
    n, m = map(int, input().split (' '))
    start = str_to_datetime (input())
    #print (start)
    end = str_to_datetime (input())
    #print (end)
    #print (end-start)
    adj = []
    for i in range(n):
        adj.append ([])
    for j in range (m):
        gc.collect()
        aux = input().split(' ')
        u = int(aux[0])
        v = int(aux[1])
        tim = aux[2].split('-')
        tim = [ int(x) for x in tim ]
        temp = (tim[0]*24*3600)+(tim[1]*3600)+(tim[2]*60)+(tim[3])
        #print (temp)
        adj[u].append ((v, temp))
        adj[v].append ((u, temp))
    d = dij (adj, n)
    #print (d)
    if (d > 6307200000):
        print ("IMPOSSIBLE")
    else:
        start += timedelta(seconds=d)
        if (start > end):
            print ("IMPOSSIBLE")
        else:
            print ("POSSIBLE")
            print ("{:%d/%m/%Y - %H:%M:%S}".format(start))
    gc.collect()
