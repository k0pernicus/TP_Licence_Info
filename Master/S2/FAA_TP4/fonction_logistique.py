import numpy as np
import math
import matplotlib.pyplot as pl
from descente_gradient import descente_gradient

def f_theta(theta, txp):
    return np.dot(theta.T, txp)

if __name__ == '__main__':

        femme = np.loadtxt("x.txt")
        homme = np.loadtxt("y.txt")

        f_h = np.concatenate((femme,homme), axis=0)
        print(f_h)


        a = 1
        b = f_h.mean(0)

        print("A = " + str(a))
        print("\nB = " + str(b))

        b = b[0] * (- 1)
        print("\n\nA = " + str(a))
        print("\nB = " + str(b))
        
        sig = 1 / (1    + np.exp((np.dot((-1),(np.dot(a,f_h) + b)))))
        
        print("\n\n SIG" + str(sig))

        pl.figure(1)
        #pl.axis([-10,10,-0.1,1.1])
        #pl.axis([30,200,-0.1,1.1])
        pl.plot(f_h[:,0],sig[:,0], '*')
        #pl.plot(f_h,sig, '^')
        pl.grid(True)
        print("bitch")

        x = np.vstack((sig[:,0],np.ones(len(sig))))
        print("x shape : " + str(np.shape(x)))
        print("x : " + str(x))
       # batch = descente_gradient(x, sig[:,1], len(sig))
       # batch.calculer()

       # pl.figure(2)
       # pl.plot(sig[0,:], f_theta(batch.tab_points[-1], sig), '.', label = "Batch")
       # print(f_theta(batch.tab_points[-1], sig))
        pl.show()



