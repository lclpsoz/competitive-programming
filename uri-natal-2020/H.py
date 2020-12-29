import itertools

adj = [ [0, 1],
        [0, -1],
        [1, 0],
        [-1, 0]]

def bfs(n, mat, st):
    INF = 10**9
    dist = [[INF] * (n+2) for i in range(n+2)]

    # print("st", st)
    q = [[[st[0], st[1]], 0]]
    sz = len(q)
    i = 0
    while i < len(q):
        pt, d = q[i]
        # print(pt, d, dist[pt[0]][pt[1]], len(q))
        i += 1
        if dist[pt[0]][pt[1]] != INF:
            continue
        dist[pt[0]][pt[1]] = d

        for delta in adj:
            now = [pt[0]+delta[0], pt[1]+delta[1]]
            if dist[now[0]][now[1]] == INF and mat[now[0]][now[1]] != '#':
                q.append([now, d+1])

    return dist

t = int(input())
while t:
    n, p = map(int, input().split(' '))
    mat = ["#"*(n+2)]
    players = []
    portals = []
    for i in range(1, n+1):
        mat.append("#" + input() + "#")
        for j in range(1, n+1):
            if mat[i][j] == 'G':
                players.append([i, j])
            elif mat[i][j] == 'X':
                portals.append([i, j])
    mat.append(mat[0])
    # for lin in mat:
    #     print(lin)
    dists = []
    for st in players:
        dist = bfs(n, mat, st)
        now = []
        for x, y in portals:
            now.append(dist[x][y])
        dists.append(now)
    # if t == 2:
    #     for i in dists:
    #         for j in i:
    #             for x in j:
    #                 if x > 100:
    #                     print('#', end=' ')
    #                 else:
    #                     print(x, end = ' ')
    #             print('')
    
    ans = 10**9
    for perm in itertools.permutations([i for i in range(p)]):
        now = 0
        for i in range(p):
            now = max(now, dists[perm[i]][i])
        ans = min(ans, now)

    if ans == 10**9:
        ans = -1
    print(ans)
    t -= 1