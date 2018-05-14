import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

def plot_string(i):
	plt.clf()
	plt.plot(l,u[i,:],'.-')
	plt.ylim([-1.5,1.5])
	plt.grid()

u = np.genfromtxt("cuerda.txt")
n = np.size(u,1)
nt = np.size(u,0)
l = np.linspace(0,100,n)

# Grafica

plt.plot(l,u[0,:],'.-')
plt.plot(l,u[-1,:],'.-')
plt.ylim([-1.5,1.5])
plt.grid()
plt.savefig('u.png')


# Animacion

frms = nt/50;
fig,ax = plt.subplots()
anim = FuncAnimation(fig, plot_string, frames=int(frms), interval=20)
anim.save('u.gif', writer='imagemagick', fps=int(frms/2))
