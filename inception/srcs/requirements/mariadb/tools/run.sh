#!/bin/bash

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

if [ ! -d "/var/lib/mysql/mysql" ]; then
	echo "Initialisation"
	mariadb-install-db --user=mysql --ldata=/var/lib/mysql
fi

exec mysqld --user=mysql --console &

sleep 5


echo "Config database"
mysql -uroot -p"${SQL_ROOT_PASSWORD}" -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
mysql -uroot -p"${SQL_ROOT_PASSWORD}" -e "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql -uroot -p"${SQL_ROOT_PASSWORD}" -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';"
mysql -uroot -p"${SQL_ROOT_PASSWORD}" -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
mysql -uroot -p"${SQL_ROOT_PASSWORD}" -e "FLUSH PRIVILEGES;"

mysqladmin -uroot -p"${SQL_ROOT_PASSWORD}" shutdown

exec mysqld_safe --user=mysql
