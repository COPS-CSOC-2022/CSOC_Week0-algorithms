class QueueEntry(object):
    def __init__(self, v=0, dist=0):
        self.v = v
        self.dist = dist 
 
def getMinDiceThrows(move, N):
    visited = [False] * N
    queue = []
    visited[0] = True
    queue.append(QueueEntry(0, 0))
    qe = QueueEntry()  
    while queue:
        qe = queue.pop(0)
        v = qe.v  
        if v == N - 1:
            break
        j = v + 1
        while j <= v + 6 and j < N:
            if visited[j] is False:
                a = QueueEntry()
                a.dist = qe.dist + 1
                visited[j] = True
                a.v = move[j] if move[j] != -1 else j
                queue.append(a)
            j += 1
    return qe.dist
N = 30
moves = [-1] * N
moves[2] = 21
moves[4] = 7
moves[10] = 25
moves[19] = 28
moves[26] = 0
moves[20] = 8
moves[16] = 3
moves[18] = 6
print("The minimum number of dice throws required is {0}".
      format(getMinDiceThrows(moves, N)))