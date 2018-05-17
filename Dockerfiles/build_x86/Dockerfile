FROM cpputest-3.8.1

WORKDIR /root
#TODO should clone from a tag
RUN git clone https://github.com/KevinWMatthews/c-led_controller.git \
    && mkdir c-led_controller_build \
    && cd c-led_controller_build \
    && cmake ../c-led_controller -DCOMPILE_TESTS=ON \
