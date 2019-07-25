
size = 10**4 + 1
ans = [0] * (size)
ans[1] = 1

i_2 = 1
i_3 = 1
i_5 = 1
for n in range(2, size):
        curr_2 = 2 * ans[i_2]
        curr_3 = 3 * ans[i_3]
        curr_5 = 5 * ans[i_5]
        
        ans[n] = min([curr_2, curr_3, curr_5])
        
        if ans[n] == curr_2:
            i_2 += 1
        if ans[n] == curr_3:
            i_3 += 1
        if ans[n] == curr_5:
            i_5 += 1
            
for t in range(T):
    N = int(input())
    
    print(ans[N])
    