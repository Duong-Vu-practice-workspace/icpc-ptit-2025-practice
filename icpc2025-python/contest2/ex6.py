import bisect
t = int(input())
l = list()
def init():
    l.append(1)
    for i in range(1, 200000, 1):
        l.append(l[i - 1] * i)
def calC(k, n):
    return l[n] // (l[k] * l[n - k])
def testCase():
    n, k = [int(i) for i in input().split()]
    a = [int(i) for i in input().split()]
    ans = 0
    for i in range(1, n + 1, 1):
        ans += calC(i, n)
    for i in range(0, n, 1):
        s1 = bisect.bisect_left(a, a[i] + k, i + 1, i + n)
        s2 = bisect.bisect_left(a, abs(a[i] - k), i + 1, i + n)
        if (a[s1] == (a[i] + k)) or a[s2] == (abs(a[i] - k)):
            ans -= 1
            for j in range(3, n, 1):
                ans -= calC(j - 2, n - 2 - i)
    print(ans)

init()
while(t > 0):
    testCase()

    t -= 1