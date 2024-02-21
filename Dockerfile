FROM debian:latest

WORKDIR ~/

COPY .vimrc /root/.vimrc

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    git \
    ripgrep \
    build-essential \
    vim \
    ssh \
    valgrind
    linux-perf 

RUN echo "alias gs='git status'" >> /root/.bashrc && \
    echo "alias gp='git pull'" >> /root/.bashrc && \
    echo "alias ll='ls -l'" >> /root/.bashrc && \
    echo "alias hi='apt update && apt upgrade -y'" >> /root/.bashrc

CMD ["/bin/bash"]
