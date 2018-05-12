import numpy as np
import matplotlib.pyplot as plt

V = np.genfromtxt("potencial.txt")
Ex = np.genfromtxt("campox.txt")
Ey = np.genfromtxt("campoy.txt")

m,n = np.shape(Ex)
M,N = np.meshgrid(np.arange(m),np.arange(n))


plt.imshow(V)
plt.colorbar()
plt.streamplot(M,N,Ex,Ey, color='black', linewidth=1, density=2)




plt.savefig('V.png')
