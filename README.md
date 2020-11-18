# Infor
```

Drupal 9
Composer 2+
php 7.3
['boostrap_storybook'](https://www.drupal.org/project/bootstrap_storybook)

```

# Usage

```
# Start lando drupal site
lando start

# Install dependencies
lando composer install
 or 
composer install (local composer, please ensure local composer version = lando composer version)

# Enable sub theme
lando theme:enable mysub

# Install node packages under custom theme
lando npm install -prefix web/themes/custom/mysub/

# Run browsersync
lando npm watch -prefix web/themes/custom/mysub/

# Run browsersync and storybook
lando npm crazy -prefix web/themes/custom/mysub/
```

# Lando Usage examples

```
# Doing a drush site install
lando drush si --db-url=mysql://drupal9:drupal9@database/drupal9 -y

drupal9@database/drupal9 -y

# Run composer tests
lando composer test

# Drop into a mysql shell
lando mysql

# Check hte app's installed php extensions
lando php -m
```