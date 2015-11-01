
def solution(A):
    length = len(A)
    X,Y = 1,length - 2
    part_a = A[0]
    part_c = A[-1]
    part_b = sum(A) - part_a - part_c - A[X] - A[Y]
    result = 0
    while X + 1 < Y:
        if part_a == part_b and part_b == part_c:
            result = 1
            break
        if part_a < part_c:
            part_a += A[X]
            part_b -= A[X + 1]
            X += 1
        else:
            part_b -= A[Y - 1]
            part_c += A[Y]
            Y -= 1
    return 0


A = [4, 5, 1, 1, 1, 1, 4, 3, 1]
print solution(A)