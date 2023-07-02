FROM debian:bullseye-slim
ENV DEBIAN_FRONTEND=noninteractive

ARG CONTAINER_USER=esp
ARG CONTAINER_GROUP=esp
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd -r ${CONTAINER_GROUP} \
  && useradd -r -g ${CONTAINER_GROUP} -m ${CONTAINER_USER} \
  && groupmod --gid ${USER_GID} ${CONTAINER_GROUP} \
  && usermod --uid ${USER_UID} --gid ${USER_GID} ${CONTAINER_USER} \
  && chown -R ${CONTAINER_GROUP}:${CONTAINER_USER} /home/${CONTAINER_USER}

RUN apt-get update \
    && apt-get install -y git curl wget flex bison gcc
  # && apt-get clean -y && rm -rf /var/lib/apt/lists/* /tmp/library-scripts

USER ${CONTAINER_USER}
ENV USER=${CONTAINER_USER}
WORKDIR /home/${CONTAINER_USER}