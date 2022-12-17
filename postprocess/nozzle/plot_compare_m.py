#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec 16 19:01:08 2022

@author: yan
"""

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Dec 12 13:35:29 2022

@author: yan

"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.ticker import FormatStrFormatter


cp_euler = pd.read_csv("coolprop_euler.csv", ",", skiprows=0)
cp_rans = pd.read_csv("coolprop_rans.csv", ",", skiprows=0)
ex = pd.read_csv("ex_m.csv", "  ", skiprows=0)



# plot (M,Z)
fig1 = plt.figure( dpi=300)
axes = fig1.add_axes([0.15, 0.15, 0.7, 0.7]) #size of figure
axes.plot(cp_euler.iloc[:,4]*1000 , cp_euler.iloc[:,0], 'k', lw=2, label="CoolProp Euler")
axes.plot(cp_rans.iloc[:,4]*1000 , cp_rans.iloc[:,0], 'r', lw=2, label="CoolProp RANS")
plt.errorbar(ex.iloc[:,0]*1000 , ex.iloc[:,1], ex.iloc[:,2], fmt="ko", ms=2, mew=0.1, label='Experiment')

axes.set_xlabel('$X[mm]$',fontsize=12)
#axes.set_yscale("log")
axes.set_ylabel('$Mach$',fontsize=12) 

axes.set_title('Mach number along centerline',fontsize=14)

axes.legend(loc=2) # 

axes.set_xlim(0,120)
# axes.set_ylim(0.2,1)
#axes.legend(loc=2) # 2 means left top
fig1.savefig("nozzle_m.pdf")

