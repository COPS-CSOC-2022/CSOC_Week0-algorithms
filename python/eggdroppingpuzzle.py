import sys
 
def e(n, k):
 
    if (k == 1 or k == 0):
        return k
 
    if (n == 1):
        return k
 
    min = sys.maxsize
 
   
    for x in range(1, k + 1):
 
        res = max(e(n - 1, x - 1),
                  e(n, k - x))
        if (res < min):
            min = res
 
    return min + 1
 
if __name__ == "__main__":
 
    n = int(input())
    k = int(input())
    print("Minimum number of trials in worst case with",
           n, "eggs and", k, "floors is", e(n, k))
 
