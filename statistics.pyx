# distutils: language = c++
from libcpp.vector cimport vector

#
# Connection to C++
#
cdef extern from "stats.cc":

  cdef cppclass Stats[T]:
    T get_min(vector[T])
    T get_max(vector[T])
    float get_mean(vector[T])
    float get_stddev(vector[T])


#
# Python Interface
#
cdef class PyStats:

  cdef Stats[float] stats

  def get_min(self, vector[float] v):
    return self.stats.get_min(v)

  def get_max(self, vector[float] v):
    return self.stats.get_max(v)

  def get_mean(self, vector[float] v):
    return self.stats.get_mean(v)

  def get_stddev(self, vector[float] v):
    return self.stats.get_stddev(v)
