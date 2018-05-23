FROM cpputest-3.8.1

RUN useradd --create-home build
USER build

WORKDIR /home/build
#TODO should build from a tag
RUN git clone https://github.com/KevinWMatthews/c-led_controller.git \
    && mkdir c-led_controller_build \
    && cd c-led_controller_build \
    && cmake ../c-led_controller -DCOMPILE_TESTS=ON

WORKDIR /home/build/c-led_controller_build
CMD make && make test
