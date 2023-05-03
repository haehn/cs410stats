
import timeit

code = '''import statistics

import numpy as np

somevalues = [100]*100000

s = statistics.PyStats()

s.get_min( somevalues )
'''

print('Cython Mean', timeit.timeit(code, number=100))



code = '''import statistics

import numpy as np

somevalues = [100]*100000

s = statistics.PyStats()

np.mean( somevalues )
'''

print('Numpy Mean', timeit.timeit(code, number=100))



code = '''import statistics

import numpy as np

somevalues = [100]*100000

s = statistics.PyStats()

mean = 0
for v in somevalues:
  mean+=v
mean /= len(somevalues)
'''

print('Python Mean', timeit.timeit(code, number=100))



