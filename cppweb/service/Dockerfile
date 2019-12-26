FROM gcc_base:latest

ADD ./src /usr/cppweb/src

WORKDIR /usr/cppweb/build
RUN cmake ../src && \
    cmake --build .

ENTRYPOINT ["/usr/cppweb/build/atm_service"]
