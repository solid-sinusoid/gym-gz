ARG from=andreaostuni/gym-gz:pypi-master
FROM ${from}

# Install the PyPI package in a virtualenv
ARG pip_options=""
RUN virtualenv -p $(which python3) ${VIRTUAL_ENV} &&\
    python -m pip install --upgrade pip &&\
    # pip install ${pip_options} gym-gz &&\
    rm -r $HOME/.cache/pip



# Clone the repository
WORKDIR /github
ARG branch="devel"

# idyntree
RUN wget https://github.com/robotology/idyntree/archive/refs/tags/v12.0.0.tar.gz
RUN tar -xf v12.0.0.tar.gz && cd idyntree-12.0.0 && mkdir build && cd build && \
    cmake .. && make install


# gym-gz-models
RUN git clone -b master https://github.com/andreaostuni/gym-gz-models.git
RUN cd /github/gym-gz-models && pip install .

# gym-gz
RUN git clone -b ${branch} https://github.com/andreaostuni/gym-gz
RUN cd /github/gym-gz/scenario && pip install -e .
RUN cd /github/gym-gz && mkdir build && cd build && cmake .. && make install
RUN cd /github/gym-gz && pip install -e .



# Reset the entrypoint
ENTRYPOINT [""]

CMD ["bash"]
