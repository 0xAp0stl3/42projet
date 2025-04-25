FROM	debian:bullseye

RUN	apt-get update -y && \
	apt-get install wget \
	curl \
	php7.4 \
	php7.4-fpm \
	php7.4-mysql \
	mariadb-client -y

RUN	wget https://fr.wordpress.org/wordpress-6.7.2-fr_FR.tar.gz -P /var/www && \
	tar -xzf /var/www/wordpress-6.7.2-fr_FR.tar.gz -C /var/www && \
	rm /var/www/wordpress-6.7.2-fr_FR.tar.gz

RUN	chown -R www-data:www-data /var/www/wordpress

COPY	/conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar

RUN	chmod +x wp-cli.phar
RUN	mv wp-cli.phar /usr/local/bin/wp

COPY	/conf/wp-config.php /var/www/wordpress/wp-config.php
COPY	/tools/run.sh	/run.sh

EXPOSE	9000

ENTRYPOINT ["bash", "run.sh"]
