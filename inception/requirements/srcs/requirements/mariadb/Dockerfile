FROM alpine:3.21

RUN apk update && apk add --no-cache \
    mariadb mariadb-client \
 && rm -rf /var/cache/apk/*

RUN mkdir -p /run/mariadbd /var/lib/mysql /var/log/mysql \
 && chown -R mysql:mysql /run/mariadbd /var/lib/mysql /var/log/mysql

COPY tools/init.sh /init.sh
RUN chmod +x /init.sh

EXPOSE 3306
ENTRYPOINT ["/init.sh"]