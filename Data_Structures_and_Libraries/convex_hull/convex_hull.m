axis ([0 5, 0 5])

x = [0 1 3 4 3 0 2 1 0]';
y = [0 1 1 4 3 3 2 2 0]';
plot(x, y, "linewidth", 4, '-')

hold on

x_ch = [0 4 3 0 0]';
y_ch = [3 4 1 0 3]';
plot(x_ch, y_ch, "linewidth", 4, '--')