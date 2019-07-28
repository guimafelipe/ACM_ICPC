#code
maximum = 10**6
minimum = -maximum

T = int(input())

def copy_grid(grid):
    ans = []
    for r in range(3):
        row = [0] * 3
        for c in range(3):
            row[c] = grid[r][c]
        ans.append(row)
    return ans
 
def print_grid(grid):
    for i in range(len(grid)):
        print(grid[i])
    print()

def get_children(grid, a):
    ans = []
    
    for r in range(3):
        for c in range(3):
            if grid[r][c] != "_":
                continue
            
            grid[r][c] = a
            ans.append(copy_grid(grid))
            grid[r][c] = "_"
    
    return ans
            
def get_heuristic(grid, h):
    h = 0
    # horizontal win/loss
    for i in range(3):
        if grid[i][0] == 'x' and grid[i][1] == 'x' and grid[i][2] == 'x':
            return maximum - h
        if grid[i][0] == 'o' and grid[i][1] == 'o' and grid[i][2] == 'o':
            return minimum + h
    
    # vertical win/loss
    for i in range(3):
        if grid[0][i] == 'x' and grid[1][i] == 'x' and grid[2][i] == 'x':
            return maximum - h
        if grid[0][i] == 'o' and grid[1][i] == 'o' and grid[2][i] == 'o':
            return minimum + h
    
    # forward diagonal win/loss
    if grid[0][0] == 'x' and grid[1][d] == 'x' and grid[2][2] == 'x':
        return maximum - h
    if grid[0][0] == 'o' and grid[1][1] == 'o' and grid[2][2] == 'o':
        return minimum + h
        
    # backward diagonal win/loss
    if grid[2][0] == 'x' and grid[1][1] == 'x' and grid[0][2] == 'x':
        return maximum - h
    if grid[2][0] == 'o' and grid[1][1] == 'o' and grid[0][2] == 'o':
        return minimum + h
    
    return 0
    
def is_draw(grid):
    for r in range(3):
        for c in range(3):
            if grid[r][c] == "_":
                return False
    return True
    
def minimax(grid, player, h):
    heuristic = get_heuristic(grid, h)
    
    if heuristic != 0:
        return heuristic
    
    if is_draw(grid):
        return 0
    
    if player == "Max":
        children = get_children(grid, "x")
        worst_case = minimum
        for child in children:
            worst_case = max(worst_case, minimax(child, "Min", h + 1))
        
    if player == "Min":
        children = get_children(grid, "o")
        worst_case = maximum
        for child in children:
            worst_case = min(worst_case, minimax(child, "Max", h + 1))
    
    return worst_case
    
def get_move(grid, next_grid):
    ans = [0, 0]
    for r in range(3):
        for c in range(3):
            if grid[r][c] != next_grid[r][c]:
                return [r, c]
    return ans

for t in range(T):
    grid = []
    for i in range(3):
        line = input().split(" ")
        grid.append([line[0], line[1], line[2]])
    
    children = get_children(grid, "x")
    worst_case = minimum
    h = 1
    next_grid = children[0]
    for child in children:
        score = minimax(child, "Min", h)
        if score > worst_case:
            worst_case = score
            next_grid = child

    move = get_move(grid, next_grid)
    
    print(move[0], move[1])
        