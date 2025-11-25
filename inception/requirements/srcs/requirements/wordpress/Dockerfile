FROM alpine:3.21

RUN apk update && apk add --no-cache \
    php83 \
    php83-fpm \
    php83-mysqli \
    php83-mbstring \
    php83-dom \
    php83-gd \
    php83-zip \
    php83-curl \
    php83-phar \
    curl \
    tar \
    mariadb-client \
 && rm -rf /var/cache/apk/*

WORKDIR /var/www/wp

RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    mv wordpress/* . && \
    rm -rf wordpress latest.tar.gz

# Install WP-CLI
RUN curl -fsSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp \
 && chmod +x /usr/local/bin/wp

# PHP-FPM pool config
COPY conf/www.conf /etc/php83/php-fpm.d/www.conf

# Create a non-root user 'www-data' to run the web server
# -D: Do not create a home directory
# -H: Do not create a home directory
# -s /sbin/nologin: Set the shell to nologin for security
# -g www-data: Set the primary group to www-data
# -G www-data: Add to the www-data group
RUN adduser -D -H -s /sbin/nologin -g www-data -G www-data www-data

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

EXPOSE 9000
ENTRYPOINT ["/init.sh"]
CMD ["php-fpm83", "-F"]