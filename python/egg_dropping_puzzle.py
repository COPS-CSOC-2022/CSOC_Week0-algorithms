e = int(input())
f = int(input())
highest = 50000


def eggs_floors(e, f):
    floor = [[0 for i in range(f + 1)] for i in range(e + 1)]

    for j in range(1, e + 1):
        floor[j][1] = 1
        floor[j][0] = 0

    for k in range(1, f + 1):
        floor[1][k] = k

    for j in range(2, e + 1):
        for k in range(2, f + 1):
            floor[j][k] = highest
            for i in range(1, k + 1):
                trials = 1 + max(floor[j - 1][i - 1], floor[j][k - i])
                if trials < floor[j][k]:
                    floor[j][k] = trials
    return floor[e][f]


print(f"Minimum number of trials required for {e} eggs and {f} floors = {eggs_floors(e,f)}")
