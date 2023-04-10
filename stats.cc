#include <iostream>
#include <vector>

#include <cassert>
#include <cmath>

template <typename T>
class Stats {
    
    public:
        T get_min(std::vector<T> v);
        T get_max(std::vector<T> v);
        float get_mean(std::vector<T> v);
        float get_stddev(std::vector<T> v);
        
};

template <typename T>
T Stats<T>::get_min(std::vector<T> v) {
    
    T minvalue = v[0];
    
    for(int i=1; i<v.size(); i++) {
        
        minvalue = std::min(minvalue, v[i]);
        
    }
    
    return minvalue;
}

template <typename T>
T Stats<T>::get_max(std::vector<T> v) {
    
    T minvalue = v[0];
    
    for(int i=1; i<v.size(); i++) {
        
        minvalue = std::max(minvalue, v[i]);
        
    }
    
    return minvalue;
}

template <typename T>
float Stats<T>::get_mean(std::vector<T> v) {
    
    float sum = v[0];
    
    for(int i=1; i<v.size(); i++) {
        
        sum += v[i];
        
    }
    
    sum /= v.size();
    
    return sum;
}

template <typename T>
float Stats<T>::get_stddev(std::vector<T> v) {

    float stddev = 0;

    float mean = Stats<T>::get_mean(v);

    for(int i=1; i<v.size(); i++) {
        
        stddev += std::pow(v[i] - mean, 2);
        
    }

    return std::sqrt(stddev / v.size());

}

void test_get_min() {

  std::vector<float> somevalues;

  somevalues.push_back(1.3);
  somevalues.push_back(2);
  somevalues.push_back(3);
  somevalues.push_back(-241);

  Stats<float> stats;
  
  assert(stats.get_min(somevalues)==-241);
  std::cout << "Test OK!" << std::endl;
    
}

void test_get_max() {

  std::vector<float> somevalues;

  somevalues.push_back(1.3);
  somevalues.push_back(2);
  somevalues.push_back(3);
  somevalues.push_back(-241);

  Stats<float> stats;
  
  assert(stats.get_max(somevalues)==3);
  std::cout << "Test OK!" << std::endl;
    
}

void test_get_mean() {

  std::vector<float> somevalues;

  somevalues.push_back(1.3);
  somevalues.push_back(2);
  somevalues.push_back(3);
  somevalues.push_back(-241);

  Stats<float> stats;

  float diff = std::abs(stats.get_mean(somevalues)) - std::abs(-58.675);

  assert(diff < 0.0005);

  std::cout << "Test OK!" << std::endl;
    
}

void test_get_stddev() {

  std::vector<float> somevalues;

  somevalues.push_back(1.3);
  somevalues.push_back(2);
  somevalues.push_back(3);
  somevalues.push_back(-241);

  Stats<float> stats;

  float diff = std::abs(stats.get_stddev(somevalues)) - std::abs(105.26712152899404);

  assert(diff < 0.0005);

  std::cout << "Test OK!" << std::endl;

}

int main()
{
    
  test_get_min();
  test_get_max();
  test_get_mean();
  test_get_stddev();
  
}
