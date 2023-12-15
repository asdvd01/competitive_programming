import matplotlib.pyplot as plt

data = {
    (100, 10): 0,
    (100, 100): 0,
    (100, 1000): 0,
    (100, 10000): 0,
    (200, 10): 0,
    (200, 100): 0,
    (200, 1000): 0,
    (200, 10000): 0,
    (500, 10): 46,
    (500, 100): 0,
    (500, 1000): 0,
    (500, 10000): 0,
    (1000, 10): 12,
    (1000, 100): 3,
    (1000, 1000): 1,
    (1000, 10000): 0,
    (2000, 10): 178,
    (2000, 100): 19,
    (2000, 1000): 10,
    (2000, 10000): 4,
    (5000, 10): 686,
    (5000, 100): 185,
    (5000, 1000): 32,
    (5000, 10000): 72,
    (10000, 10): 2919,
    (10000, 100): 698,
    (10000, 1000): 293,
    (10000, 10000): 198,
}

bases = [10, 100, 1000, 10000]
digits = [100, 200, 500, 1000, 2000, 5000, 10000]

plt.figure(figsize=(10, 6))

for base in bases:
    time_values = [data[(d, base)] for d in digits]
    plt.plot(digits, time_values, label=f'Base {base}')

plt.xlabel('Number of Digits Multiplied')
plt.ylabel('Time to Multiply')
plt.title('Time Improvement with Different Bases for Multiplication')
plt.legend()
plt.grid(True)
plt.show()
