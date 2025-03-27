import numpy as np
import matplotlib.pyplot as plt

with open('3c2.txt', 'r') as file:
    data = file.read()
data = data.splitlines()

N = []
t = []
a = []

for i in data:
    a = i.split()
    N.append(int(a[0]))
    t.append(int(a[1]))
N = np.array(N)
t = np.array(t)
N = np.log(N)
t = np.log(t)

sN = np.mean(N)
sNt = np.mean(t * N)
sN2 = np.mean(N ** 2)
st = np.mean(t)
k = (sNt - st * sN)/(sN2 - sN ** 2)
b = st - k * sN


plt.ylabel("$ln(t), ln(мс)$", fontsize="12") 
plt.xlabel("$ln(N)$", fontsize="12")
plt.title('Стратегия С (неравномерное рапределение)') 
#plt.axis([4,14,2,13])
x = np.array([0., 15]) 
plt.minorticks_on()
plt.grid(True, "both", "both")
#plt.plot(x, k * x + b, "-r", linewidth=1, label = k) 
plt.scatter(N, t, zorder=2)

#print(k)
#plt.legend()
plt.savefig('12.png')