import numpy as np
import matplotlib.pyplot as plt

q1,p1,q2,p2 = np.genfromtxt("q1_p1_q2_p2.txt", unpack=True)



# Graficas
plt.figure()
plt.plot(q1,p1,'.-')

plt.title("q1 p1")
plt.grid()

plt.xlabel('q1')
plt.ylabel('p1')
plt.savefig('q1_p1.png')


plt.figure()
plt.plot(q2,p2,'.-')
plt.title("q2 p2")

plt.grid()
plt.xlabel('q2')
plt.ylabel('p2')
plt.savefig('q2_p2.png')


q2,p2 = np.genfromtxt("q2_p2.txt", unpack=True)
plt.figure()
plt.plot(q2,p2,'.-')

plt.xlabel('q2')
plt.ylabel('p2')
plt.title("q2 p2")
plt.grid()
plt.savefig('caos.pdf')
