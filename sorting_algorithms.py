import matplotlib.pyplot as plt
import os
import numpy as np

comparasions1 = []
comparasions2 = []
comparasions3 = []

sizes = []
size = 0

with open("comps.dat", mode="rb") as handler:
    temp = []
    filesize = os.stat("comps.dat").st_size // 4
    byte = handler.read(4)
    while byte:
        temp.append(int.from_bytes(byte, "little"))
        byte = handler.read(4)
    size = temp[0]
    sizes = temp[1:size + 2]
    comparasions1 = temp[(size + 2): 2 * (size + 1)]
    comparasions2 = temp[2 * (size + 1): 3*size + 2]
    comparasions3 = temp[3 * size + 2: 4 * size + 2]

print(len(comparasions1))
print(len(comparasions2))
print(len(comparasions3))

plt.plot(sizes[1:], comparasions1)
plt.plot(sizes[1:], comparasions2)
plt.plot(sizes[1:], comparasions3)

plt.show()