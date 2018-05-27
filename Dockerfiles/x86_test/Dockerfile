FROM kevinwmatthews/docker-cpputest:v3.8-bugfix-latest

ARG user=builder
RUN useradd --create-home $user
USER $user

WORKDIR /home/$user
#TODO checkout a tag before building
RUN git clone https://github.com/KevinWMatthews/c-led_controller.git \
    && mkdir c-led_controller_build \
    && cd c-led_controller_build \
    && cmake ../c-led_controller -DCOMPILE_TESTS=ON

WORKDIR /home/$user/c-led_controller_build
CMD make && make test
