#!/bin/sh
set -eu

SSL_CERT_SRC="${SSL_CERT_SRC:-/run/secrets/ssl_cert}"
SSL_KEY_SRC="${SSL_KEY_SRC:-/run/secrets/ssl_key}"
SSL_CERT_DST="/etc/nginx/ssl/tls.crt"
SSL_KEY_DST="/etc/nginx/ssl/tls.key"
DOMAIN="${DOMAIN_NAME:-localhost}"

if [ -f "$SSL_CERT_SRC" ] && [ -f "$SSL_KEY_SRC" ]; then
  cp "$SSL_CERT_SRC" "$SSL_CERT_DST" && cp "$SSL_KEY_SRC" "$SSL_KEY_DST"
  chmod 600 "$SSL_KEY_DST"
else
  if [ ! -f "$SSL_CERT_DST" ] || [ ! -f "$SSL_KEY_DST" ]; then
    openssl req -x509 -nodes -days 365 \
      -newkey rsa:2048 \
      -keyout "$SSL_KEY_DST" \
      -out   "$SSL_CERT_DST" \
      -subj "/CN=${DOMAIN}"
    chmod 600 "$SSL_KEY_DST"
  fi
fi

mkdir -p /var/www/wp
exec nginx -g 'daemon off;'