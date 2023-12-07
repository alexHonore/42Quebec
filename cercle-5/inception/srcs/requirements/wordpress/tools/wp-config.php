<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the installation.
 * You don't have to use the web site, you can copy this file to "wp-config.php"
 * and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * Database settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// ** Database settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** Database username */
define( 'DB_USER', 'test' );

/** Database password */
define( 'DB_PASSWORD', '12345' );

/** Database hostname */
define( 'DB_HOST', 'mariadb' );

/** Database charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The database collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication unique keys and salts.
 *
 * Change these to different unique phrases! You can generate these using
 * the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}.
 *
 * You can change these at any point in time to invalidate all existing cookies.
 * This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
	define('AUTH_KEY',         'BusuNJm.$V`}=#cxgY,W&CiQKVUNg(G^}@},obO0RoI1V*KjLNK69`U[rUgdW`2^');
	define('SECURE_AUTH_KEY',  '{dZU%iP#KTA?QaA!v>.-XOb/~9|[}d.X~=i$<aDfV|Pd(;i6&.yq9xR_OgYi:^f)');
	define('LOGGED_IN_KEY',    'U[.M6uaGosH*6F-d-r/|iiIoT#$b%1?=>}+_%XPd_b{3JM,!7O6|d-!uABh:?M&X');
	define('NONCE_KEY',        'lVZy?|SCa:~(oLy?*S&+h@zi8.5J^:rR*O<6>O.C.?jCO]^lFd*151mTRg eU][J');
	define('AUTH_SALT',        'eY2|?}.dyC>T<:K)_Zcydu#RnAf#[) uo~bjs7a`wK,$B[hPIA+Blh,F)Z/5S2^+');
	define('SECURE_AUTH_SALT', 'dS~->ZGPcbFYsfm/-IuFHLsM.zzgS2uDBlx_vO,i-9r?]@idp)A/^RnEG-nOM465');
	define('LOGGED_IN_SALT',   '5Wj@|TZ/7Y1y(it|TFK?hnTM?>MfF`L+~+VP69P]Q0j+`$ehF+1HOcwE|Y2$~hNV');
	define('NONCE_SALT',       'u_V`khr@O@FB7.5o_%r0^-Be+e<S!K|J5nU1m2;|Q$;u [Ozr5$$Bq[lm[`|3KE`');
/**#@-*/

/**
 * WordPress database table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* Add any custom values between this line and the "stop editing" line. */


/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', '/var/www/html/wordpress' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
