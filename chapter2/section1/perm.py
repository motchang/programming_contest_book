MAX_N = 10 ** 8
used = [0] * MAX_N
perm = [0] * MAX_N

# {0,1,2,3,4, ... ,n - 1}の並び替えn!通りを生成する

def permutation1(pos, n):
    if pos == n:
        print(perm[:n])
        return

    # permのpos番目を0～n-1のどれにするかのループ
    for i in range(n):
        if not used[i]:
            perm[pos] = i
            # iを使ったのでフラグをTrueにしておく
            used[i] = True
            permutation1(pos + 1, n)
            # 戻ってきたらフラグを戻しておく
            used[i] = False
    return

from itertools import permutations

def permutation2(n):
    perm2 = list(range(n))
    for tmp_perm in permutations(perm2, n):
        print(tmp_perm)
    return

permutation1(0, 3)
print()
permutation2(3)
