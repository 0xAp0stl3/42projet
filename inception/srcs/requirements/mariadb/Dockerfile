FROM	debian:bullseye

RUN	apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install mariadb-server -y

COPY	conf/my.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY	tools/run.sh /run.sh

EXPOSE 	3306

ENTRYPOINT ["bash", "run.sh"]
