#!/bin/bash

set -e 

sleep 10

if [ ! -f /var/www/wordpress/index.php ]; then
  echo "Volume WordPress vide."
  wp core download --locale=fr_FR --path=/var/www/wordpress --allow-root
  chown -R www-data:www-data /var/www/wordpress
fi

#Vérifier si WordPress est installé en testant la présence des tables dans la base
if ! wp core is-installed --allow-root --path='/var/www/wordpress' > /dev/null 2>&1; then
	echo "WordPress n'est pas installé, lancement de l'installation."
	wp core install --allow-root \
		--url="${DOMAIN_NAME}" \
		--title="${SITE_TITLE}" \
		--admin_user="${WP_ADMIN}" \
		--admin_password="${WP_ADMIN_PASSWORD}" \
		--admin_email="${WP_EMAIL}" \
		--path='/var/www/wordpress'
			
	wp user create --allow-root \
		--role=author \
		$USER_LOGIN $USER_EMAIL --user_pass=$USER_PASSWORD \
		--path='/var/www/wordpress'

else
    echo "WordPress est déjà installé."
fi

if [ ! -d /run/php ]; then
	mkdir -p /run/php
fi

/usr/sbin/php-fpm7.4 -F
