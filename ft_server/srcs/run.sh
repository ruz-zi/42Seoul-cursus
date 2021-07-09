#!/bin/bash

chmod 775 /run.sh
chown -R www-data:www-data /var/www/
chmod -R 755 /var/www/

openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=dju/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
chmod 600 localhost.dev*
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/

cp -rp ./srcs/default /etc/nginx/sites-available/

wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
rm latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
cp -rp ./srcs/wp-config.php /var/www/html/wordpress/

service mysql start
echo "create database wordpress;" | mysql -u root --skip-password
echo "grant all privileges on wordpress.* to 'dju'@'localhost' identified by '1234' with grant option;" | mysql -u root --skip-password
echo "use wordpress;" | mysql -u root --skip-password

wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.2-all-languages.tar.gz
rm phpMyAdmin-5.0.2-all-languages.tar.gz
mv phpMyAdmin-5.0.2-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
cp -rp ./srcs/config.inc.php /var/www/html/phpmyadmin/

service nginx start
service php7.3-fpm start
service mysql restart
