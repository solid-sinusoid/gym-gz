ARG from=andreaostuni/gym-gz:base
FROM ${from}

RUN pip3 install vcstool colcon-common-extensions &&\
    rm -r $HOME/.cache/pip

ARG CMAKE_BUILD_TYPE="Release"
ARG gazebo_codename="garden"
ARG GAZEBO_DEFAULT_CHANNEL="stable"

RUN echo "deb http://packages.osrfoundation.org/gazebo/ubuntu-${GAZEBO_DEFAULT_CHANNEL} `lsb_release -cs` main" > \
        /etc/apt/sources.list.d/gazebo-${GAZEBO_DEFAULT_CHANNEL}.list &&\
    wget http://packages.osrfoundation.org/gazebo.key -O - | apt-key add - &&\
    apt-get update &&\
    mkdir -p /workspace/src &&\
    cd /workspace/src &&\
    wget https://raw.githubusercontent.com/gazebo-tooling/gazebodistro/master/collection-${gazebo_codename}.yaml &&\
    vcs import < collection-${gazebo_codename}.yaml &&\
    apt -y install --no-install-recommends \
        $(sort -u $(find . -iname 'packages-'$(lsb_release -cs)'.apt' -o -iname 'packages.apt') | grep -v -E "dart|^libgz|^libsdformat" | tr '\n' ' ') &&\
    rm -rf /var/lib/apt/lists/* &&\
    cd /workspace &&\
    colcon graph &&\
    colcon build \
        --cmake-args \
            -GNinja \
            -DBUILD_TESTING:BOOL=OFF \
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} \
        --merge-install \
        &&\
    find build/ -type f -not -name 'CMakeCache.txt' -delete &&\
    echo "source /workspace/install/setup.bash" >> /etc/bash.bashrc

# Source /etc/bash.bashrc before each command
SHELL ["/bin/bash", "-i", "-c"]

COPY entrypoint.sh /entrypoint.sh
COPY setup_virtualenv.sh /setup_virtualenv.sh
RUN chmod 755 /entrypoint.sh
RUN chmod 755 /setup_virtualenv.sh
ENTRYPOINT ["/entrypoint.sh"]
CMD ["bash"]
