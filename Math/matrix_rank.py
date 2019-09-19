#code

def copy(A):
    ans = [0] * len(A)
    for i in range(len(A)):
        ans[i] = A[i]
        
    return ans

def mult_k(k, A):
    for i in range(len(A)):
        A[i] *= k
    return A
        
def swap_row(m, i, r):
    temp = copy(m[i])
    m[i] = m[r]
    m[r] = temp
  
def swap_col(m, i, c):
    for j in range(len(m)):
        temp = m[j][i]
        m[j][i] = m[j][c]
        m[j][c] = temp
    
def rank(m):
    R = len(m)
    C = len(m[0])
    
    ans = C
    
    for i in range(min(len(m), ans)):
        if m[i][i] == 0:
            flag = False
            
            for r in range(i + 1, R):
                if m[r][i] != 0:
                    swap_row(m, i, r)
                    flag = True
                    break
            
            if not flag:
                swap_col(m, i, ans - 1)
                ans -= 1
                i -= 1
        
        else: # echelon
            for r in range(i + 1, R):
                temp = mult_k((m[r][i] / m[i][i]), copy(m[i]))
                
                for j in range(i, ans):
                    m[r][j] -= temp[j]
    
    return ans
    
T = int(input())

for t in range(T):
    m = [[0 for j in range(3)] for i in range(3)]
    
    for i in range(3):
        line = input().split(" ")
        
        for j in range(3):
            m[i][j] = int(line[j])
            
    print(rank(m))

# input

# 2
# 10 20 10
# -20 -30 10
# 30 50 0
# 2 4 3
# 1 0 9
# 9 6 8