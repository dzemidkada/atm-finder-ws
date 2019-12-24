FROM gcc:9.2

# Install dependencies

RUN apt-get clean
RUN apt-get -qq update
RUN apt-get -qq upgrade
RUN apt-get -qq install cmake

RUN apt-get -qq install libboost-all-dev=1.62.0.1
RUN apt-get -qq install build-essential libtcmalloc-minimal7 && \
    ln -s /usr/lib/libtcmalloc-minimal.so.4 /usr/lib/libtcmalloc-minimal.so

# Copy files

RUN mkdir /usr/src/cppweb
COPY . /usr/src/cppweb

# Build service

WORKDIR /usr/src/cppweb
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make
