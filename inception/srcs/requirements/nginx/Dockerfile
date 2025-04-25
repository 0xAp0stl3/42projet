FROM	debian:bullseye

RUN	apt-get update &&\
	apt-get install nginx openssl vim curl -y

RUN	mkdir -p /etc/nginx/ssl
RUN	mkdir -p /var/run/nginx

RUN	openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=Occitanue/L=Perpignan/O=42/OU=42/CN=mrocher.42.fr/UID=mrocher"

COPY	/conf/nginx.conf /etc/nginx/nginx.conf

RUN	chmod 755 /var/www/html
RUN	chown -R www-data:www-data /var/www/html

CMD	["nginx", "-g", "daemon off;"]
