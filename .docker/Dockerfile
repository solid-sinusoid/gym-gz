ARG from=andreaostuni/gym-gz:pypi-master
FROM ${from}

# Install the PyPI package in a virtualenv
ARG pip_options=""
RUN virtualenv -p $(which python3) ${VIRTUAL_ENV} &&\
    python -m pip install --upgrade pip &&\
    pip install ${pip_options} gym-gz &&\
    rm -r $HOME/.cache/pip

# Clone the repository
WORKDIR /github
ARG branch="master"
RUN git clone -b ${branch} https://github.com/andreaostuni/gym-gz /github

# Reset the entrypoint
ENTRYPOINT [""]

CMD ["bash"]
