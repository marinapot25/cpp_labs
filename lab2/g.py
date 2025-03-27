import numpy as np
import matplotlib.pyplot as plt

with open('shell_classic.txt', 'r') as file:
    data = file.read()
data = data.splitlines()

N = []
t = []
a = []
s = []

for i in data:
    a = i.split()
    N.append(int(a[0]))
    t.append(int(a[1]))
    s.append(int(a[2]))
N = np.array(N)
t = np.array(t)
s = np.array(s)

plt.ylabel("Количество перестановок", fontsize="12") 
plt.xlabel("Число элементов $N$", fontsize="12")
plt.title('Число перестановок от числа элементов $N$ для классической сортировки Шелла', fontsize="10") 
plt.grid(True, "both", "both")
plt.scatter(N, s, zorder=2)
plt.savefig('shell_classic_swap.png')
plt.close()

plt.ylabel("Время $t$, мс", fontsize="12") 
plt.xlabel("Число элементов $N$", fontsize="12")
plt.title('Время $t$ от числа элементов $N$ для классической сортировки Шелла', fontsize="12") 
plt.grid(True, "both", "both")
plt.scatter(N, t, zorder=2)
plt.savefig('shell_classic_time.png')
plt.close()
