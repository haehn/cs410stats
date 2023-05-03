
import timeit


def test_cython():

  code = '''import statistics

import numpy as np

somevalues = [100]*100000

s = statistics.PyStats()

s.get_mean( somevalues )
  '''

  print('Cython Mean', timeit.timeit(code, number=100))


def test_numpy():
  code = '''
import numpy as np

somevalues = np.array([100]*100000)

np.mean( somevalues )
  '''

  print('Numpy Mean', timeit.timeit(code, number=100))


def test_python():
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



