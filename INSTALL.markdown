Jarifa
======

Requirements 
------------

The following requirements are needed in order to install OrgGrid:

 * GNU/Linux (tested and developed in Debian Stable.
 * Apache 2.0 or greater (SSL support it is recommended).
 * PHP 5.0 or greater.
 * PHP-GETTEXT.
 * PHP-CURL for Identi.ca support.
 * PHP 5.0 for MySQL.
 * MySQL. 

Installation process
--------------------

The installation process of Jarifa is the following:

 * Download the source code.
 * Unzip it in /var/www or the document root of your Apache configuration file.
 * Set up the data base for Jarifa using the file located in /var/www/jarifa/conf/jarifa.sql.
 * Create the root account using the MySQL interface (it is easier if you are using phpmyadmin).
 * Give Apache user read, write and access permissions to the Jarifa folder.
 * Access Jarifa with your web browser in: http://SERVER/jarifa 

Check the [wiki](https://github.com/teleyinex/jarifa/wiki) for further details.
