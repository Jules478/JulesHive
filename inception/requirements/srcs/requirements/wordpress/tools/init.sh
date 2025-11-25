#!/bin/sh

# Read secrets from Docker secrets files
if [ ! -f "$WORDPRESS_DB_PASSWORD_FILE" ]; then echo "❌ DB password file missing"; exit 1; fi
WORDPRESS_DB_PASSWORD=$(cat "$WORDPRESS_DB_PASSWORD_FILE")

if [ ! -f "$WP_ADMIN_PASSWORD_FILE" ]; then echo "❌ Admin password file missing"; exit 1; fi
WP_ADMIN_PASSWORD=$(cat "$WP_ADMIN_PASSWORD_FILE")

# Optional: second user
if [ -n "${WP_SECOND_PASSWORD_FILE:-}" ] && [ -f "$WP_SECOND_PASSWORD_FILE" ]; then
  WP_SECOND_PASSWORD=$(cat "$WP_SECOND_PASSWORD_FILE")
fi

# Create wp-config.php using WP-CLI
if [ ! -f wp-config.php ]; then
  wp config create \
    --path=/var/www/wp \
    --dbname="$WORDPRESS_DB_NAME" \
    --dbuser="$WORDPRESS_DB_USER" \
    --dbpass="$WORDPRESS_DB_PASSWORD" \
    --dbhost="$WORDPRESS_DB_HOST" \
    --dbprefix="wp_" \
    --allow-root
fi

# Install WordPress if not installed
if ! wp core is-installed --path=/var/www/wp --allow-root; then
  wp core install \
    --path=/var/www/wp \
    --url="https://${DOMAIN_NAME}" \
    --title="${WP_SITE_TITLE}" \
    --admin_user="${WP_ADMIN_USER}" \
    --admin_password="${WP_ADMIN_PASSWORD}" \
    --admin_email="${WP_ADMIN_EMAIL}" \
    --skip-email \
    --allow-root
  if [ -n "${WP_SECOND_USER:-}" ] && [ -n "${WP_SECOND_EMAIL:-}" ] && [ -n "${WP_SECOND_PASSWORD:-}" ]; then
    wp user create "${WP_SECOND_USER}" "${WP_SECOND_EMAIL}" \
      --path=/var/www/wp \
      --user_pass="${WP_SECOND_PASSWORD}" \
      --role="${WP_SECOND_ROLE:-author}" \
      --allow-root
  fi
fi

chown -R www-data:www-data /var/www/wp

exec "$@"