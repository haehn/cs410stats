FROM continuumio/miniconda3

MAINTAINER CS410.net version: 0.1


RUN apt-get update
RUN apt-get install -y g++

RUN conda create --name CS410 python=3.9

SHELL ["conda", "run", "-n", "CS410", "/bin/bash", "-c"]

RUN conda install numpy
RUN conda install cython
RUN conda install pytest

RUN git clone https://github.com/haehn/cs410stats.git


ADD setup.py setup.py
ADD statistics.cpp statistics.cpp
ADD statistics.pyx statistics.pyx
ADD stats.cc stats.cc

ADD test_stats.py test_stats.py

RUN python setup.py build_ext --inplace


ENTRYPOINT ["conda", "run", "--no-capture-output", "-n", "CS410", "python", "test_stats.py"]
