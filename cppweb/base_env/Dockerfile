# Build
FROM gcc:latest

RUN apt-get -qq update
RUN apt-get -qq upgrade
RUN apt-get -qq install -y cmake

RUN apt-get -qq install -y libboost-chrono-dev libboost-date-time-dev \
    libboost-program-options-dev \
    libboost-regex-dev \
    libboost-system-dev \
    libboost-thread-dev \
    libboost-filesystem-dev
RUN apt-get -qq install -y build-essential libtcmalloc-minimal4 && \
    ln -s /usr/lib/libtcmalloc-minimal.so.4 /usr/lib/libtcmalloc-minimal.so
