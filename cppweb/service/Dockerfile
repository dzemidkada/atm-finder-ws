# Build
FROM gcc_base:latest as build

ADD ./src /usr/cppweb/src

WORKDIR /usr/cppweb/build
RUN cmake ../src && \
    cmake --build .

ENTRYPOINT ["/usr/cppweb/build/atm_service"]
